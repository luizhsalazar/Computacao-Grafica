#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <addobjects.h>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QGraphicsView* getDrawWindow();
    void addObjectName(const char*);

private:
    Ui::MainWindow *ui;
    AddObjects* addObjectsUi;

private slots:
    void on_buttonMoreZoom_clicked();
    void on_buttonLessZoom_clicked();
    void on_buttonUp_clicked();
    void on_buttonDown_clicked();
    void on_buttonLeft_clicked();
    void on_buttonRight_clicked();
    void on_deleteButton_clicked();

    void on_actionAddObjeto_triggered();
    void on_pushButtonScale_clicked();
    void on_pushButtonRotate_clicked();
    void on_pushButtonMove_clicked();
    void on_buttonLessZoom_2_clicked();
    void on_buttonRotacionarWindowLeft_clicked();
    void on_buttonRotacionarWindowRight_clicked();
    void on_rotateUnity_editingFinished();
};

#endif // MAINWINDOW_H
