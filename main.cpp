#include <QtWidgets>
#include <mediator.h>
#include <test.h>

bool fillPolygon;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Mediator::init();

//    Test *t = new Test();
//    t->run();

    return a.exec();
}
