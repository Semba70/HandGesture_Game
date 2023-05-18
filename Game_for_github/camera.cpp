// Copyright (C) 2017 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include "camera.h"
#if defined(Q_OS_ANDROID) || defined(Q_OS_IOS)
#    include "ui_camera_mobile.h"
#else
#    include "ui_camera.h"
#endif


#include "imagesettings.h"
#include "metadatadialog.h"
#include "videosettings.h"

#include <QAudioDevice>
#include <QAudioInput>
#include <QCameraDevice>
#include <QMediaDevices>
#include <QMediaFormat>
#include <QMediaMetaData>
#include <QMediaRecorder>


#include <QLineEdit>
#include <QMessageBox>

#include <QAction>
#include <QActionGroup>
#include <QImage>
#include <QKeyEvent>
#include <QPalette>

#include <QDir>
#include <QTimer>

#include <QRandomGenerator>

#if QT_CONFIG(permissions)
  #include <QPermission>
#endif

torch::jit::script::Module module = torch::jit::load("Hand_Model.pt");
torch::Device device(torch::kCPU);

Camera::Camera() : ui(new Ui::Camera)
{
    ui->setupUi(this);

    // disable all buttons by default
    updateCameraActive(false);
    readyForCapture(false);
    ui->recordButton->setEnabled(false);
    ui->pauseButton->setEnabled(false);
    ui->stopButton->setEnabled(false);
    ui->metaDataButton->setEnabled(false);


    scene_how = new QGraphicsScene;
    pix = new QGraphicsPixmapItem(QPixmap::fromImage(QImage("images\\introduction_3.jpg")));
    scene_how->addItem(pix);
    ui->howto_graphicsView->setScene(scene_how);


    scene_janken = new QGraphicsScene;
    //AI_set();

    

    // try to actually initialize camera & mic
    init();


    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(CountDown()));
    connect(timer, SIGNAL(timeout()), this, SLOT(RePlay()));
}

void Camera::init()
{
#if QT_CONFIG(permissions)
    // camera
    QCameraPermission cameraPermission;
    switch (qApp->checkPermission(cameraPermission)) {
    case Qt::PermissionStatus::Undetermined:
        qApp->requestPermission(cameraPermission, this, &Camera::init);
        return;
    case Qt::PermissionStatus::Denied:
        qWarning("Camera permission is not granted!");
        return;
    case Qt::PermissionStatus::Granted:
        break;
    }
    // microphone
    QMicrophonePermission microphonePermission;
    switch (qApp->checkPermission(microphonePermission)) {
    case Qt::PermissionStatus::Undetermined:
        qApp->requestPermission(microphonePermission, this, &Camera::init);
        return;
    case Qt::PermissionStatus::Denied:
        qWarning("Microphone permission is not granted!");
        return;
    case Qt::PermissionStatus::Granted:
        break;
    }
#endif

    m_audioInput.reset(new QAudioInput);
    m_captureSession.setAudioInput(m_audioInput.get());

    // Camera devices:

    videoDevicesGroup = new QActionGroup(this);
    videoDevicesGroup->setExclusive(true);
    updateCameras();
    connect(&m_devices, &QMediaDevices::videoInputsChanged, this, &Camera::updateCameras);

    connect(videoDevicesGroup, &QActionGroup::triggered, this, &Camera::updateCameraDevice);
    connect(ui->captureWidget, &QTabWidget::currentChanged, this, &Camera::updateCaptureMode);

    connect(ui->metaDataButton, &QPushButton::clicked, this, &Camera::showMetaDataDialog);
    connect(ui->exposureCompensation, &QAbstractSlider::valueChanged, this,
            &Camera::setExposureCompensation);

    setCamera(QMediaDevices::defaultVideoInput());
}

void Camera::setCamera(const QCameraDevice &cameraDevice)
{
    m_camera.reset(new QCamera(cameraDevice));
    m_captureSession.setCamera(m_camera.data());

    connect(m_camera.data(), &QCamera::activeChanged, this, &Camera::updateCameraActive);
    connect(m_camera.data(), &QCamera::errorOccurred, this, &Camera::displayCameraError);

    if (!m_mediaRecorder) {
        m_mediaRecorder.reset(new QMediaRecorder);
        m_captureSession.setRecorder(m_mediaRecorder.data());
        connect(m_mediaRecorder.data(), &QMediaRecorder::recorderStateChanged, this,
                &Camera::updateRecorderState);
        connect(m_mediaRecorder.data(), &QMediaRecorder::durationChanged, this,
                &Camera::updateRecordTime);
        connect(m_mediaRecorder.data(), &QMediaRecorder::errorChanged, this,
                &Camera::displayRecorderError);
    }

    if (!m_imageCapture) {
        m_imageCapture.reset(new QImageCapture);
        m_captureSession.setImageCapture(m_imageCapture.get());
        connect(m_imageCapture.get(), &QImageCapture::readyForCaptureChanged, this,
                &Camera::readyForCapture);
        connect(m_imageCapture.get(), &QImageCapture::imageCaptured, this,
                &Camera::processCapturedImage);
        connect(m_imageCapture.get(), &QImageCapture::imageSaved, this, &Camera::imageSaved);
        connect(m_imageCapture.get(), &QImageCapture::errorOccurred, this,
                &Camera::displayCaptureError);
    }

    m_captureSession.setVideoOutput(ui->viewfinder);

    updateCameraActive(m_camera->isActive());
    updateRecorderState(m_mediaRecorder->recorderState());
    readyForCapture(m_imageCapture->isReadyForCapture());

    updateCaptureMode();

    m_camera->start();
}

