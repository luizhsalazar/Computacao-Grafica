/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Oct 20 14:56:38 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDial>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionReta;
    QAction *actionPoligono;
    QAction *actionPonto;
    QAction *actionAddObject;
    QAction *actionMover_Objeto;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLabel *label;
    QPushButton *deleteButton;
    QListWidget *listObjects;
    QTabWidget *tabWidget;
    QWidget *tab;
    QDoubleSpinBox *translateX;
    QDoubleSpinBox *translateY;
    QPushButton *translateButton;
    QLabel *label_3;
    QLabel *label_5;
    QDoubleSpinBox *translateZ;
    QLabel *label_14;
    QWidget *tab_2;
    QPushButton *scaleButton;
    QDoubleSpinBox *scaleZ;
    QLabel *label_18;
    QDoubleSpinBox *scaleY;
    QLabel *label_6;
    QDoubleSpinBox *scaleX;
    QLabel *label_7;
    QWidget *tab_3;
    QSpinBox *rotateObjAngle;
    QLabel *label_8;
    QPushButton *buttonRotate;
    QDial *rotateObjDial;
    QFrame *rotationAxisObjWrapper;
    QRadioButton *z_axis_obj;
    QRadioButton *x_axis_obj;
    QRadioButton *y_axis_obj;
    QFrame *rotationTypeObjWrapper;
    QRadioButton *radioOrigin;
    QRadioButton *radioPoint;
    QRadioButton *radioCenter;
    QFrame *framePointRotation;
    QLabel *label_10;
    QDoubleSpinBox *rotateZSpin;
    QDoubleSpinBox *rotateYSpin;
    QLabel *label_9;
    QDoubleSpinBox *rotateXSpin;
    QLabel *label_19;
    QPushButton *addObjButton;
    QPushButton *loadXmlButton;
    QGraphicsView *draw_window;
    QLabel *label_12;
    QTabWidget *tabWidget_2;
    QWidget *Rotation;
    QSpinBox *WindowControlSpeed;
    QPushButton *buttonRight;
    QPushButton *buttonLeft;
    QPushButton *buttonUp;
    QPushButton *buttonDown;
    QLabel *label_2;
    QPushButton *buttonFront;
    QPushButton *buttonBack;
    QPushButton *resetWindowButton;
    QWidget *tab_5;
    QSpinBox *rotationAngle;
    QPushButton *rotateWindowLeft;
    QLabel *label_11;
    QPushButton *rotateWindowRight;
    QRadioButton *x_axis;
    QRadioButton *y_axis;
    QRadioButton *z_axis;
    QDial *rotateX;
    QDial *rotateY;
    QDial *rotateZ;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QWidget *tab_4;
    QSpinBox *zoomSpeed;
    QLabel *label_4;
    QPushButton *buttonMoreZoom;
    QPushButton *buttonLessZoom;
    QWidget *tab_6;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLabel *label_13;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(835, 655);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionReta = new QAction(MainWindow);
        actionReta->setObjectName(QString::fromUtf8("actionReta"));
        actionReta->setMenuRole(QAction::TextHeuristicRole);
        actionPoligono = new QAction(MainWindow);
        actionPoligono->setObjectName(QString::fromUtf8("actionPoligono"));
        actionPonto = new QAction(MainWindow);
        actionPonto->setObjectName(QString::fromUtf8("actionPonto"));
        actionAddObject = new QAction(MainWindow);
        actionAddObject->setObjectName(QString::fromUtf8("actionAddObject"));
        actionAddObject->setCheckable(false);
        actionAddObject->setMenuRole(QAction::ApplicationSpecificRole);
        actionMover_Objeto = new QAction(MainWindow);
        actionMover_Objeto->setObjectName(QString::fromUtf8("actionMover_Objeto"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, -20, 311, 421));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 30, 71, 16));
        deleteButton = new QPushButton(groupBox);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(70, 180, 81, 27));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(deleteButton->sizePolicy().hasHeightForWidth());
        deleteButton->setSizePolicy(sizePolicy1);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/minus-circle.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon);
        listObjects = new QListWidget(groupBox);
        listObjects->setObjectName(QString::fromUtf8("listObjects"));
        listObjects->setGeometry(QRect(0, 50, 311, 121));
        tabWidget = new QTabWidget(groupBox);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 220, 311, 201));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        translateX = new QDoubleSpinBox(tab);
        translateX->setObjectName(QString::fromUtf8("translateX"));
        translateX->setGeometry(QRect(40, 10, 62, 31));
        translateX->setMinimum(-9999);
        translateX->setMaximum(9999.99);
        translateX->setSingleStep(0.1);
        translateY = new QDoubleSpinBox(tab);
        translateY->setObjectName(QString::fromUtf8("translateY"));
        translateY->setGeometry(QRect(40, 50, 62, 31));
        translateY->setMinimum(-9999);
        translateY->setMaximum(9999.99);
        translateY->setSingleStep(0.1);
        translateButton = new QPushButton(tab);
        translateButton->setObjectName(QString::fromUtf8("translateButton"));
        translateButton->setGeometry(QRect(220, 120, 51, 31));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/tick-circle.png"), QSize(), QIcon::Normal, QIcon::Off);
        translateButton->setIcon(icon1);
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 20, 16, 16));
        QFont font;
        font.setPointSize(10);
        label_3->setFont(font);
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 60, 16, 16));
        label_5->setFont(font);
        translateZ = new QDoubleSpinBox(tab);
        translateZ->setObjectName(QString::fromUtf8("translateZ"));
        translateZ->setGeometry(QRect(40, 90, 62, 31));
        translateZ->setMinimum(-9999);
        translateZ->setMaximum(9999.99);
        translateZ->setSingleStep(0.1);
        label_14 = new QLabel(tab);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(20, 100, 16, 16));
        label_14->setFont(font);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        scaleButton = new QPushButton(tab_2);
        scaleButton->setObjectName(QString::fromUtf8("scaleButton"));
        scaleButton->setGeometry(QRect(220, 120, 51, 31));
        scaleButton->setIcon(icon1);
        scaleZ = new QDoubleSpinBox(tab_2);
        scaleZ->setObjectName(QString::fromUtf8("scaleZ"));
        scaleZ->setGeometry(QRect(40, 90, 62, 31));
        scaleZ->setMinimum(0.1);
        scaleZ->setMaximum(9999.99);
        scaleZ->setSingleStep(0.1);
        label_18 = new QLabel(tab_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(20, 100, 16, 16));
        label_18->setFont(font);
        scaleY = new QDoubleSpinBox(tab_2);
        scaleY->setObjectName(QString::fromUtf8("scaleY"));
        scaleY->setGeometry(QRect(40, 50, 62, 31));
        scaleY->setMinimum(0.1);
        scaleY->setMaximum(9999.99);
        scaleY->setSingleStep(0.1);
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 60, 16, 16));
        label_6->setFont(font);
        scaleX = new QDoubleSpinBox(tab_2);
        scaleX->setObjectName(QString::fromUtf8("scaleX"));
        scaleX->setGeometry(QRect(40, 10, 62, 31));
        scaleX->setMinimum(0.1);
        scaleX->setMaximum(9999.99);
        scaleX->setSingleStep(0.1);
        scaleX->setValue(0.1);
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 20, 16, 16));
        label_7->setFont(font);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        rotateObjAngle = new QSpinBox(tab_3);
        rotateObjAngle->setObjectName(QString::fromUtf8("rotateObjAngle"));
        rotateObjAngle->setGeometry(QRect(30, 70, 71, 22));
        rotateObjAngle->setMinimum(-360);
        rotateObjAngle->setMaximum(360);
        label_8 = new QLabel(tab_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 70, 20, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Bitstream Charter"));
        font1.setPointSize(14);
        label_8->setFont(font1);
        buttonRotate = new QPushButton(tab_3);
        buttonRotate->setObjectName(QString::fromUtf8("buttonRotate"));
        buttonRotate->setGeometry(QRect(220, 120, 51, 31));
        buttonRotate->setIcon(icon1);
        rotateObjDial = new QDial(tab_3);
        rotateObjDial->setObjectName(QString::fromUtf8("rotateObjDial"));
        rotateObjDial->setGeometry(QRect(20, 90, 81, 61));
        QFont font2;
        font2.setStyleStrategy(QFont::PreferDefault);
        rotateObjDial->setFont(font2);
        rotateObjDial->setFocusPolicy(Qt::WheelFocus);
        rotateObjDial->setOrientation(Qt::Horizontal);
        rotateObjDial->setWrapping(true);
        rotationAxisObjWrapper = new QFrame(tab_3);
        rotationAxisObjWrapper->setObjectName(QString::fromUtf8("rotationAxisObjWrapper"));
        rotationAxisObjWrapper->setGeometry(QRect(10, 40, 271, 21));
        rotationAxisObjWrapper->setFrameShape(QFrame::Panel);
        rotationAxisObjWrapper->setFrameShadow(QFrame::Plain);
        rotationAxisObjWrapper->setLineWidth(0);
        z_axis_obj = new QRadioButton(rotationAxisObjWrapper);
        z_axis_obj->setObjectName(QString::fromUtf8("z_axis_obj"));
        z_axis_obj->setGeometry(QRect(200, 0, 61, 22));
        QFont font3;
        font3.setPointSize(9);
        z_axis_obj->setFont(font3);
        z_axis_obj->setChecked(false);
        x_axis_obj = new QRadioButton(rotationAxisObjWrapper);
        x_axis_obj->setObjectName(QString::fromUtf8("x_axis_obj"));
        x_axis_obj->setGeometry(QRect(10, 0, 71, 22));
        x_axis_obj->setFont(font3);
        x_axis_obj->setChecked(true);
        y_axis_obj = new QRadioButton(rotationAxisObjWrapper);
        y_axis_obj->setObjectName(QString::fromUtf8("y_axis_obj"));
        y_axis_obj->setGeometry(QRect(100, 0, 71, 22));
        y_axis_obj->setFont(font3);
        rotationTypeObjWrapper = new QFrame(tab_3);
        rotationTypeObjWrapper->setObjectName(QString::fromUtf8("rotationTypeObjWrapper"));
        rotationTypeObjWrapper->setGeometry(QRect(10, 10, 271, 21));
        rotationTypeObjWrapper->setFrameShape(QFrame::Box);
        rotationTypeObjWrapper->setFrameShadow(QFrame::Raised);
        rotationTypeObjWrapper->setLineWidth(0);
        radioOrigin = new QRadioButton(rotationTypeObjWrapper);
        radioOrigin->setObjectName(QString::fromUtf8("radioOrigin"));
        radioOrigin->setGeometry(QRect(10, 0, 71, 22));
        radioOrigin->setFont(font3);
        radioOrigin->setChecked(true);
        radioPoint = new QRadioButton(rotationTypeObjWrapper);
        radioPoint->setObjectName(QString::fromUtf8("radioPoint"));
        radioPoint->setGeometry(QRect(100, 0, 71, 22));
        radioPoint->setFont(font3);
        radioCenter = new QRadioButton(rotationTypeObjWrapper);
        radioCenter->setObjectName(QString::fromUtf8("radioCenter"));
        radioCenter->setGeometry(QRect(200, 0, 71, 22));
        radioCenter->setFont(font3);
        radioCenter->setChecked(false);
        framePointRotation = new QFrame(tab_3);
        framePointRotation->setObjectName(QString::fromUtf8("framePointRotation"));
        framePointRotation->setGeometry(QRect(110, 70, 101, 91));
        framePointRotation->setFrameShape(QFrame::Panel);
        framePointRotation->setFrameShadow(QFrame::Plain);
        framePointRotation->setLineWidth(0);
        label_10 = new QLabel(framePointRotation);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(0, 0, 16, 16));
        label_10->setFont(font);
        rotateZSpin = new QDoubleSpinBox(framePointRotation);
        rotateZSpin->setObjectName(QString::fromUtf8("rotateZSpin"));
        rotateZSpin->setGeometry(QRect(20, 60, 71, 22));
        rotateZSpin->setMinimum(-9999);
        rotateZSpin->setMaximum(9999.99);
        rotateYSpin = new QDoubleSpinBox(framePointRotation);
        rotateYSpin->setObjectName(QString::fromUtf8("rotateYSpin"));
        rotateYSpin->setGeometry(QRect(20, 30, 71, 22));
        rotateYSpin->setMinimum(-9999);
        rotateYSpin->setMaximum(9999.99);
        label_9 = new QLabel(framePointRotation);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(0, 30, 16, 16));
        label_9->setFont(font);
        rotateXSpin = new QDoubleSpinBox(framePointRotation);
        rotateXSpin->setObjectName(QString::fromUtf8("rotateXSpin"));
        rotateXSpin->setGeometry(QRect(20, 0, 71, 22));
        rotateXSpin->setMinimum(-9999);
        rotateXSpin->setMaximum(9999.99);
        label_19 = new QLabel(framePointRotation);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(0, 60, 16, 16));
        label_19->setFont(font);
        tabWidget->addTab(tab_3, QString());
        addObjButton = new QPushButton(groupBox);
        addObjButton->setObjectName(QString::fromUtf8("addObjButton"));
        addObjButton->setGeometry(QRect(0, 180, 61, 27));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/plus-circle.png"), QSize(), QIcon::Normal, QIcon::Off);
        addObjButton->setIcon(icon2);
        loadXmlButton = new QPushButton(groupBox);
        loadXmlButton->setObjectName(QString::fromUtf8("loadXmlButton"));
        loadXmlButton->setGeometry(QRect(160, 180, 101, 27));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/blue-document--arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        loadXmlButton->setIcon(icon3);
        draw_window = new QGraphicsView(centralWidget);
        draw_window->setObjectName(QString::fromUtf8("draw_window"));
        draw_window->setGeometry(QRect(330, 30, 500, 560));
        sizePolicy.setHeightForWidth(draw_window->sizePolicy().hasHeightForWidth());
        draw_window->setSizePolicy(sizePolicy);
        draw_window->setMinimumSize(QSize(500, 500));
        draw_window->setMaximumSize(QSize(500, 560));
        draw_window->setFrameShape(QFrame::StyledPanel);
        draw_window->setFrameShadow(QFrame::Sunken);
        draw_window->setLineWidth(1);
        draw_window->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        draw_window->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(330, 10, 67, 17));
        tabWidget_2 = new QTabWidget(centralWidget);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(10, 430, 311, 161));
        Rotation = new QWidget();
        Rotation->setObjectName(QString::fromUtf8("Rotation"));
        WindowControlSpeed = new QSpinBox(Rotation);
        WindowControlSpeed->setObjectName(QString::fromUtf8("WindowControlSpeed"));
        WindowControlSpeed->setGeometry(QRect(60, 10, 61, 31));
        WindowControlSpeed->setMinimum(0);
        WindowControlSpeed->setMaximum(100);
        WindowControlSpeed->setValue(50);
        buttonRight = new QPushButton(Rotation);
        buttonRight->setObjectName(QString::fromUtf8("buttonRight"));
        buttonRight->setGeometry(QRect(110, 80, 51, 31));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonRight->setIcon(icon4);
        buttonLeft = new QPushButton(Rotation);
        buttonLeft->setObjectName(QString::fromUtf8("buttonLeft"));
        buttonLeft->setGeometry(QRect(10, 80, 51, 31));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/arrow-180.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonLeft->setIcon(icon5);
        buttonUp = new QPushButton(Rotation);
        buttonUp->setObjectName(QString::fromUtf8("buttonUp"));
        buttonUp->setGeometry(QRect(60, 50, 51, 31));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/arrow-090.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonUp->setIcon(icon6);
        buttonDown = new QPushButton(Rotation);
        buttonDown->setObjectName(QString::fromUtf8("buttonDown"));
        buttonDown->setGeometry(QRect(60, 80, 51, 31));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/arrow-270.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonDown->setIcon(icon7);
        label_2 = new QLabel(Rotation);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 20, 46, 13));
        buttonFront = new QPushButton(Rotation);
        buttonFront->setObjectName(QString::fromUtf8("buttonFront"));
        buttonFront->setGeometry(QRect(220, 10, 51, 31));
        buttonBack = new QPushButton(Rotation);
        buttonBack->setObjectName(QString::fromUtf8("buttonBack"));
        buttonBack->setGeometry(QRect(220, 40, 51, 31));
        resetWindowButton = new QPushButton(Rotation);
        resetWindowButton->setObjectName(QString::fromUtf8("resetWindowButton"));
        resetWindowButton->setGeometry(QRect(190, 80, 111, 31));
        tabWidget_2->addTab(Rotation, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        rotationAngle = new QSpinBox(tab_5);
        rotationAngle->setObjectName(QString::fromUtf8("rotationAngle"));
        rotationAngle->setGeometry(QRect(200, 80, 61, 31));
        rotationAngle->setMinimum(0);
        rotationAngle->setMaximum(360);
        rotationAngle->setValue(90);
        rotateWindowLeft = new QPushButton(tab_5);
        rotateWindowLeft->setObjectName(QString::fromUtf8("rotateWindowLeft"));
        rotateWindowLeft->setGeometry(QRect(120, 80, 31, 31));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons/arrow-return-180-left.png"), QSize(), QIcon::Normal, QIcon::Off);
        rotateWindowLeft->setIcon(icon8);
        label_11 = new QLabel(tab_5);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(60, 90, 51, 18));
        QFont font4;
        font4.setPointSize(11);
        label_11->setFont(font4);
        rotateWindowRight = new QPushButton(tab_5);
        rotateWindowRight->setObjectName(QString::fromUtf8("rotateWindowRight"));
        rotateWindowRight->setGeometry(QRect(160, 80, 31, 31));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icons/arrow-return.png"), QSize(), QIcon::Normal, QIcon::Off);
        rotateWindowRight->setIcon(icon9);
        x_axis = new QRadioButton(tab_5);
        x_axis->setObjectName(QString::fromUtf8("x_axis"));
        x_axis->setGeometry(QRect(70, 50, 41, 22));
        x_axis->setChecked(true);
        y_axis = new QRadioButton(tab_5);
        y_axis->setObjectName(QString::fromUtf8("y_axis"));
        y_axis->setGeometry(QRect(140, 50, 41, 22));
        y_axis->setChecked(false);
        z_axis = new QRadioButton(tab_5);
        z_axis->setObjectName(QString::fromUtf8("z_axis"));
        z_axis->setGeometry(QRect(210, 50, 41, 22));
        rotateX = new QDial(tab_5);
        rotateX->setObjectName(QString::fromUtf8("rotateX"));
        rotateX->setGeometry(QRect(90, 10, 31, 31));
        rotateY = new QDial(tab_5);
        rotateY->setObjectName(QString::fromUtf8("rotateY"));
        rotateY->setGeometry(QRect(150, 10, 31, 31));
        rotateZ = new QDial(tab_5);
        rotateZ->setObjectName(QString::fromUtf8("rotateZ"));
        rotateZ->setGeometry(QRect(210, 10, 31, 31));
        label_15 = new QLabel(tab_5);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(80, 20, 16, 17));
        label_16 = new QLabel(tab_5);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(140, 20, 16, 17));
        label_17 = new QLabel(tab_5);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(200, 20, 16, 17));
        tabWidget_2->addTab(tab_5, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        zoomSpeed = new QSpinBox(tab_4);
        zoomSpeed->setObjectName(QString::fromUtf8("zoomSpeed"));
        zoomSpeed->setGeometry(QRect(180, 50, 71, 31));
        zoomSpeed->setMinimum(0);
        zoomSpeed->setMaximum(100);
        zoomSpeed->setValue(50);
        label_4 = new QLabel(tab_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 60, 41, 16));
        label_4->setFont(font4);
        buttonMoreZoom = new QPushButton(tab_4);
        buttonMoreZoom->setObjectName(QString::fromUtf8("buttonMoreZoom"));
        buttonMoreZoom->setGeometry(QRect(100, 50, 31, 31));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icons/plus-button.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonMoreZoom->setIcon(icon10);
        buttonLessZoom = new QPushButton(tab_4);
        buttonLessZoom->setObjectName(QString::fromUtf8("buttonLessZoom"));
        buttonLessZoom->setGeometry(QRect(140, 50, 31, 31));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/icons/minus-button.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonLessZoom->setIcon(icon11);
        tabWidget_2->addTab(tab_4, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        radioButton = new QRadioButton(tab_6);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(50, 50, 81, 22));
        radioButton->setChecked(false);
        radioButton_2 = new QRadioButton(tab_6);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(150, 50, 117, 22));
        radioButton_2->setChecked(true);
        tabWidget_2->addTab(tab_6, QString());
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 410, 111, 17));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 835, 21));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Sistema Gr\303\241fico", 0));
        actionReta->setText(QApplication::translate("MainWindow", "Reta", 0, -1));
        actionPoligono->setText(QApplication::translate("MainWindow", "Poligono", 0, -1));
        actionPonto->setText(QApplication::translate("MainWindow", "Ponto", 0, -1));
        actionAddObject->setText(QApplication::translate("MainWindow", "Adicionar Objeto", 0, -1));
        actionAddObject->setIconText(QApplication::translate("MainWindow", "Add Object", 0, -1));
        actionMover_Objeto->setText(QApplication::translate("MainWindow", "Mover Objeto", 0, -1));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("MainWindow", "Objetos", 0, -1));
        deleteButton->setText(QApplication::translate("MainWindow", "Delete", 0, -1));
        translateButton->setText(QApplication::translate("MainWindow", "OK", 0, -1));
        label_3->setText(QApplication::translate("MainWindow", "X", 0, -1));
        label_5->setText(QApplication::translate("MainWindow", "Y", 0, -1));
        label_14->setText(QApplication::translate("MainWindow", "Z", 0, -1));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Move", 0, -1));
        scaleButton->setText(QApplication::translate("MainWindow", "OK", 0, -1));
        label_18->setText(QApplication::translate("MainWindow", "Z", 0, -1));
        label_6->setText(QApplication::translate("MainWindow", "Y", 0, -1));
        label_7->setText(QApplication::translate("MainWindow", "X", 0, -1));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Resize", 0, -1));
        label_8->setText(QApplication::translate("MainWindow", "\316\261", 0, -1));
        buttonRotate->setText(QApplication::translate("MainWindow", "OK", 0, -1));
        z_axis_obj->setText(QApplication::translate("MainWindow", "Z Axis", 0, -1));
        x_axis_obj->setText(QApplication::translate("MainWindow", "X Axis", 0, -1));
        y_axis_obj->setText(QApplication::translate("MainWindow", "Y Axis", 0, -1));
        radioOrigin->setText(QApplication::translate("MainWindow", "Origin", 0, -1));
        radioPoint->setText(QApplication::translate("MainWindow", "Point", 0, -1));
        radioCenter->setText(QApplication::translate("MainWindow", "Center", 0, -1));
        label_10->setText(QApplication::translate("MainWindow", "X", 0, -1));
        label_9->setText(QApplication::translate("MainWindow", "Y", 0, -1));
        label_19->setText(QApplication::translate("MainWindow", "Z", 0, -1));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Rotation", 0, -1));
        addObjButton->setText(QApplication::translate("MainWindow", "Add", 0, -1));
        loadXmlButton->setText(QApplication::translate("MainWindow", "Load .xml", 0, -1));
