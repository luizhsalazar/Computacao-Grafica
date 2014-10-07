#ifndef ADDOBJECTS_H
#define ADDOBJECTS_H

#include <QDialog>
#include <QColorDialog>
#include <coordinate.h>

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
    QList<Coordinate*> vertices;
    int count,countBs;
    QColorDialog *qColorDialog;
    QColor qcolor;
    QList<Coordinate*> verticesBspline;

private slots:
    void on_pushButtonCancel_5_clicked();
    void on_pushButtonCancel_4_clicked();
    void on_pushButtonDeleteRow_clicked();
    void on_pushButtonAddCoordPolygon_clicked();
    void on_pushButtonPolygon_clicked();
    void on_pushButtonLine_clicked();
    void on_pushButtonPoint_clicked();
    void on_pushButtonCancel_clicked();
    void on_pushButtonCancel_2_clicked();
    void on_pushButtonCancel_3_clicked();

    void on_pushButtonBezier_clicked();

    void on_pushButtonBspline_2_clicked();
    void on_pushButtonAddCoordBspline_2_clicked();
    void on_pushButtonDeleteRowBspline_2_clicked();
    void on_pushButtonCancel_9_clicked();
};

#endif // ADDOBJECTS_H