void Camera::keyPressEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat())
        return;

    switch (event->key()) {
    case Qt::Key_CameraFocus:
        displayViewfinder();
        event->accept();
        break;
    case Qt::Key_Camera:
        if (m_doImageCapture) {
            takeImage();
        } else {
            if (m_mediaRecorder->recorderState() == QMediaRecorder::RecordingState)
                stop();
            else
                record();
        }
        event->accept();
        break;
    default:
        QMainWindow::keyPressEvent(event);
    }
}

void Camera::updateRecordTime()
{
    QString str = tr("Recorded %1 sec").arg(m_mediaRecorder->duration() / 1000);
    ui->statusbar->showMessage(str);
}

void Camera::processCapturedImage(int requestId, const QImage &img)
{
    Q_UNUSED(requestId);
    QImage scaledImage =
            img.scaled(ui->viewfinder->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

    ui->lastImagePreviewLabel->setPixmap(QPixmap::fromImage(scaledImage));

    // Display captured image for 4 seconds.
    //displayCapturedImage();
    //QTimer::singleShot(4000, this, &Camera::displayViewfinder);
}

void Camera::configureCaptureSettings()
{
    if (m_doImageCapture)
        configureImageSettings();
    else
        configureVideoSettings();
}

void Camera::configureVideoSettings()
{
    VideoSettings settingsDialog(m_mediaRecorder.data());

    if (settingsDialog.exec())
        settingsDialog.applySettings();
}

void Camera::configureImageSettings()
{
    ImageSettings settingsDialog(m_imageCapture.get());

    if (settingsDialog.exec() == QDialog::Accepted)
        settingsDialog.applyImageSettings();
}

void Camera::record()
{
    m_mediaRecorder->record();
    updateRecordTime();
}

void Camera::pause()
{
    m_mediaRecorder->pause();
}

void Camera::stop()
{
    m_mediaRecorder->stop();
}

void Camera::setMuted(bool muted)
{
    m_captureSession.audioInput()->setMuted(muted);
}

void Camera::takeImage()
{   
    const QString image_path = QDir::current().filePath("./\\hand_image\\hand_image.jpg");
    m_isCapturingImage = true;
    m_imageCapture->captureToFile(image_path);
}

void Camera::displayCaptureError(int id, const QImageCapture::Error error,
                                 const QString &errorString)
{
    Q_UNUSED(id);
    Q_UNUSED(error);
    QMessageBox::warning(this, tr("Image Capture Error"), errorString);
    m_isCapturingImage = false;
}

void Camera::startCamera()
{
    m_camera->start();
}

void Camera::stopCamera()
{
    m_camera->stop();
}

void Camera::updateCaptureMode()
{
    int tabIndex = ui->captureWidget->currentIndex();
    m_doImageCapture = (tabIndex == 0);
}

void Camera::updateCameraActive(bool active)
{
    if (active) {
        ui->actionStartCamera->setEnabled(false);
        ui->actionStopCamera->setEnabled(true);
        ui->captureWidget->setEnabled(true);
        ui->actionSettings->setEnabled(true);
    } else {
        ui->actionStartCamera->setEnabled(true);
        ui->actionStopCamera->setEnabled(false);
        ui->captureWidget->setEnabled(false);
        ui->actionSettings->setEnabled(false);
    }
}

void Camera::updateRecorderState(QMediaRecorder::RecorderState state)
{
    switch (state) {
    case QMediaRecorder::StoppedState:
        ui->recordButton->setEnabled(true);
        ui->pauseButton->setEnabled(true);
        ui->stopButton->setEnabled(false);
        ui->metaDataButton->setEnabled(true);
        break;
    case QMediaRecorder::PausedState:
        ui->recordButton->setEnabled(true);
        ui->pauseButton->setEnabled(false);
        ui->stopButton->setEnabled(true);
        ui->metaDataButton->setEnabled(false);
        break;
    case QMediaRecorder::RecordingState:
        ui->recordButton->setEnabled(false);
        ui->pauseButton->setEnabled(true);
        ui->stopButton->setEnabled(true);
        ui->metaDataButton->setEnabled(false);
        break;
    }
}

void Camera::setExposureCompensation(int index)
{
    m_camera->setExposureCompensation(index * 0.5);
}

void Camera::displayRecorderError()
{
    if (m_mediaRecorder->error() != QMediaRecorder::NoError)
        QMessageBox::warning(this, tr("Capture Error"), m_mediaRecorder->errorString());
}

void Camera::displayCameraError()
{
    if (m_camera->error() != QCamera::NoError)
        QMessageBox::warning(this, tr("Camera Error"), m_camera->errorString());
}

void Camera::updateCameraDevice(QAction *action)
{
    setCamera(qvariant_cast<QCameraDevice>(action->data()));
}

void Camera::displayViewfinder()
{
    //ui->stackedWidget->setCurrentIndex(3);
}

void Camera::displayCapturedImage()
{
    //ui->stackedWidget->setCurrentIndex(3);
}

void Camera::readyForCapture(bool ready)
{
    ui->takeImageButton->setEnabled(ready);
}

void Camera::imageSaved(int id, const QString &fileName)
{
    Q_UNUSED(id);
    ui->statusbar->showMessage(tr("Captured \"%1\"").arg(QDir::toNativeSeparators(fileName)));

    m_isCapturingImage = false;
    if (m_applicationExiting)
        close();
}

void Camera::closeEvent(QCloseEvent *event)
{
    if (m_isCapturingImage) {
        setEnabled(false);
        m_applicationExiting = true;
        event->ignore();
    } else {
        event->accept();
    }
}

void Camera::updateCameras()
{
    ui->menuDevices->clear();
    const QList<QCameraDevice> availableCameras = QMediaDevices::videoInputs();
    for (const QCameraDevice &cameraDevice : availableCameras) {
        QAction *videoDeviceAction = new QAction(cameraDevice.description(), videoDevicesGroup);
        videoDeviceAction->setCheckable(true);
        videoDeviceAction->setData(QVariant::fromValue(cameraDevice));
        if (cameraDevice == QMediaDevices::defaultVideoInput())
            videoDeviceAction->setChecked(true);

        ui->menuDevices->addAction(videoDeviceAction);
    }
}

void Camera::showMetaDataDialog()
{
    if (!m_metaDataDialog)
        m_metaDataDialog = new MetaDataDialog(this);
    m_metaDataDialog->setAttribute(Qt::WA_DeleteOnClose, false);
    if (m_metaDataDialog->exec() == QDialog::Accepted)
        saveMetaData();
}

void Camera::saveMetaData()
{
    QMediaMetaData data;
    for (int i = 0; i < QMediaMetaData::NumMetaData; i++) {
        QString val = m_metaDataDialog->m_metaDataFields[i]->text();
        if (!val.isEmpty()) {
            auto key = static_cast<QMediaMetaData::Key>(i);
            if (i == QMediaMetaData::CoverArtImage) {
                QImage coverArt(val);
                data.insert(key, coverArt);
            } else if (i == QMediaMetaData::ThumbnailImage) {
                QImage thumbnail(val);
                data.insert(key, thumbnail);
            } else if (i == QMediaMetaData::Date) {
                QDateTime date = QDateTime::fromString(val);
                data.insert(key, date);
            } else {
                data.insert(key, val);
            }
        }
    }
    m_mediaRecorder->setMetaData(data);
}

#include "moc_camera.cpp"



void Camera::on_StartButton_released()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void Camera::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void Camera::on_pushButton_2_released()
{
    ui->stackedWidget->setCurrentIndex(4);
    m_captureSession.setVideoOutput(ui->viewfinder_2);
    start();
}

void Camera::on_pushButton_onemore_released()
{
    time10 = 500;
    ui->time_label->setText(QString::number(time10 / 100.0, 'f', 2));
    ui->stackedWidget->setCurrentIndex(3);
    m_captureSession.setVideoOutput(ui->viewfinder_2);
    start();
}

void Camera::Playgame() {

}

void Camera::CountDown()
{
    time10--;
    if (time10 >= 0) {
        ui->time_label->setText(QString::number(time10 / 100.0, 'f', 2));
    }
}

//一回目
void Camera::start() {
    cnt = 0;
    time10 = 500;
    ui->label_5->setText(QString::number(cnt));
    QRandomGenerator random = QRandomGenerator::securelySeeded();
    view_index = random.bounded(8 + 1);
    ViewImage(view_index);


    ui->stackedWidget->setCurrentIndex(3);
    time10--;
    timer->start(10);
}
void Camera::playgame() {

    QRandomGenerator random = QRandomGenerator::securelySeeded();
    view_index = random.bounded(8 + 1);
    ViewImage(view_index);


    ui->stackedWidget->setCurrentIndex(3);
    time10--;
    timer->start(10);
}

// RePlay(int view_index)
void Camera::RePlay() {
    if (time10 == 0) {

        takeImage();
    }
    if (time10 == -10){
        //HSVで画像の肌色抽出
       //Image_set();
        
        //音源
        player->setAudioOutput(audioOutput);
        audioOutput->setVolume(50);

        //手の判別
        Judge(module, device, view_index);
        cnt++;
       
        if (label == "false") {
            player->setSource(QUrl::fromLocalFile("music\\break.mp3"));
            player->play();
            Onemore();
        }
        else {
            player->setSource(QUrl::fromLocalFile("music\\correct.mp3"));
            player->play();

            ui->label_5->setText(QString::number(cnt));
            if (cnt == 1) {
                time10 = 400;
            }
            else if (cnt == 2) {
                time10 = 300;
            }
            else if (cnt > 2 && cnt < 5) {
                time10 = 200;
            }
            else {
                time10 = 100;
            }
            playgame();
        }
    }
}

void Camera::ViewImage(int view_index) {

    janken10 = new QGraphicsPixmapItem(QPixmap::fromImage(QImage(filenames[view_index])));

    scene_janken->addItem(janken10);
    ui->janken_graphicsView->setScene(scene_janken);

}

void Camera::Image_set() {
    cv::Mat input;
    input = cv::imread("hand_image\\hand_image.jpg", 1);
    // 肌色抽出のための範囲を定義
    cv::Scalar lowerBound = cv::Scalar(0, 60, 80);  // 下限値 (B, G, R)
    cv::Scalar upperBound = cv::Scalar(20, 160, 240);  // 上限値 (B, G, R)

    // 画像をHSV色空間に変換
    cv::Mat hsvImage;
    cv::cvtColor(input, hsvImage, cv::COLOR_BGR2HSV);

    // 肌色範囲内のピクセルをマスクする
    cv::Mat skinMask;
    cv::inRange(hsvImage, lowerBound, upperBound, skinMask);

    // 元の画像とマスクをビット単位でAND演算
    cv::Mat maskedImage;
    cv::bitwise_and(input, input, maskedImage, skinMask);

    // 画像を保存する
    cv::imwrite("hand_image\\output.jpg", input);
    cv::imwrite("hand_image\\output2.jpg", skinMask);
    cv::imwrite("hand_image\\output3.jpg", maskedImage);
}

void Camera::Judge(torch::jit::script::Module module, torch::Device device,int view_index) {

       

       cv::Mat image;

       // 画像ファイルを読み込む
       image = cv::imread("hand_image\\hand_image.jpg", cv::IMREAD_GRAYSCALE);
       // 二値化
       cv::threshold(image, image, 160, 255, cv::THRESH_BINARY);
       // 画像リサイズ
       cv::resize(image, image, cv::Size(224, 224));

       //cv::imshow("手", image);

       // OpenCVの行列をTensorに変換する
       auto tensor_image = torch::from_blob(image.data, { 1, 224, 224, 1 }, torch::kByte);

       tensor_image = tensor_image.permute({ 0, 3, 1, 2 }); // convert to CxHxW

       // 正規化する
       tensor_image = tensor_image.div(255);

       // Create a vector of inputs.
       std::vector<torch::jit::IValue> inputs;

       inputs.push_back(tensor_image.to(device));

       module.to(device);

       // Execute the model and turn its output into a tensor.
       at::Tensor output = module.forward({ inputs }).toTensor().to(device);

       auto max_result = output.argmax(1);
       int predicted_label = max_result.item<int>();

       // ラベルを出力する
       
       switch (predicted_label) {
       case 0:
           label = "goo";
           if (view_index == 2 || view_index == 4 || view_index == 6) {
               //ok
               label = "ok";
           }
           else {
               //false
               label = "false";
           }
           break;
       case 1:
           label = "choki";
           if (view_index == 1 || view_index == 3 || view_index == 8) {
               //ok
               label = "ok";
           }
           else {
               //false
               label = "false";
           }
           break;
       case 2:
           label = "par";
           if (view_index == 0 || view_index == 5 || view_index == 7) {
               //ok
               label = "ok";
           }
           else {
               //false
               label = "false";
           }
           break;
       default:
           label = "unknown";
           break;
       }
       //ui->label_5->setText(label);
       //std::cout << std::endl << "Predicted label: " << label << std::endl;

}

void Camera::Onemore()
{
    timer->stop();
    ui->stackedWidget->setCurrentIndex(4);
    ui->label_result->setText(QString::number(cnt-1));
}
