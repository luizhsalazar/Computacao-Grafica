/********************************************************************************
** Form generated from reading UI file 'addobjects.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDOBJECTS_H
#define UI_ADDOBJECTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddObjects
{
public:
    QTabWidget *lineName;
    QWidget *tabWidgetPage1;
    QGroupBox *groupBox_5;
    QLabel *label_20;
    QLabel *label_21;
    QDoubleSpinBox *pointX;
    QDoubleSpinBox *pointY;
    QLabel *label_28;
    QDoubleSpinBox *pointZ;
    QPushButton *pushButtonPoint;
    QLineEdit *pointName;
    QLabel *label_22;
    QWidget *tabWidgetPage2;
    QGroupBox *groupBox_6;
    QLabel *label_24;
    QDoubleSpinBox *lineZ2;
    QLabel *label_32;
    QDoubleSpinBox *lineX2;
    QLabel *label_23;
    QDoubleSpinBox *lineY2;
    QGroupBox *groupBox_7;
    QDoubleSpinBox *lineZ1;
    QLabel *label_31;
    QLabel *label_29;
    QDoubleSpinBox *lineY1;
    QLabel *label_30;
    QDoubleSpinBox *lineX1;
    QPushButton *pushButtonLine;
    QLabel *label_27;
    QLineEdit *lineNameLine;
    QWidget *tabWidgetPage3;
    QPushButton *pushButtonPolygon;
    QLineEdit *lineNamePolygon;
    QLabel *label_38;
    QTableWidget *tableWidget;
    QDoubleSpinBox *polygonX;
    QDoubleSpinBox *polygonY;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *addCoordPol;
    QPushButton *deleteCoordPol;
    QCheckBox *checkBoxFill;
    QDoubleSpinBox *polygonZ;
    QLabel *label_7;
    QTableWidget *facesTable;
    QLabel *label_8;
    QLabel *label_9;
    QComboBox *faceCombo1;
    QComboBox *faceCombo2;
    QPushButton *addEdgePol;
    QPushButton *deleteEdgePol;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QComboBox *faceCombo3;
    QLabel *label;
    QSpinBox *red;
    QSpinBox *green;
    QSpinBox *blue;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *selectColorButton;
    QPushButton *addObjectCancel;

    void setupUi(QDialog *AddObjects)
    {
        if (AddObjects->objectName().isEmpty())
            AddObjects->setObjectName(QStringLiteral("AddObjects"));
        AddObjects->resize(524, 489);
        lineName = new QTabWidget(AddObjects);
        lineName->setObjectName(QStringLiteral("lineName"));
        lineName->setGeometry(QRect(10, 10, 371, 471));
        lineName->setTabPosition(QTabWidget::North);
        lineName->setTabShape(QTabWidget::Rounded);
        lineName->setUsesScrollButtons(true);
        tabWidgetPage1 = new QWidget();
        tabWidgetPage1->setObjectName(QStringLiteral("tabWidgetPage1"));
        groupBox_5 = new QGroupBox(tabWidgetPage1);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(30, 50, 311, 71));
        label_20 = new QLabel(groupBox_5);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(0, 30, 16, 16));
        QFont font;
        font.setPointSize(10);
        label_20->setFont(font);
        label_21 = new QLabel(groupBox_5);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(100, 30, 16, 16));
        label_21->setFont(font);
        pointX = new QDoubleSpinBox(groupBox_5);
        pointX->setObjectName(QStringLiteral("pointX"));
        pointX->setGeometry(QRect(20, 30, 71, 22));
        pointX->setMaximum(9999.99);
        pointY = new QDoubleSpinBox(groupBox_5);
        pointY->setObjectName(QStringLiteral("pointY"));
        pointY->setGeometry(QRect(120, 30, 71, 22));
        pointY->setMaximum(9999.99);
        label_28 = new QLabel(groupBox_5);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(200, 30, 16, 16));
        label_28->setFont(font);
        pointZ = new QDoubleSpinBox(groupBox_5);
        pointZ->setObjectName(QStringLiteral("pointZ"));
        pointZ->setGeometry(QRect(220, 30, 71, 22));
        pointZ->setMaximum(9999.99);
        pushButtonPoint = new QPushButton(tabWidgetPage1);
        pushButtonPoint->setObjectName(QStringLiteral("pushButtonPoint"));
        pushButtonPoint->setGeometry(QRect(10, 240, 101, 31));
        pointName = new QLineEdit(tabWidgetPage1);
        pointName->setObjectName(QStringLiteral("pointName"));
        pointName->setGeometry(QRect(80, 20, 181, 21));
        label_22 = new QLabel(tabWidgetPage1);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(30, 20, 41, 21));
        label_22->setFont(font);
        lineName->addTab(tabWidgetPage1, QString());
        tabWidgetPage2 = new QWidget();
        tabWidgetPage2->setObjectName(QStringLiteral("tabWidgetPage2"));
        groupBox_6 = new QGroupBox(tabWidgetPage2);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(30, 140, 301, 61));
        label_24 = new QLabel(groupBox_6);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(10, 30, 16, 16));
        label_24->setFont(font);
        lineZ2 = new QDoubleSpinBox(groupBox_6);
        lineZ2->setObjectName(QStringLiteral("lineZ2"));
        lineZ2->setGeometry(QRect(230, 30, 71, 22));
        lineZ2->setMaximum(9999.99);
        label_32 = new QLabel(groupBox_6);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(210, 30, 16, 16));
        label_32->setFont(font);
        lineX2 = new QDoubleSpinBox(groupBox_6);
        lineX2->setObjectName(QStringLiteral("lineX2"));
        lineX2->setGeometry(QRect(30, 30, 71, 22));
        lineX2->setMaximum(9999.99);
        label_23 = new QLabel(groupBox_6);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(110, 30, 16, 16));
        label_23->setFont(font);
        lineY2 = new QDoubleSpinBox(groupBox_6);
        lineY2->setObjectName(QStringLiteral("lineY2"));
        lineY2->setGeometry(QRect(130, 30, 71, 22));
        lineY2->setMaximum(9999.99);
        groupBox_7 = new QGroupBox(tabWidgetPage2);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(30, 60, 301, 61));
        lineZ1 = new QDoubleSpinBox(groupBox_7);
        lineZ1->setObjectName(QStringLiteral("lineZ1"));
        lineZ1->setGeometry(QRect(230, 30, 71, 22));
        lineZ1->setMaximum(9999.99);
        label_31 = new QLabel(groupBox_7);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(10, 30, 16, 16));
        label_31->setFont(font);
        label_29 = new QLabel(groupBox_7);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(110, 30, 16, 16));
        label_29->setFont(font);
        lineY1 = new QDoubleSpinBox(groupBox_7);
        lineY1->setObjectName(QStringLiteral("lineY1"));
        lineY1->setGeometry(QRect(130, 30, 71, 22));
        lineY1->setMaximum(9999.99);
        label_30 = new QLabel(groupBox_7);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(210, 30, 16, 16));
        label_30->setFont(font);
        lineX1 = new QDoubleSpinBox(groupBox_7);
        lineX1->setObjectName(QStringLiteral("lineX1"));
        lineX1->setGeometry(QRect(30, 30, 71, 22));
        lineX1->setMaximum(9999.99);
        pushButtonLine = new QPushButton(tabWidgetPage2);
        pushButtonLine->setObjectName(QStringLiteral("pushButtonLine"));
        pushButtonLine->setGeometry(QRect(10, 240, 91, 31));
        label_27 = new QLabel(tabWidgetPage2);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(30, 30, 81, 21));
        label_27->setFont(font);
        lineNameLine = new QLineEdit(tabWidgetPage2);
        lineNameLine->setObjectName(QStringLiteral("lineNameLine"));
        lineNameLine->setGeometry(QRect(80, 30, 181, 21));
        lineName->addTab(tabWidgetPage2, QString());
        tabWidgetPage3 = new QWidget();
        tabWidgetPage3->setObjectName(QStringLiteral("tabWidgetPage3"));
        pushButtonPolygon = new QPushButton(tabWidgetPage3);
        pushButtonPolygon->setObjectName(QStringLiteral("pushButtonPolygon"));
        pushButtonPolygon->setGeometry(QRect(10, 370, 121, 31));
        lineNamePolygon = new QLineEdit(tabWidgetPage3);
        lineNamePolygon->setObjectName(QStringLiteral("lineNamePolygon"));
        lineNamePolygon->setGeometry(QRect(80, 20, 181, 21));
        label_38 = new QLabel(tabWidgetPage3);
        label_38->setObjectName(QStringLiteral("label_38"));
        label_38->setGeometry(QRect(30, 20, 81, 21));
        label_38->setFont(font);
        tableWidget = new QTableWidget(tabWidgetPage3);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 81, 251, 121));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setShowGrid(true);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(3);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(76);
        tableWidget->horizontalHeader()->setHighlightSections(true);
        tableWidget->horizontalHeader()->setMinimumSectionSize(24);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(30);
        tableWidget->verticalHeader()->setHighlightSections(false);
        polygonX = new QDoubleSpinBox(tabWidgetPage3);
        polygonX->setObjectName(QStringLiteral("polygonX"));
        polygonX->setGeometry(QRect(290, 60, 71, 22));
        polygonX->setMinimum(-9999);
        polygonX->setMaximum(9999);
        polygonY = new QDoubleSpinBox(tabWidgetPage3);
        polygonY->setObjectName(QStringLiteral("polygonY"));
        polygonY->setGeometry(QRect(290, 90, 71, 22));
        polygonY->setMinimum(-9999);
        polygonY->setMaximum(9999);
        label_5 = new QLabel(tabWidgetPage3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(270, 60, 16, 16));
        label_5->setFont(font);
        label_6 = new QLabel(tabWidgetPage3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(270, 90, 16, 16));
        label_6->setFont(font);
        addCoordPol = new QPushButton(tabWidgetPage3);
        addCoordPol->setObjectName(QStringLiteral("addCoordPol"));
        addCoordPol->setGeometry(QRect(280, 150, 81, 31));
        deleteCoordPol = new QPushButton(tabWidgetPage3);
        deleteCoordPol->setObjectName(QStringLiteral("deleteCoordPol"));
        deleteCoordPol->setGeometry(QRect(280, 180, 81, 31));
        checkBoxFill = new QCheckBox(tabWidgetPage3);
        checkBoxFill->setObjectName(QStringLiteral("checkBoxFill"));
        checkBoxFill->setGeometry(QRect(290, 20, 71, 18));
        polygonZ = new QDoubleSpinBox(tabWidgetPage3);
        polygonZ->setObjectName(QStringLiteral("polygonZ"));
        polygonZ->setGeometry(QRect(290, 120, 71, 22));
        polygonZ->setMinimum(-9999);
        polygonZ->setMaximum(9999);
        label_7 = new QLabel(tabWidgetPage3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(270, 120, 16, 16));
        label_7->setFont(font);
        facesTable = new QTableWidget(tabWidgetPage3);
        if (facesTable->columnCount() < 3)
            facesTable->setColumnCount(3);
        facesTable->setObjectName(QStringLiteral("facesTable"));
        facesTable->setGeometry(QRect(10, 240, 251, 121));
        facesTable->setRowCount(0);
        facesTable->setColumnCount(3);
        facesTable->horizontalHeader()->setDefaultSectionSize(76);
        label_8 = new QLabel(tabWidgetPage3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 220, 111, 17));
        label_9 = new QLabel(tabWidgetPage3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 60, 91, 17));
        faceCombo1 = new QComboBox(tabWidgetPage3);
        faceCombo1->setObjectName(QStringLiteral("faceCombo1"));
        faceCombo1->setGeometry(QRect(300, 250, 61, 31));
        faceCombo2 = new QComboBox(tabWidgetPage3);
        faceCombo2->setObjectName(QStringLiteral("faceCombo2"));
        faceCombo2->setGeometry(QRect(300, 290, 61, 31));
        addEdgePol = new QPushButton(tabWidgetPage3);
        addEdgePol->setObjectName(QStringLiteral("addEdgePol"));
        addEdgePol->setGeometry(QRect(280, 370, 81, 31));
        deleteEdgePol = new QPushButton(tabWidgetPage3);
        deleteEdgePol->setObjectName(QStringLiteral("deleteEdgePol"));
        deleteEdgePol->setGeometry(QRect(280, 400, 81, 31));
        label_10 = new QLabel(tabWidgetPage3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(270, 260, 21, 17));
        label_11 = new QLabel(tabWidgetPage3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(270, 300, 21, 17));
        label_12 = new QLabel(tabWidgetPage3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(270, 340, 21, 17));
        faceCombo3 = new QComboBox(tabWidgetPage3);
        faceCombo3->setObjectName(QStringLiteral("faceCombo3"));
        faceCombo3->setGeometry(QRect(300, 330, 61, 31));
        lineName->addTab(tabWidgetPage3, QString());
        label = new QLabel(AddObjects);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(410, 40, 91, 17));
        red = new QSpinBox(AddObjects);
        red->setObjectName(QStringLiteral("red"));
        red->setGeometry(QRect(430, 60, 61, 31));
        red->setReadOnly(true);
        red->setMaximum(255);
        red->setValue(255);
        green = new QSpinBox(AddObjects);
        green->setObjectName(QStringLiteral("green"));
        green->setGeometry(QRect(430, 100, 61, 31));
        green->setReadOnly(true);
        green->setMaximum(255);
        green->setValue(255);
        blue = new QSpinBox(AddObjects);
        blue->setObjectName(QStringLiteral("blue"));
        blue->setGeometry(QRect(430, 140, 61, 31));
        blue->setReadOnly(true);
        blue->setMaximum(255);
        blue->setValue(255);
        label_2 = new QLabel(AddObjects);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(410, 70, 31, 16));
        label_3 = new QLabel(AddObjects);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(410, 110, 41, 17));
        label_4 = new QLabel(AddObjects);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(410, 150, 61, 17));
        selectColorButton = new QPushButton(AddObjects);
        selectColorButton->setObjectName(QStringLiteral("selectColorButton"));
        selectColorButton->setGeometry(QRect(397, 180, 111, 31));
        addObjectCancel = new QPushButton(AddObjects);
        addObjectCancel->setObjectName(QStringLiteral("addObjectCancel"));
        addObjectCancel->setGeometry(QRect(440, 450, 75, 31));

        retranslateUi(AddObjects);

        lineName->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AddObjects);
    } // setupUi

    void retranslateUi(QDialog *AddObjects)
    {
        AddObjects->setWindowTitle(QApplication::translate("AddObjects", "Adicionar Objeto", 0));
        groupBox_5->setTitle(QApplication::translate("AddObjects", "Coordinates of the Point", 0));
        label_20->setText(QApplication::translate("AddObjects", "X", 0));
        label_21->setText(QApplication::translate("AddObjects", "Y", 0));
        label_28->setText(QApplication::translate("AddObjects", "Z", 0));
        pushButtonPoint->setText(QApplication::translate("AddObjects", "Add Point", 0));
        label_22->setText(QApplication::translate("AddObjects", "Nome:", 0));
        lineName->setTabText(lineName->indexOf(tabWidgetPage1), QApplication::translate("AddObjects", "Point", 0));
        groupBox_6->setTitle(QApplication::translate("AddObjects", "Final Coordinates of the Line", 0));
        label_24->setText(QApplication::translate("AddObjects", "X", 0));
        label_32->setText(QApplication::translate("AddObjects", "Z", 0));
        label_23->setText(QApplication::translate("AddObjects", "Y", 0));
        groupBox_7->setTitle(QApplication::translate("AddObjects", "Initial Coordinates of the Line", 0));
        label_31->setText(QApplication::translate("AddObjects", "X", 0));
        label_29->setText(QApplication::translate("AddObjects", "Y", 0));
        label_30->setText(QApplication::translate("AddObjects", "Z", 0));
        pushButtonLine->setText(QApplication::translate("AddObjects", "Add Line", 0));
        label_27->setText(QApplication::translate("AddObjects", "Nome:", 0));
        lineName->setTabText(lineName->indexOf(tabWidgetPage2), QApplication::translate("AddObjects", "Line", 0));
        pushButtonPolygon->setText(QApplication::translate("AddObjects", "Add Polygon", 0));
        label_38->setText(QApplication::translate("AddObjects", "Nome:", 0));
        label_5->setText(QApplication::translate("AddObjects", "X", 0));
        label_6->setText(QApplication::translate("AddObjects", "Y", 0));
        addCoordPol->setText(QApplication::translate("AddObjects", "Add", 0));
        deleteCoordPol->setText(QApplication::translate("AddObjects", "Delete", 0));
        checkBoxFill->setText(QApplication::translate("AddObjects", "Filled", 0));
        label_7->setText(QApplication::translate("AddObjects", "Z", 0));
        label_8->setText(QApplication::translate("AddObjects", "Triangular Faces", 0));
        label_9->setText(QApplication::translate("AddObjects", "Coordinates", 0));
        addEdgePol->setText(QApplication::translate("AddObjects", "Add", 0));
        deleteEdgePol->setText(QApplication::translate("AddObjects", "Delete", 0));
        label_10->setText(QApplication::translate("AddObjects", "V1", 0));
        label_11->setText(QApplication::translate("AddObjects", "V2", 0));
        label_12->setText(QApplication::translate("AddObjects", "V3", 0));
        lineName->setTabText(lineName->indexOf(tabWidgetPage3), QApplication::translate("AddObjects", "Polygon", 0));
        label->setText(QApplication::translate("AddObjects", "Stroke Color", 0));
        label_2->setText(QApplication::translate("AddObjects", "R", 0));
        label_3->setText(QApplication::translate("AddObjects", "G", 0));
        label_4->setText(QApplication::translate("AddObjects", "B", 0));
        selectColorButton->setText(QApplication::translate("AddObjects", "Select Color", 0));
        addObjectCancel->setText(QApplication::translate("AddObjects", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class AddObjects: public Ui_AddObjects {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDOBJECTS_H
