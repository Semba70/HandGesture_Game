/********************************************************************************
** Form generated from reading UI file 'camera.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERA_H
#define UI_CAMERA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Camera
{
public:
    QAction *actionExit;
    QAction *actionStartCamera;
    QAction *actionStopCamera;
    QAction *actionSettings;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
    QStackedWidget *stackedWidget;
    QWidget *viewfinderPage;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *StartButton;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_6;
    QWidget *previewPage;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QGridLayout *gridLayout_5;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_5;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout_7;
    QSpacerItem *verticalSpacer_7;
    QVideoWidget *viewfinder;
    QSpacerItem *horizontalSpacer_8;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_7;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_15;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_9;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *horizontalSpacer_17;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_16;
    QSpacerItem *horizontalSpacer_13;
    QGraphicsView *howto_graphicsView;
    QWidget *page_2;
    QFormLayout *formLayout;
    QLabel *time_label;
    QGraphicsView *janken_graphicsView;
    QVideoWidget *viewfinder_2;
    QLabel *lastImagePreviewLabel_2;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_12;
    QLabel *label_5;
    QLabel *label_8;
    QWidget *page_4;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_18;
    QLabel *label_result;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_19;
    QPushButton *pushButton_onemore;
    QWidget *page;
    QVBoxLayout *verticalLayout_3;
    QTabWidget *captureWidget;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *takeImageButton;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QSlider *exposureCompensation;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QPushButton *recordButton;
    QPushButton *pauseButton;
    QPushButton *stopButton;
    QSpacerItem *verticalSpacer;
    QPushButton *muteButton;
    QPushButton *metaDataButton;
    QLabel *lastImagePreviewLabel;
    QSpacerItem *verticalSpacer_3;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuDevices;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Camera)
    {
        if (Camera->objectName().isEmpty())
            Camera->setObjectName("Camera");
        Camera->resize(902, 842);
        actionExit = new QAction(Camera);
        actionExit->setObjectName("actionExit");
        actionStartCamera = new QAction(Camera);
        actionStartCamera->setObjectName("actionStartCamera");
        actionStopCamera = new QAction(Camera);
        actionStopCamera->setObjectName("actionStopCamera");
        actionSettings = new QAction(Camera);
        actionSettings->setObjectName("actionSettings");
        centralwidget = new QWidget(Camera);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(145, 145, 145, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        stackedWidget->setPalette(palette);
        QFont font;
        font.setPointSize(40);
        stackedWidget->setFont(font);
        viewfinderPage = new QWidget();
        viewfinderPage->setObjectName("viewfinderPage");
        horizontalLayout = new QHBoxLayout(viewfinderPage);
        horizontalLayout->setObjectName("horizontalLayout");
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 0, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        StartButton = new QPushButton(viewfinderPage);
        StartButton->setObjectName("StartButton");
        QFont font1;
        font1.setPointSize(50);
        StartButton->setFont(font1);

        gridLayout_3->addWidget(StartButton, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 1, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_5, 0, 0, 1, 1);

        label_2 = new QLabel(viewfinderPage);
        label_2->setObjectName("label_2");
        QFont font2;
        font2.setPointSize(72);
        label_2->setFont(font2);

        gridLayout_4->addWidget(label_2, 0, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_6, 0, 2, 1, 1);


        horizontalLayout->addLayout(gridLayout_4);

        stackedWidget->addWidget(viewfinderPage);
        previewPage = new QWidget();
        previewPage->setObjectName("previewPage");
        verticalLayout = new QVBoxLayout(previewPage);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(previewPage);
        label_3->setObjectName("label_3");
        label_3->setSizeIncrement(QSize(0, 0));
        label_3->setBaseSize(QSize(0, 0));
        QFont font3;
        font3.setPointSize(35);
        font3.setUnderline(false);
        label_3->setFont(font3);
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setLineWidth(1);
        label_3->setMidLineWidth(0);
        label_3->setTextFormat(Qt::AutoText);
        label_3->setScaledContents(false);
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_3);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName("gridLayout_5");
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_4, 0, 1, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_5, 2, 1, 1, 1);

        pushButton = new QPushButton(previewPage);
        pushButton->setObjectName("pushButton");

        gridLayout_5->addWidget(pushButton, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer, 1, 0, 1, 1);


        horizontalLayout_3->addLayout(gridLayout_5);


        verticalLayout->addLayout(horizontalLayout_3);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName("gridLayout_7");
        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_7, 0, 0, 1, 1);

        viewfinder = new QVideoWidget(previewPage);
        viewfinder->setObjectName("viewfinder");

        gridLayout_7->addWidget(viewfinder, 0, 1, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_8, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_7);

        stackedWidget->addWidget(previewPage);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        verticalLayout_7 = new QVBoxLayout(page_3);
        verticalLayout_7->setObjectName("verticalLayout_7");
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_7->addItem(horizontalSpacer_11);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_7->addItem(horizontalSpacer_14);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_7->addItem(horizontalSpacer_10);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_15);

        label_4 = new QLabel(page_3);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        horizontalLayout_4->addWidget(label_4);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_9);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_5->addItem(horizontalSpacer_17);

        pushButton_2 = new QPushButton(page_3);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout_5->addWidget(pushButton_2);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_5->addItem(horizontalSpacer_16);


        verticalLayout_6->addLayout(verticalLayout_5);


        horizontalLayout_4->addLayout(verticalLayout_6);


        horizontalLayout_5->addLayout(horizontalLayout_4);


        verticalLayout_7->addLayout(horizontalLayout_5);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_7->addItem(horizontalSpacer_13);

        howto_graphicsView = new QGraphicsView(page_3);
        howto_graphicsView->setObjectName("howto_graphicsView");

        verticalLayout_7->addWidget(howto_graphicsView);

        stackedWidget->addWidget(page_3);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        formLayout = new QFormLayout(page_2);
        formLayout->setObjectName("formLayout");
        time_label = new QLabel(page_2);
        time_label->setObjectName("time_label");
        time_label->setFont(font2);
        time_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(2, QFormLayout::FieldRole, time_label);

        janken_graphicsView = new QGraphicsView(page_2);
        janken_graphicsView->setObjectName("janken_graphicsView");

        formLayout->setWidget(3, QFormLayout::LabelRole, janken_graphicsView);

        viewfinder_2 = new QVideoWidget(page_2);
        viewfinder_2->setObjectName("viewfinder_2");
        lastImagePreviewLabel_2 = new QLabel(viewfinder_2);
        lastImagePreviewLabel_2->setObjectName("lastImagePreviewLabel_2");
        lastImagePreviewLabel_2->setGeometry(QRect(30, 200, 641, 431));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lastImagePreviewLabel_2->sizePolicy().hasHeightForWidth());
        lastImagePreviewLabel_2->setSizePolicy(sizePolicy1);
        lastImagePreviewLabel_2->setFrameShape(QFrame::Box);

        formLayout->setWidget(3, QFormLayout::FieldRole, viewfinder_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_12);

        label_5 = new QLabel(page_2);
        label_5->setObjectName("label_5");

        horizontalLayout_6->addWidget(label_5);

        label_8 = new QLabel(page_2);
        label_8->setObjectName("label_8");

        horizontalLayout_6->addWidget(label_8);


        formLayout->setLayout(2, QFormLayout::LabelRole, horizontalLayout_6);

        stackedWidget->addWidget(page_2);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        verticalLayout_9 = new QVBoxLayout(page_4);
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        label_6 = new QLabel(page_4);
        label_6->setObjectName("label_6");
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(label_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_18);

        label_result = new QLabel(page_4);
        label_result->setObjectName("label_result");
        label_result->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_result);

        label_7 = new QLabel(page_4);
        label_7->setObjectName("label_7");
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_7);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_19);


        verticalLayout_8->addLayout(horizontalLayout_2);

        pushButton_onemore = new QPushButton(page_4);
        pushButton_onemore->setObjectName("pushButton_onemore");

        verticalLayout_8->addWidget(pushButton_onemore);


        verticalLayout_9->addLayout(verticalLayout_8);

        stackedWidget->addWidget(page_4);
        page = new QWidget();
        page->setObjectName("page");
        verticalLayout_3 = new QVBoxLayout(page);
        verticalLayout_3->setObjectName("verticalLayout_3");
        captureWidget = new QTabWidget(page);
        captureWidget->setObjectName("captureWidget");
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        verticalLayout_2 = new QVBoxLayout(tab_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        takeImageButton = new QPushButton(tab_2);
        takeImageButton->setObjectName("takeImageButton");
        takeImageButton->setEnabled(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/shutter.svg"), QSize(), QIcon::Normal, QIcon::Off);
        takeImageButton->setIcon(icon);

        verticalLayout_2->addWidget(takeImageButton);

        verticalSpacer_2 = new QSpacerItem(20, 161, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        label = new QLabel(tab_2);
        label->setObjectName("label");

        verticalLayout_2->addWidget(label);

        exposureCompensation = new QSlider(tab_2);
        exposureCompensation->setObjectName("exposureCompensation");
        exposureCompensation->setMinimum(-4);
        exposureCompensation->setMaximum(4);
        exposureCompensation->setPageStep(2);
        exposureCompensation->setOrientation(Qt::Horizontal);
        exposureCompensation->setTickPosition(QSlider::TicksAbove);

        verticalLayout_2->addWidget(exposureCompensation);

        captureWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName("gridLayout_2");
        recordButton = new QPushButton(tab);
        recordButton->setObjectName("recordButton");

        gridLayout_2->addWidget(recordButton, 0, 0, 1, 1);

        pauseButton = new QPushButton(tab);
        pauseButton->setObjectName("pauseButton");

        gridLayout_2->addWidget(pauseButton, 1, 0, 1, 1);

        stopButton = new QPushButton(tab);
        stopButton->setObjectName("stopButton");

        gridLayout_2->addWidget(stopButton, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 76, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 3, 0, 1, 1);

        muteButton = new QPushButton(tab);
        muteButton->setObjectName("muteButton");
        muteButton->setCheckable(true);

        gridLayout_2->addWidget(muteButton, 4, 0, 1, 1);

        metaDataButton = new QPushButton(tab);
        metaDataButton->setObjectName("metaDataButton");
        metaDataButton->setCheckable(true);

        gridLayout_2->addWidget(metaDataButton, 5, 0, 1, 1);

        captureWidget->addTab(tab, QString());

        verticalLayout_3->addWidget(captureWidget);

        lastImagePreviewLabel = new QLabel(page);
        lastImagePreviewLabel->setObjectName("lastImagePreviewLabel");
        sizePolicy1.setHeightForWidth(lastImagePreviewLabel->sizePolicy().hasHeightForWidth());
        lastImagePreviewLabel->setSizePolicy(sizePolicy1);
        lastImagePreviewLabel->setFrameShape(QFrame::Box);

        verticalLayout_3->addWidget(lastImagePreviewLabel);

        verticalSpacer_3 = new QSpacerItem(108, 177, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        stackedWidget->addWidget(page);

        verticalLayout_4->addWidget(stackedWidget);

        Camera->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Camera);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 902, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuDevices = new QMenu(menubar);
        menuDevices->setObjectName("menuDevices");
        Camera->setMenuBar(menubar);
        statusbar = new QStatusBar(Camera);
        statusbar->setObjectName("statusbar");
        Camera->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuDevices->menuAction());
        menuFile->addAction(actionStartCamera);
        menuFile->addAction(actionStopCamera);
        menuFile->addSeparator();
        menuFile->addAction(actionSettings);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);

        retranslateUi(Camera);
        QObject::connect(actionExit, &QAction::triggered, Camera, qOverload<>(&QMainWindow::close));
        QObject::connect(actionSettings, SIGNAL(triggered()), Camera, SLOT(configureCaptureSettings()));
        QObject::connect(actionStartCamera, SIGNAL(triggered()), Camera, SLOT(startCamera()));
        QObject::connect(actionStopCamera, SIGNAL(triggered()), Camera, SLOT(stopCamera()));
        QObject::connect(muteButton, SIGNAL(toggled(bool)), Camera, SLOT(setMuted(bool)));
        QObject::connect(stopButton, SIGNAL(clicked()), Camera, SLOT(stop()));
        QObject::connect(takeImageButton, SIGNAL(clicked()), Camera, SLOT(takeImage()));
        QObject::connect(recordButton, SIGNAL(clicked()), Camera, SLOT(record()));
        QObject::connect(exposureCompensation, SIGNAL(valueChanged(int)), Camera, SLOT(setExposureCompensation(int)));
        QObject::connect(pauseButton, SIGNAL(clicked()), Camera, SLOT(pause()));

        stackedWidget->setCurrentIndex(0);
        captureWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Camera);
    } // setupUi

    void retranslateUi(QMainWindow *Camera)
    {
        Camera->setWindowTitle(QCoreApplication::translate("Camera", "Camera", nullptr));
        actionExit->setText(QCoreApplication::translate("Camera", "Close", nullptr));
        actionStartCamera->setText(QCoreApplication::translate("Camera", "Start Camera", nullptr));
        actionStopCamera->setText(QCoreApplication::translate("Camera", "Stop Camera", nullptr));
        actionSettings->setText(QCoreApplication::translate("Camera", "Change Settings", nullptr));
        StartButton->setText(QCoreApplication::translate("Camera", "\343\202\271\343\202\277\343\203\274\343\203\210", nullptr));
        label_2->setText(QCoreApplication::translate("Camera", "\343\201\230\343\202\203\343\202\223\346\244\234\345\256\232", nullptr));
        label_3->setText(QCoreApplication::translate("Camera", "\342\206\221\343\203\241\343\203\213\343\203\245\343\203\274\343\203\220\343\203\274\343\201\256\343\200\214Devices\343\200\215\343\202\210\343\202\212\n"
"\345\257\276\345\277\234\343\201\256\343\202\253\343\203\241\343\203\251\343\202\222\n"
"\351\201\270\346\212\236\343\201\227\343\201\246\343\201\217\343\201\240\343\201\225\343\201\204", nullptr));
        pushButton->setText(QCoreApplication::translate("Camera", "\346\254\241\343\201\270", nullptr));
        label_4->setText(QCoreApplication::translate("Camera", "\351\201\212\343\201\263\346\226\271", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Camera", "\343\202\271\343\202\277\343\203\274\343\203\210", nullptr));
        time_label->setText(QString());
        lastImagePreviewLabel_2->setText(QString());
        label_5->setText(QCoreApplication::translate("Camera", "0", nullptr));
        label_8->setText(QCoreApplication::translate("Camera", "\345\225\217\346\255\243\350\247\243", nullptr));
        label_6->setText(QCoreApplication::translate("Camera", "\343\201\226\343\202\223\343\201\255\343\202\223\357\274\201\343\201\276\343\201\237\343\203\201\343\203\243\343\203\254\343\203\263\343\202\270\343\201\227\343\202\210\343\201\206\357\274\201", nullptr));
        label_result->setText(QString());
        label_7->setText(QCoreApplication::translate("Camera", "\345\225\217\346\255\243\350\247\243\357\274\201", nullptr));
        pushButton_onemore->setText(QCoreApplication::translate("Camera", "\343\202\202\343\201\206\344\270\200\345\272\246\343\201\202\343\201\235\343\201\266", nullptr));
        takeImageButton->setText(QCoreApplication::translate("Camera", "Capture Photo", nullptr));
        label->setText(QCoreApplication::translate("Camera", "Exposure Compensation:", nullptr));
        captureWidget->setTabText(captureWidget->indexOf(tab_2), QCoreApplication::translate("Camera", "Image", nullptr));
        recordButton->setText(QCoreApplication::translate("Camera", "Record", nullptr));
        pauseButton->setText(QCoreApplication::translate("Camera", "Pause", nullptr));
        stopButton->setText(QCoreApplication::translate("Camera", "Stop", nullptr));
        muteButton->setText(QCoreApplication::translate("Camera", "Mute", nullptr));
        metaDataButton->setText(QCoreApplication::translate("Camera", "Set metadata", nullptr));
        captureWidget->setTabText(captureWidget->indexOf(tab), QCoreApplication::translate("Camera", "Video", nullptr));
        lastImagePreviewLabel->setText(QString());
        menuFile->setTitle(QCoreApplication::translate("Camera", "File", nullptr));
        menuDevices->setTitle(QCoreApplication::translate("Camera", "Devices", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Camera: public Ui_Camera {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERA_H
