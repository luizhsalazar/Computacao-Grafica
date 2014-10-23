#include <QApplication>
#include <QtWidgets>
#include <controller.h>
#include <test.h>
#include <iostream>
#include <QDir>
#include <QFileDialog>


bool fillPolygon;

using std::cout;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Controller::init();

   Test *t = new Test();
   t->run();

    return a.exec();
}
