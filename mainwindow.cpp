 #include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QListWidgetItem>
#include <mediator.h>

#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->addObjectsUi = new AddObjects();

    this->currentDialObjectValue = 0;

    this->ui->framePointRotation->hide();

    this->currentDialXValue = 0;
    this->currentDialYValue = 0;
    this->currentDialZValue = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

QGraphicsView* MainWindow::getDrawWindow()
{
    return ui->draw_window;
}

void MainWindow::addObjectName(QString* name)
{
    this->ui->listObjects->addItem(new QListWidgetItem(QString(name->toUtf8().data())));
    this->ui->listObjects->setCurrentRow(0);
}

void MainWindow::on_addObjButton_clicked()
{
    this->addObjectsUi->exec();
}

void MainWindow::on_buttonUp_clicked()
{
    Mediator::getInstance()->moveWindow(-this->ui->WindowControlSpeed->value(), Y_AXIS);
}

void MainWindow::on_buttonDown_clicked()
{
    Mediator::getInstance()->moveWindow(this->ui->WindowControlSpeed->value(), Y_AXIS);
}

void MainWindow::on_buttonLeft_clicked()
{
    Mediator::getInstance()->moveWindow(this->ui->WindowControlSpeed->value(), X_AXIS);
}

void MainWindow::on_buttonRight_clicked()
{
    Mediator::getInstance()->moveWindow(-this->ui->WindowControlSpeed->value(), X_AXIS);
}

void MainWindow::on_buttonFront_clicked()
{
    Mediator::getInstance()->moveWindow(-this->ui->WindowControlSpeed->value(), Z_AXIS);
}

void MainWindow::on_buttonBack_clicked()
{
    Mediator::getInstance()->moveWindow(this->ui->WindowControlSpeed->value(), Z_AXIS);
}

void MainWindow::on_rotateWindowLeft_clicked()
{
    this->rotateWindow(-this->ui->rotationAngle->value());
}

void MainWindow::on_rotateWindowRight_clicked()
{
    this->rotateWindow(this->ui->rotationAngle->value());
}

void MainWindow::rotateWindow(int value)
{
    Mediator *m = Mediator::getInstance();
    if(this->ui->x_axis->isChecked()){
        m->rotateWindow(value, X_AXIS);
    }else if(this->ui->y_axis->isChecked()){
        m->rotateWindow(value, Y_AXIS);
    }else if(this->ui->z_axis->isChecked()){
        m->rotateWindow(value, Z_AXIS);
    }
}

void MainWindow::on_rotateX_dialMoved(int value)
{
    int rotateValue = -1;

    if(this->currentDialXValue < value || (this->currentDialXValue == 0 && value == 99))
        rotateValue = 1;

    this->currentDialXValue = value;

    Mediator *m = Mediator::getInstance();
    m->rotateWindow(rotateValue, X_AXIS);
}

void MainWindow::on_rotateY_dialMoved(int value)
{
    int rotateValue = -1;

    if(this->currentDialYValue < value || (this->currentDialYValue == 0 && value == 99))
        rotateValue = 1;

    this->currentDialYValue = value;

    Mediator *m = Mediator::getInstance();
    m->rotateWindow(rotateValue, Y_AXIS);
}

void MainWindow::on_rotateZ_dialMoved(int value)
{
    int rotateValue = -1;

    if(this->currentDialZValue < value || (this->currentDialZValue == 0 && value == 99))
        rotateValue = 1;

    this->currentDialZValue = value;

    Mediator *m = Mediator::getInstance();
    m->rotateWindow(rotateValue, Z_AXIS);
}

void MainWindow::on_buttonMoreZoom_clicked()
{
    Mediator::getInstance()->zoomWindow(this->ui->zoomSpeed->value());
}

void MainWindow::on_buttonLessZoom_clicked()
{
    Mediator::getInstance()->zoomWindow(-this->ui->zoomSpeed->value());
}

void MainWindow::on_deleteButton_clicked()
{
    QListWidget* listObjects = this->ui->listObjects;
    int index = listObjects->currentRow();

    if(index != -1)
    {
        listObjects->takeItem(index);
    }

    //listObjects->setCurrentRow(-1);

    Mediator::getInstance()->deleteShape3D(index);
}

