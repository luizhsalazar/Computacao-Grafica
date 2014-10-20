#include <QtWidgets>
#include <controller.h>
#include <test.h>

bool fillPolygon;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Controller::init();

    return a.exec();
}
