// Copyright (C) 2017 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef CAMERA_H
#define CAMERA_H

/*
#include <iostream>
#include <opencv2/opencv.hpp>
#include <torch/torch.h>
#include <torch/script.h>
*/

#include <torch/torch.h>
#include <iostream>
#include <torch/script.h>
#include <opencv2/opencv.hpp>


#include <QAudioInput>
#include <QCamera>
#include <QImageCapture>
#include <QMediaCaptureSession>
#include <QMediaDevices>
#include <QMediaMetaData>
#include <QMediaRecorder>
#include <QScopedPointer>

#include <QMainWindow>


#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include <QTimer>

#include <QMediaPlayer>
#include <qaudiooutput.h>
#include <QUrl>


QT_BEGIN_NAMESPACE
namespace Ui {
class Camera;
}
class QActionGroup;
QT_END_NAMESPACE

class MetaDataDialog;

class Camera : public QMainWindow
{
    Q_OBJECT

public:
    Camera();

    QTimer* timer;
    int time10 = 500;

    void playgame();
    void start();
    void ViewImage(int view_index);
    void Judge(torch::jit::script::Module module, torch::Device device,int view_index);
    void Image_set();
    void Onemore();

    char filenames[9][13] = { "image\\0.jpg", "image\\1.jpg", "image\\2.jpg" , "image\\3.jpg", "image\\4.jpg", "image\\5.jpg", "image\\6.jpg", "image\\7.jpg", "image\\8.jpg" };
    int view_index;
    int cnt = 0;
    QString label;


    //‰¹Œ¹
    QMediaPlayer* player = new QMediaPlayer;
    QAudioOutput* audioOutput = new QAudioOutput;

public slots:
    void saveMetaData();

private slots:
    void init();


    void setCamera(const QCameraDevice &cameraDevice);

    void startCamera();
    void stopCamera();

    void record();
    void pause();
    void stop();
    void setMuted(bool);

    void takeImage();
    void displayCaptureError(int, QImageCapture::Error, const QString &errorString);

    void configureCaptureSettings();
    void configureVideoSettings();
    void configureImageSettings();

    void displayRecorderError();
    void displayCameraError();

    void updateCameraDevice(QAction *action);

    void updateCameraActive(bool active);
    void updateCaptureMode();
    void updateRecorderState(QMediaRecorder::RecorderState state);
    void setExposureCompensation(int index);

    void updateRecordTime();

    void processCapturedImage(int requestId, const QImage &img);

    void displayViewfinder();
    void displayCapturedImage();

    void readyForCapture(bool ready);
    void imageSaved(int id, const QString &fileName);

    void updateCameras();

    void showMetaDataDialog();




    void on_StartButton_released();

    void on_pushButton_clicked();

    void on_pushButton_2_released();

    void on_pushButton_onemore_released();


    void CountDown();

    void RePlay();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void closeEvent(QCloseEvent *event) override;

    void Playgame();

private:
    Ui::Camera *ui;
    QGraphicsScene *scene_how;
    QGraphicsPixmapItem *pix;

    QGraphicsScene* scene_janken;


    QGraphicsPixmapItem* janken10;



    QActionGroup *videoDevicesGroup = nullptr;

    QMediaDevices m_devices;
    QScopedPointer<QImageCapture> m_imageCapture;
    QMediaCaptureSession m_captureSession;
    QScopedPointer<QCamera> m_camera;
    QScopedPointer<QAudioInput> m_audioInput;
    QScopedPointer<QMediaRecorder> m_mediaRecorder;

    bool m_isCapturingImage = false;
    bool m_applicationExiting = false;
    bool m_doImageCapture = true;

    MetaDataDialog *m_metaDataDialog = nullptr;
};

#endif