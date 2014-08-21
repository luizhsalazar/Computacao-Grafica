#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QListWidgetItem>
#include <mediator.h>

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
    Mediator::getInstance()->zoomInWindow(this->ui->zoomSpeed->value());
}

void MainWindow::on_buttonLessZoom_clicked()
{
    Mediator::getInstance()->zoomOutWindow(this->ui->zoomSpeed->value());
}

void MainWindow::on_buttonUp_clicked()
{
    Mediator::getInstance()->moveWindowVertical(this->ui->WindowControlSpeed->value());
}

void MainWindow::on_buttonDown_clicked()
{
    Mediator::getInstance()->moveWindowVertical(-this->ui->WindowControlSpeed->value());
}

void MainWindow::on_buttonLeft_clicked()
{
    Mediator::getInstance()->moveWindowHorizontal(-this->ui->WindowControlSpeed->value());
}

void MainWindow::on_buttonRight_clicked()
{
    Mediator::getInstance()->moveWindowHorizontal(this->ui->WindowControlSpeed->value());
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

    Mediator::getInstance()->deleteGeometricShape(index);
}

void MainWindow::on_actionAddObjeto_triggered()
{
    this->addObjectsUi->exec();
}
