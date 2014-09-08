#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QList>
#include <mainwindow.h>
#include <window.h>
#include <transform.h>
#include <geometricshape.h>
#include <displayfile.h>
#include <geometricshapefactory.h>
#include <coordinate.h>
using namespace std;

class Controller
{
private:    
    //Variables    
    MainWindow *mainWindow;
    Window* window;
    DisplayFile *displayFile;

    //Methods
    Controller();
    void addGeometricShapeToDisplayFile(GeometricShape*);

public:
    ~Controller();

    QList<GeometricShape*> getGeometricShapes();
    QList<GeometricShape*> getCppGeometricShapes();

    static Controller* getInstance();
    static Controller* init();

    void addLine(QString*, double, double, double, double, QColor);
    void addPolygon(QString*, QList<Coordinate*>, bool);
    void addPoint(QString*, double, double, QColor);

    void deleteGeometricShape(int);

    void resizeObject(int,double,double);
    void rotateObject(int,int, rotateType);
    void rotateObject(int,int,double,double);
    void moveObject(int,double,double);

    void zoomInWindow(int);
    void zoomOutWindow(int);
    void moveWindowVertical(int);
    void moveWindowHorizontal(int);
    void rotateWindow(double);

    void redraw();
};

#endif // CONTROLLER_H
