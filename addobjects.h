#ifndef ADDOBJECTS_H
#define ADDOBJECTS_H

#include <QDialog>
#include <QColorDialog>
#include <coordinate3d.h>

namespace Ui {
    class AddObjects;
}

class AddObjects : public QDialog
{
    Q_OBJECT

public:
    explicit AddObjects(QWidget *parent = 0);
    ~AddObjects();

private:
    Ui::AddObjects *ui;
    int count,countBs;
    QColorDialog *qColorDialog;
    QColor qcolor;
    void populateEdgeCombos();

private slots:


private slots:
    void on_deleteEdgePol_clicked();
    void on_addEdgePol_clicked();
    void on_pushButtonPolygon_clicked();
    void on_deleteCoordPol_clicked();
    void on_addCoordPol_clicked();
    void on_pushButtonLine_clicked();
    void on_pushButtonPoint_clicked();
    void on_selectColorButton_clicked();
    void on_addObjectCancel_clicked();
};

#endif // ADDOBJECTS_H
