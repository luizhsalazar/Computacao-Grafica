#include <QApplication>
#include <QtWidgets>
#include <mediator.h>
#include <test.h>
#include <iostream>
#include <QDir>
#include <QFileDialog>
#include "xmlloader.h"

bool fillPolygon;

using std::cout;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Mediator::init();

   Test *t = new Test();
   t->run();

    return a.exec();
}
