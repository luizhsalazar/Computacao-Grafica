#include "controller.h"

/**
  SINGLETON CLASS
*/

static Controller* m_instance = 0;

Controller::Controller()
{
    this->mainWindow = new MainWindow;
    this->window =  new Window(mainWindow->getDrawWindow());
    this->displayFile = new DisplayFile;
    mainWindow->show();
}

Controller::~Controller()
{

}

void Controller::setProjectionType(projectionType type)
{
    Transform::getInstance()->setProjectionType(type);
    this->redraw();
}

void Controller::resetWindow()
{
    this->window->reset();
    this->redraw();
}

Controller* Controller::init()
{
    return Controller::getInstance();
}

Controller* Controller::getInstance()
{
    if(m_instance == 0)
        m_instance = new Controller();

    return m_instance;
}

void Controller::deleteShape3D(int index)
{
    this->displayFile->deleteShape3D(index);
    this->redraw();
}

void Controller::redraw()
{
    QList<Shape3D*> s = this->getCppShapes3D();
    this->window->redraw(s);
}

void Controller::redraw2D()
{
    this->window->redraw2D(this->getCppGeometricShapes());
}

QList<Shape3D*> Controller::getShapes3D()
{
    return this->displayFile->getShapes3D();
}

QList<Shape3D*> Controller::getCppShapes3D()
{
    return this->displayFile->getCppShapes3D();
}

void Controller::zoomWindow(float percent)
{
    this->window->zoom(percent);
}

void Controller::moveWindow(float variation, axis axis)
{
    this->window->move(variation, axis);
}


void Controller::moveObject(int index, float tx, float ty, float tz)
{
    QList<Shape3D*> shapeList = this->getShapes3D();
    QList<Shape3D*> cppShapeList = this->getCppShapes3D();

    Shape3D* s = shapeList.at(index);
    Shape3D* cppS = cppShapeList.at(index);

    if(s != NULL)
    {
        Coordinate3D* t = new Coordinate3D(tx,ty,tz);
        Transform::getInstance()->translateShape3D(s,t);
        Transform::getInstance()->translateShape3D(cppS,t);
        this->redraw();
    }
}

void Controller::resizeObject(int index, float sx, float sy, float sz)
{
    QList<Shape3D*> shapeList = this->getShapes3D();
    QList<Shape3D*> cppShapeList = this->getCppShapes3D();

    Shape3D* s = shapeList.at(index);
    Shape3D* cppS = cppShapeList.at(index);

    if(s != NULL)
    {
        Coordinate3D* scaleVector = new Coordinate3D(sx,sy,sz);
        Coordinate3D* anchor = this->window->getCenter();
        Transform::getInstance()->scaleShape3D(s,anchor,scaleVector);
        Transform::getInstance()->scaleShape3D(cppS,anchor,scaleVector);
        this->redraw();
    }
}

void Controller::rotateObject(int index, int angle, axis axis, rotationType type)
{
    QList<Shape3D*> shapeList = this->getShapes3D();
    QList<Shape3D*> cppShapeList = this->getCppShapes3D();

    Shape3D* s = shapeList.at(index);
    Shape3D* cppS = cppShapeList.at(index);

    if(s != NULL)
    {
        Coordinate3D* anchor;
        if(type == ORIGIN)
            anchor = new Coordinate3D();
        else
            anchor = s->calcCenter();

        Transform::getInstance()->rotateShape3D(s, anchor, this->getAxisVector(axis), angle);
        Transform::getInstance()->rotateShape3D(cppS, anchor, this->getAxisVector(axis), angle);
        this->redraw();
    }
}

void Controller::rotateObject(int index, int angle, float rx, float ry, float rz, axis axis)
{
    QList<Shape3D*> shapeList = this->getShapes3D();
    QList<Shape3D*> cppShapeList = this->getCppShapes3D();

    Shape3D* s = shapeList.at(index);
    Shape3D* cppS = cppShapeList.at(index);

    if(s != NULL)
    {
        Coordinate3D* anchor = new Coordinate3D(rx, ry, rz);
        Transform::getInstance()->rotateShape3D(s, anchor, this->getAxisVector(axis), angle);
        Transform::getInstance()->rotateShape3D(cppS, anchor, this->getAxisVector(axis), angle);
        this->redraw();
    }
}

Coordinate3D* Controller::getAxisVector(axis axis)
{
    if(axis == X_AXIS)
        return new Coordinate3D(1,0,0);
    else if(axis == Y_AXIS)
        return new Coordinate3D(0,1,0);
    else
        return new Coordinate3D(0,0,1);
}

void Controller::rotateWindow(float angle, axis axis)
{
    this->window->rotate(angle, axis);
}

void Controller::addShape3DToDisplayFile(Shape3D *s)
{
    this->displayFile->addShape3D(s);
    this->mainWindow->addObjectName(s->getName());
    this->redraw();
}

void Controller::addPoint3D(QString *name, float x, float y, float z, QColor strokeColor)
{
    Shape3DFactory *s = Shape3DFactory::getInstance();
    Point3D* p = s->createPoint3D(name, x, y, z, strokeColor);
    this->addShape3DToDisplayFile(p);
}

void Controller::addLine3D(QString *name, float ax, float ay, float az, float bx, float by, float bz, QColor strokeColor)
{
    Shape3DFactory *s = Shape3DFactory::getInstance();

    Coordinate3D* a = new Coordinate3D(ax, ay, az);
    Coordinate3D* b = new Coordinate3D(bx, by, bz);

    Line3D* l = s->createLine3D(name, a, b, strokeColor);
    this->addShape3DToDisplayFile(l);
}

void Controller::addPolygon3D(QString *name, QList<Face*> faces, bool filled)
{
    Shape3DFactory *s = Shape3DFactory::getInstance();
    Polygon3D* p = s->createPolygon3D(name, faces);
    p->setFilled(filled);
    this->addShape3DToDisplayFile(p);
}

void Controller::addPolygon3D(Polygon3D* p)
{
    this->addShape3DToDisplayFile(p);
}

void Controller::addBezierCurve(QString* name, QList<Coordinate*> coordinates, QColor strokeColor)
{
    Bezier* curve = GeometricShapeFactory::getInstance()->createBezierCurve(name, coordinates, strokeColor);
    this->addGeometricShapeToDisplayFile(curve);
    this->redraw2D();
}

void Controller::addBsplineCurve(QString* name, QList<Coordinate *> coordinates, QColor strokeColor)
{
    Bspline* cspline = GeometricShapeFactory::getInstance()->createBsplineCurve(name,coordinates,strokeColor);
    this->addGeometricShapeToDisplayFile(cspline);
    this->redraw2D();
}

void Controller::addGeometricShapeToDisplayFile(GeometricShape* geometricShape)
{

    this->displayFile->addGeometricShape(geometricShape, 0 , this->window->getCenter2D());
    this->mainWindow->addObjectName(new QString("shape"));
}

QList<GeometricShape*> Controller::getGeometricShapes()
{
    return this->displayFile->getGeometricShapes();
}

QList<GeometricShape*> Controller::getCppGeometricShapes()
{
    return this->displayFile->getCppGeometricShapes();
}
