#include "addobjects.h"
#include <qcolordialog.h>
#include "ui_addobjects.h"

#include <QMessageBox>

#include <controller.h>

AddObjects::AddObjects(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::AddObjects)
{
    ui->setupUi(this);
    count = 0;
    countBs = 0;

    this->qcolor = QColor(0,0,0);
    this->qColorDialog = new QColorDialog();

    this->ui->tableWidget->insertColumn(0);
    this->ui->tableWidget->insertColumn(1);
    this->ui->tableWidget->setColumnWidth(0,80);
    this->ui->tableWidget->setColumnWidth(1,80);

    QTableWidgetItem* qtwi = new QTableWidgetItem(QString("X"),QTableWidgetItem::Type);
    this->ui->tableWidget->setHorizontalHeaderItem(0,qtwi);
    QTableWidgetItem* qtwi2 = new QTableWidgetItem(QString("Y"),QTableWidgetItem::Type);
    this->ui->tableWidget->setHorizontalHeaderItem(1,qtwi2);
}

AddObjects::~AddObjects()
{
    delete ui;
}

void AddObjects::on_pushButtonPoint_clicked()
{
    QString name = this->ui->lineNamePoint->text();
    if(name.isEmpty())
        QMessageBox::warning(this,"Erro","É necessário a inserção de um nome para o objeto!",QMessageBox::Ok);
    else
    {
        QColor strokeColor = this->qcolor;
        Controller::getInstance()->addPoint(&name, this->ui->SpinBoxPointX->value(),this->ui->SpinBoxPointY->value(), strokeColor);
        this->close();
    }
}


void AddObjects::on_pushButtonLine_clicked()
{
    QString name = this->ui->lineNameLine->text();
    if(name.isEmpty())
        QMessageBox::warning(this,"Erro","É necessário a inserção de um nome para o objeto!",QMessageBox::Ok);
    else
    {
        QColor strokeColor = this->qcolor;
        Controller::getInstance()->addLine(&name,
                                         this->ui->SpinBoxLineX1->value(),
                                         this->ui->SpinBoxLineY1->value(),
                                         this->ui->SpinBoxLineX2->value(),
                                         this->ui->SpinBoxLineY2->value(),
                                         strokeColor);
        this->close();
    }
}

void AddObjects::on_pushButtonPolygon_clicked()

{
    QString name = this->ui->lineNamePolygon->text();
    if(name.isEmpty())
        QMessageBox::warning(this,"Erro","É necessário a inserção de um nome para o objeto!",QMessageBox::Ok);
    else
    {
        Controller::getInstance()->addPolygon(&name, vertices, false);

        //Limpa tabela e vertices
        vertices.clear();
        this->ui->tableWidget->clear();
        for(int i =count;i >= 0;i--)
        {
            this->ui->tableWidget->removeRow(i);
        }
        count = 0;


        this->close();
    }

}

void AddObjects::on_pushButtonAddCoordPolygon_clicked()
{
    vertices.append(new Coordinate(this->ui->SpinBoxPolygonX->value(),this->ui->SpinBoxPolygonY->value()));
    this->ui->tableWidget->insertRow(count);

    //Coloca as coordenadas na tabela
    this->ui->tableWidget->setItem(count,0,new QTableWidgetItem(QString::number(this->ui->SpinBoxPolygonX->value())));
    this->ui->tableWidget->setItem(count,1,new QTableWidgetItem(QString::number(this->ui->SpinBoxPolygonY->value())));
    count++;
}

void AddObjects::on_pushButtonDeleteRow_clicked()
{
    this->ui->tableWidget->removeRow(this->ui->tableWidget->currentRow());
    vertices.removeAt(this->ui->tableWidget->currentRow()-1);
    count--;

}

void AddObjects::on_pushButtonCancel_clicked()
{
    this->close();
}

void AddObjects::on_pushButtonCancel_2_clicked()
{
    this->close();
}

void AddObjects::on_pushButtonCancel_3_clicked()
{
    this->close();
}

void AddObjects::on_pushButtonCancel_4_clicked()
{
    this->close();
}

void AddObjects::on_pushButtonCancel_5_clicked()
{
    this->close();
}
