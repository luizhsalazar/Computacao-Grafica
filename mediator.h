#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <QList>
#include <mainwindow.h>
#include <window.h>
#include <transform.h>
#include <geometricshape.h>
#include <displayfile.h>
#include <geometricshapefactory.h>
#include <coordinate.h>
using namespace std;

class Mediator
{
private:    
    //Variables    
    MainWindow *mainWindow;
    Window* window;
    DisplayFile *displayFile;

    //Methods
    Mediator();
    void addGeometricShapeToDisplayFile(GeometricShape*);

public:
    ~Mediator();

    QList<GeometricShape*> getGeometricShapes();
    QList<GeometricShape*> getCppGeometricShapes();

    static Mediator* getInstance();
    static Mediator* init();

    void addLine(QString*, double, double, double, double, QColor);
    void addPolygon(QString*, QList<Coordinate*>, bool);
//    void addBezierCurve(QString*, QList<Coordinate*>, QColor);
//    void addBsplineCurve(QString*, QList<Coordinate*>, QColor);
    void addPoint(QString*, double, double, QColor);

    void deleteGeometricShape(int);

//    void moveObject(int,double,double);
//    void resizeObject(int,double,double);
//    void rotateObject(int,int, rotateType);
//    void rotateObject(int,int,double,double);

    void zoomInWindow(int);
    void zoomOutWindow(int);
    void moveWindowVertical(int);
    void moveWindowHorizontal(int);
//    void rotateWindow(double);

    void redraw();
};

#endif // MEDIATOR_H