void MainWindow::on_translateButton_clicked()
{
    QListWidget* listObjects = this->ui->listObjects;
    int index = listObjects->currentRow();

    if(index != -1)
    {
        Mediator::getInstance()->moveObject(index,this->ui->translateX->value(),
                                            this->ui->translateY->value(),
                                            this->ui->translateZ->value());
    }
    else
    {
        QMessageBox::warning(this,"Erro","No object selected.",QMessageBox::Ok);

    }
}

void MainWindow::on_scaleButton_clicked()
{
    QListWidget* listObjects = this->ui->listObjects;
    int index = listObjects->currentRow();

    if(index != -1)
    {
        Mediator::getInstance()->resizeObject(index,this->ui->scaleX->value(),
                                              this->ui->scaleY->value(),
                                              this->ui->scaleZ->value());
    }
    else
    {
        QMessageBox::warning(this,"Erro","No object selected.",QMessageBox::Ok);
    }
}

void MainWindow::on_buttonRotate_clicked()
{

    QListWidget* listObjects = this->ui->listObjects;
    int index = listObjects->currentRow();

    if(index != -1)
    {
        axis raxis;
        if(ui->x_axis_obj->isChecked())
            raxis = X_AXIS;
        else if(ui->y_axis_obj->isChecked())
            raxis = Y_AXIS;
        else
            raxis = Z_AXIS;

        if(ui->radioOrigin->isChecked())
        {
            Mediator::getInstance()->rotateObject(index, this->ui->rotateObjAngle->value(), raxis, ORIGIN);
        }
        else if(ui->radioPoint->isChecked())
        {
            Mediator::getInstance()->rotateObject(index, this->ui->rotateObjAngle->value(),
                                                  this->ui->rotateXSpin->value(),
                                                  this->ui->rotateYSpin->value(),
                                                  this->ui->rotateZSpin->value(), raxis);

        }
        else if(ui->radioCenter->isChecked())
        {
            Mediator::getInstance()->rotateObject(index, this->ui->rotateObjAngle->value(), raxis, CENTER);
        }
    } else {
        QMessageBox::warning(this,"Erro","No object selected.",QMessageBox::Ok);

    }
}

void MainWindow::on_radioPoint_toggled(bool checked)
{
    if(checked) {
        this->ui->framePointRotation->show();
    } else {
        this->ui->framePointRotation->hide();
    }
}

void MainWindow::on_rotateObjDial_dialMoved(int value)
{
    QListWidget* listObjects = this->ui->listObjects;
    int index = listObjects->currentRow();

    if(index != -1)
    {
        double rotateValue = -1;

        if(this->currentDialObjectValue < value || (this->currentDialObjectValue == 0 && value == 99))
            rotateValue = 1;

        this->currentDialObjectValue = value;

        axis raxis;
        if(ui->x_axis_obj->isChecked())
            raxis = X_AXIS;
        else if(ui->y_axis_obj->isChecked())
            raxis = Y_AXIS;
        else
            raxis = Z_AXIS;

        if(ui->radioOrigin->isChecked())
        {
            Mediator::getInstance()->rotateObject(index, rotateValue, raxis, ORIGIN);
        }
        else if(ui->radioPoint->isChecked())
        {
            Mediator::getInstance()->rotateObject(index, rotateValue,
                                                  this->ui->rotateXSpin->value(),
                                                  this->ui->rotateYSpin->value(),
                                                  this->ui->rotateZSpin->value(), raxis);

        }
        else if(ui->radioCenter->isChecked())
        {
            Mediator::getInstance()->rotateObject(index, rotateValue, raxis, CENTER);
        }
    }
}

void MainWindow::on_radioButton_toggled(bool checked)
{
    if(checked){
        Mediator::getInstance()->setProjectionType(PARALLEL);
    }else{
        Mediator::getInstance()->setProjectionType(PERSPECTIVE);
    }
}

void MainWindow::on_resetWindowButton_clicked()
{
    Mediator::getInstance()->resetWindow();
}

void MainWindow::on_loadXmlButton_clicked()
{
    QFileDialog* f = new QFileDialog();
    QString fileName = f->getOpenFileName();
    char *str = fileName.toLocal8Bit().data();
    Mediator::getInstance()->loadObjFile(str);
}
