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
    void addObjectName(QString*);

private:
    Ui::MainWindow *ui;
    AddObjects* addObjectsUi;
    void rotateWindow(int);

    int currentDialObjectValue;
    int currentDialXValue;
    int currentDialYValue;
    int currentDialZValue;

private slots:


private slots:

    void on_resetWindowButton_clicked();
    void on_radioButton_toggled(bool checked);
    void on_rotateObjDial_dialMoved(int value);
    void on_radioPoint_toggled(bool checked);
    void on_addObjButton_clicked();
    void on_buttonRotate_clicked();
    void on_scaleButton_clicked();
    void on_translateButton_clicked();
    void on_deleteButton_clicked();
    void on_buttonLessZoom_clicked();
    void on_buttonMoreZoom_clicked();
    void on_rotateZ_dialMoved(int value);
    void on_rotateY_dialMoved(int value);
    void on_rotateX_dialMoved(int value);
    void on_rotateWindowLeft_clicked();
    void on_rotateWindowRight_clicked();
    void on_buttonBack_clicked();
    void on_buttonFront_clicked();
    void on_buttonRight_clicked();
    void on_buttonDown_clicked();
    void on_buttonLeft_clicked();
    void on_buttonUp_clicked();
};

#endif // MAINWINDOW_H
