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

    this->ui->tableWidget->horizontalHeader()->show();
    this->ui->tableWidget->verticalHeader()->show();

    this->ui->facesTable->horizontalHeader()->show();
    this->ui->facesTable->verticalHeader()->show();

    this->qcolor = QColor(255,255,255);
    this->qColorDialog = new QColorDialog();
}

AddObjects::~AddObjects()
{
    delete ui;
}

void AddObjects::on_addObjectCancel_clicked()
{
    this->close();
}

void AddObjects::on_selectColorButton_clicked()
{
    this->qcolor = this->qColorDialog->getColor(this->qcolor);
    this->qcolor.toRgb();

    this->ui->red->setValue(this->qcolor.red());
    this->ui->blue->setValue(this->qcolor.blue());
    this->ui->green->setValue(this->qcolor.green());
}

void AddObjects::on_pushButtonPoint_clicked()
{
    QString *name = new QString(this->ui->pointName->text());
    if(name->isEmpty())
        QMessageBox::warning(this,"Erro","O campo 'nome' e de preenchimento obrigatorio.",QMessageBox::Ok);
    else
    {
        Controller::getInstance()->addPoint3D(name, ui->pointX->value(), ui->pointY->value(), ui->pointZ->value(), qcolor);
    }
}

void AddObjects::on_pushButtonLine_clicked()
{
    QString name = this->ui->lineNameLine->text();
    if(name.isEmpty())
        QMessageBox::warning(this,"Erro","O campo 'nome' e de preenchimento obrigatorio.",QMessageBox::Ok);
    else
    {
        Controller::getInstance()->addLine3D(&name, ui->lineX1->value(), ui->lineY1->value(),
                                           ui->lineZ1->value(), ui->lineX2->value(),
                                           ui->lineY2->value(), ui->lineZ2->value(),
                                           this->qcolor);
    }
}

void AddObjects::on_addCoordPol_clicked()
{ 
    this->ui->tableWidget->insertRow(count);

    //Coloca as coordenadas na tabela
    this->ui->tableWidget->setItem(count,0,new QTableWidgetItem(QString::number(this->ui->polygonX->value())));
    this->ui->tableWidget->setItem(count,1,new QTableWidgetItem(QString::number(this->ui->polygonY->value())));
    this->ui->tableWidget->setItem(count,2,new QTableWidgetItem(QString::number(this->ui->polygonZ->value())));
    this->populateEdgeCombos();
    count++;
}

void AddObjects::on_deleteCoordPol_clicked()
{
    this->ui->tableWidget->removeRow(this->ui->tableWidget->currentRow());    
    this->populateEdgeCombos();
    count--;
}

void AddObjects::populateEdgeCombos()
{
    this->ui->facesTable->clear();
    this->ui->faceCombo1->clear();
    this->ui->faceCombo2->clear();
    this->ui->faceCombo3->clear();

    int size = this->ui->tableWidget->rowCount();
    for(int i = 0; i < size; i++)
    {
        char buff[100];
        sprintf(buff, "%d", i+1);
        this->ui->faceCombo1->addItem(buff);
        this->ui->faceCombo2->addItem(buff);
        this->ui->faceCombo3->addItem(buff);
    }
    size = this->ui->facesTable->rowCount();
    for(int i = size; i > 0; i--)
    {
        this->ui->facesTable->removeRow(i-1);
    }
}

void AddObjects::on_addEdgePol_clicked()
{
    int coord1 = ui->faceCombo1->currentIndex();
    if(coord1 > -1)
    {
        int size = ui->facesTable->rowCount();
        int coord2 = ui->faceCombo2->currentIndex();
        int coord3 = ui->faceCombo3->currentIndex();
        ui->facesTable->insertRow(size);
        ui->facesTable->setItem(size,0,new QTableWidgetItem(QString::number(coord1+1)));
        ui->facesTable->setItem(size,1,new QTableWidgetItem(QString::number(coord2+1)));
        ui->facesTable->setItem(size,2,new QTableWidgetItem(QString::number(coord3+1)));
    }
}

void AddObjects::on_deleteEdgePol_clicked()
{
    this->ui->facesTable->removeRow(this->ui->facesTable->currentRow());
}

void AddObjects::on_pushButtonPolygon_clicked()
{
    QString *name = new QString(this->ui->lineNamePolygon->text().toUtf8().data());

    if(name->isEmpty())
        QMessageBox::warning(this,"Erro","O campo nome e de preenchimento obrigatorio.",QMessageBox::Ok);
    else if(this->ui->facesTable->rowCount() == 0){
        QMessageBox::warning(this,"Erro","Nao e possivel criar poligonos 3Ds sem faces.",QMessageBox::Ok);
    } else {
        int size = this->ui->facesTable->rowCount();
        int size1 = this->ui->tableWidget->rowCount();

        QHash<int, Coordinate3D*> coordHash;
        for(int i = 0; i < size1; i++)
        {
            float ax = ui->tableWidget->item(i, 0)->text().toFloat();
            float ay = ui->tableWidget->item(i, 1)->text().toFloat();
            float az = ui->tableWidget->item(i, 2)->text().toFloat();
            coordHash.insert(i, new Coordinate3D(ax, ay, az));
        }

        QList<Face*> polFaces;
        for(int i = 0; i < size; i++)
        {
            QList<Coordinate3D*> faceCoords;

            int a = this->ui->facesTable->item(i,0)->text().toInt()-1;
            int b = this->ui->facesTable->item(i,1)->text().toInt()-1;
            int c = this->ui->facesTable->item(i,2)->text().toInt()-1;

            faceCoords << coordHash.value(a) << coordHash.value(b) << coordHash.value(c);

            polFaces.append(new Face(faceCoords, this->qcolor));
        }

        Controller::getInstance()->addPolygon3D(name, polFaces, this->ui->checkBoxFill->isChecked());
    }
}