#ifndef QT_NO_TOOLTIP
        draw_window->setToolTip(QApplication::translate("MainWindow", "Viewport", 0, -1));
#endif // QT_NO_TOOLTIP
        label_12->setText(QApplication::translate("MainWindow", "Viewport", 0, -1));
        buttonRight->setText(QString());
        buttonLeft->setText(QString());
        buttonUp->setText(QString());
        buttonDown->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Rate:", 0, -1));
        buttonFront->setText(QApplication::translate("MainWindow", "Front", 0, -1));
        buttonBack->setText(QApplication::translate("MainWindow", "Back", 0, -1));
        resetWindowButton->setText(QApplication::translate("MainWindow", "Reset Window", 0, -1));
        tabWidget_2->setTabText(tabWidget_2->indexOf(Rotation), QApplication::translate("MainWindow", "Movement", 0, -1));
        rotateWindowLeft->setText(QString());
        label_11->setText(QApplication::translate("MainWindow", "Rotate:", 0, -1));
        rotateWindowRight->setText(QString());
        x_axis->setText(QApplication::translate("MainWindow", "X", 0, -1));
        y_axis->setText(QApplication::translate("MainWindow", "Y", 0, -1));
        z_axis->setText(QApplication::translate("MainWindow", "Z", 0, -1));
        label_15->setText(QApplication::translate("MainWindow", "X", 0, -1));
        label_16->setText(QApplication::translate("MainWindow", "Y", 0, -1));
        label_17->setText(QApplication::translate("MainWindow", "Z", 0, -1));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("MainWindow", "Rotation", 0, -1));
        label_4->setText(QApplication::translate("MainWindow", "Zoom:", 0, -1));
        buttonMoreZoom->setText(QString());
        buttonLessZoom->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("MainWindow", "Zoom", 0, -1));
        radioButton->setText(QApplication::translate("MainWindow", "Parallel", 0, -1));
        radioButton_2->setText(QApplication::translate("MainWindow", "Perspective", 0, -1));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QApplication::translate("MainWindow", "Projection", 0, -1));
        label_13->setText(QApplication::translate("MainWindow", "Window Control", 0, -1));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
