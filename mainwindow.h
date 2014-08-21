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
};

#endif // MAINWINDOW_H
