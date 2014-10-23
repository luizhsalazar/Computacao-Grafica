#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QList>
#include <mainwindow.h>
#include <window.h>
#include <transform.h>
#include <displayfile.h>

#include <face.h>
#include <shape3d.h>
#include <shape3dfactory.h>
#include <objparser.h>

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
    void addShape3DToDisplayFile(Shape3D*);

public:
    ~Controller();

    QList<Shape3D*> getShapes3D();
    QList<Shape3D*> getCppShapes3D();

    QList<GeometricShape*> getGeometricShapes();
    QList<GeometricShape*> getCppGeometricShapes();

    static Controller* getInstance();
    static Controller* init();

    void resetWindow();

    void addPoint3D(QString*, float, float, float, QColor);
    void addLine3D(QString*, float, float, float, float, float, float, QColor);
    void addPolygon3D(QString*, QList<Face*>, bool);
    void addPolygon3D(Polygon3D*);

    void addBezierCurve(QString*, QList<Coordinate*>, QColor);
    void addBsplineCurve(QString*, QList<Coordinate*>, QColor);
    void addGeometricShapeToDisplayFile(GeometricShape* geometricShape);

    void deleteShape3D(int);

    void moveObject(int, float, float, float);
    void resizeObject(int, float, float, float);
    void rotateObject(int,int, axis, rotationType);
    void rotateObject(int,int,float,float,float, axis);

    void zoomWindow(float);
    void moveWindow(float, axis);
    void rotateWindow(float, axis);

    Coordinate3D* getAxisVector(axis);

    void setProjectionType(projectionType);

    void loadObjFile(char*);

    void redraw();
    void redraw2D();
};

#endif // CONTROLLER_H
