#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QListWidgetItem>
#include <controller.h>

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->addObjectsUi = new AddObjects();
}

MainWindow::~MainWindow()
{
    delete ui;
}

QGraphicsView* MainWindow::getDrawWindow()
{
    return ui->draw_window;
}

void MainWindow::addObjectName(const char* name)
{
    this->ui->listObjects->addItem(new QListWidgetItem(name));
}

void MainWindow::on_buttonMoreZoom_clicked()
{
    Controller::getInstance()->zoomInWindow(this->ui->zoomSpeed->value());
}

void MainWindow::on_buttonLessZoom_clicked()
{
    Controller::getInstance()->zoomOutWindow(this->ui->zoomSpeed->value());
}

void MainWindow::on_buttonUp_clicked()
{
    Controller::getInstance()->moveWindowVertical(this->ui->WindowControlSpeed->value());
}

void MainWindow::on_buttonDown_clicked()
{
    Controller::getInstance()->moveWindowVertical(-this->ui->WindowControlSpeed->value());
}

void MainWindow::on_buttonLeft_clicked()
{
    Controller::getInstance()->moveWindowHorizontal(-this->ui->WindowControlSpeed->value());
}

void MainWindow::on_buttonRight_clicked()
{
    Controller::getInstance()->moveWindowHorizontal(this->ui->WindowControlSpeed->value());
}

void MainWindow::on_deleteButton_clicked()
{
    QListWidget* listObjects = this->ui->listObjects;
    int index = listObjects->currentRow();

    if(index != -1)
    {
        listObjects->takeItem(index);
    }

    listObjects->setCurrentRow(-1);

    Controller::getInstance()->deleteGeometricShape(index);
}

void MainWindow::on_actionAddObjeto_triggered()
{
    this->addObjectsUi->exec();
}

void MainWindow::on_pushButtonScale_clicked()
{
    QListWidget* listObjects = this->ui->listObjects;
    int index = listObjects->currentRow();

    if(index != -1)
    {
        Controller::getInstance()->resizeObject(index,this->ui->SpinBoxScaleX->value(),this->ui->SpinBoxScaleY->value());
    }
    else
    {
        QMessageBox::warning(this,"Erro","Nenhum objeto selecionado!",QMessageBox::Ok);
    }
}

void MainWindow::on_pushButtonRotate_clicked()
{
    QListWidget* listObjects = this->ui->listObjects;
    int index = listObjects->currentRow();

        if(index != -1)
        {
            if(ui->radioOrigin->isChecked())
            {
                Controller::getInstance()->rotateObject(index,ui->spinBoxRotate->value(),ORIGIN);
            }
            else if(ui->radioPoint->isChecked())
            {
                Controller::getInstance()->rotateObject(index,ui->spinBoxRotate->value(),ui->SpinBoxPX->value(),ui->SpinBoxPY->value());

            }
            else if(ui->radioCenter->isChecked())
            {
                Controller::getInstance()->rotateObject(index,ui->spinBoxRotate->value(),CENTER);
            }
        }

        else
        {
            QMessageBox::warning(this,"Erro","Nenhum objeto selecionado!",QMessageBox::Ok);

        }

}

void MainWindow::on_pushButtonMove_clicked()
{
    QListWidget* listObjects = this->ui->listObjects;
        int index = listObjects->currentRow();

        if(index != -1)
        {

            Controller::getInstance()->moveObject(index,this->ui->SpinBoxMoveX->value(),this->ui->SpinBoxMoveY->value());
        }
        else
        {
            QMessageBox::warning(this,"Erro","Nenhum objeto selecionado!",QMessageBox::Ok);

        }
}
