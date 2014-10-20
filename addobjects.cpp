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

    this->ui->tableWidgetBspline_2->insertColumn(0);
    this->ui->tableWidgetBspline_2->insertColumn(1);
    this->ui->tableWidgetBspline_2->setColumnWidth(0,80);
    this->ui->tableWidgetBspline_2->setColumnWidth(1,80);
    this->ui->tableWidgetBspline_2->setHorizontalHeaderItem(0,qtwi);
    this->ui->tableWidgetBspline_2->setHorizontalHeaderItem(1,qtwi2);
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

void AddObjects::on_pushButtonBezier_clicked()
{
    QString name = this->ui->lineNameBezier->text();
    if(name.isEmpty())
        QMessageBox::warning(this,"Erro","O campo 'nome' e de preenchimento obrigatorio.",QMessageBox::Ok);
    else
    {

        QList<Coordinate*> coordinates;
        coordinates.append(new Coordinate(this->ui->SpinBoxBezierX1->value(),this->ui->SpinBoxBezierY1->value()));
        coordinates.append(new Coordinate(this->ui->SpinBoxBezierX2->value(),this->ui->SpinBoxBezierY2->value()));
        coordinates.append(new Coordinate(this->ui->SpinBoxBezierX3->value(),this->ui->SpinBoxBezierY3->value()));
        coordinates.append(new Coordinate(this->ui->SpinBoxBezierX4->value(),this->ui->SpinBoxBezierY4->value()));

        Controller::getInstance()->addBezierCurve(&name,coordinates);

        this->close();
    }
}


void AddObjects::on_pushButtonBspline_2_clicked()
{
    QString name = this->ui->lineNameBspline_2->text();
    if(name.isEmpty())
        QMessageBox::warning(this,"Erro","O campo 'nome' e de preenchimento obrigatorio.",QMessageBox::Ok);
    else
    {
        if(verticesBspline.size()>=4)
        {
            Controller::getInstance()->addBsplineCurve(&name, verticesBspline);

            //Limpa tabela e vertices
            verticesBspline.clear();
            this->ui->tableWidgetBspline_2->clear();
            for(int i =countBs;i >= 0;i--)
            {
                this->ui->tableWidgetBspline_2->removeRow(i);
            }
            countBs = 0;
            this->close();
        }
        else{
             QMessageBox::warning(this,"Erro","Deve-se ter no mnimo 4 coordenadas.",QMessageBox::Ok);

        }

    }
}

void AddObjects::on_pushButtonAddCoordBspline_2_clicked()
{
    verticesBspline.append(new Coordinate(this->ui->SpinBoxBsplineX_2->value(),this->ui->SpinBoxBsplineY_2->value()));
    this->ui->tableWidgetBspline_2->insertRow(countBs);

    //Coloca as coordenadas na tabela
    this->ui->tableWidgetBspline_2->setItem(countBs,0,new QTableWidgetItem(QString::number(this->ui->SpinBoxBsplineX_2->value())));
    this->ui->tableWidgetBspline_2->setItem(countBs,1,new QTableWidgetItem(QString::number(this->ui->SpinBoxBsplineY_2->value())));
    countBs++;

}

void AddObjects::on_pushButtonDeleteRowBspline_2_clicked()
{
    this->ui->tableWidgetBspline_2->removeRow(this->ui->tableWidgetBspline_2->currentRow());
    verticesBspline.removeAt(this->ui->tableWidgetBspline_2->currentRow()-1);
    countBs--;
}

void AddObjects::on_pushButtonCancel_9_clicked()
{
    this->close();
}
