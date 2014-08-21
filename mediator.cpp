#include "mediator.h"

/**
  SINGLETON CLASS
*/

static Mediator* m_instance = 0;

Mediator::Mediator()
{
    this->mainWindow = new MainWindow;
    this->window =  new Window(mainWindow->getDrawWindow());
    this->displayFile = new DisplayFile;
    mainWindow->show();
}

Mediator::~Mediator()
{

}

Mediator* Mediator::init()
{
    return Mediator::getInstance();
}

Mediator* Mediator::getInstance()
{
    if(m_instance == 0)
        m_instance = new Mediator();

    return m_instance;
}

void Mediator::deleteGeometricShape(int index)
{
    this->displayFile->deleteGeometricShape(index);
    this->redraw();
}


void Mediator::addGeometricShapeToDisplayFile(GeometricShape* geometricShape)
{
    this->displayFile->addGeometricShape(geometricShape, this->window->getAngle(), this->window->getCenter());
    this->mainWindow->addObjectName(geometricShape->getName()->toStdString().data());
}

void Mediator::addLine(QString* name, double ax, double ay, double bx, double by, QColor strokeColor)
{
    Line* line = GeometricShapeFactory::getInstance()->createLine(name, ax, ay, bx, by, strokeColor);
    this->addGeometricShapeToDisplayFile(line);
    this->redraw();
}

//void Mediator::addBezierCurve(QString* name, QList<Coordinate*> coordinates, QColor strokeColor)
//{
//    Bezier* curve = GeometricShapeFactory::getInstance()->createBezierCurve(name, coordinates, strokeColor);
//    this->addGeometricShapeToDisplayFile(curve);
//    this->redraw();
//}

//void Mediator::addBsplineCurve(QString* name, QList<Coordinate *> coordinates, QColor strokeColor)
//{
//    Bspline* cspline = GeometricShapeFactory::getInstance()->createBsplineCurve(name,coordinates,strokeColor);
//    this->addGeometricShapeToDisplayFile(cspline);
//    this->redraw();
//}

void Mediator::addPoint(QString* name, double ax, double ay, QColor strokeColor)
{
    Point* point = GeometricShapeFactory::getInstance()->createPoint(name, ax, ay, strokeColor);
    this->addGeometricShapeToDisplayFile(point);
    this->redraw();
}

void Mediator::addPolygon(QString* name, QList<Coordinate*> vertices, bool isFilled)
{
    Polygon* polygon = GeometricShapeFactory::getInstance()->createPolygon(name, vertices);
    polygon->setFill(isFilled);

    this->addGeometricShapeToDisplayFile(polygon);

    this->redraw();
}

void Mediator::redraw()
{
    this->window->redraw(this->getCppGeometricShapes());
}

QList<GeometricShape*> Mediator::getGeometricShapes()
{
    return this->displayFile->getGeometricShapes();
}

QList<GeometricShape*> Mediator::getCppGeometricShapes()
{
    return this->displayFile->getCppGeometricShapes();
}


void Mediator::zoomInWindow(int percent)
{
    this->window->zoomIn(percent);
}

void Mediator::zoomOutWindow(int percent)
{
    this->window->zoomOut(percent);
}

void Mediator::moveWindowVertical(int u)
{
    this->window->move(u, VERTICAL);
}

void Mediator::moveWindowHorizontal(int u)
{
    this->window->move(u, HORIZONTAL);
}


//void Mediator::moveObject(int index, double dx, double dy)
//{
//    QList<GeometricShape*> geometricShapeList = this->getGeometricShapes();
//    QList<GeometricShape*> cppGeometricShapeList = this->getCppGeometricShapes();

//    GeometricShape* gs = geometricShapeList.at(index);
//    GeometricShape* cppGs = cppGeometricShapeList.at(index);

//    if(gs != NULL)
//    {
//        Transform::getInstance()->translateGeometricShape(gs, dx, dy);
//        Transform::getInstance()->translateGeometricShape(cppGs, dx, dy);
//        this->redraw();
//    }

//}

//void Mediator::resizeObject(int index, double sX, double sY)
//{
//    QList<GeometricShape*> geometricShapeList = this->getGeometricShapes();
//    QList<GeometricShape*> cppGeometricShapeList = this->getCppGeometricShapes();

//    GeometricShape* gs = geometricShapeList.at(index);
//    GeometricShape* cppGs = cppGeometricShapeList.at(index);

//    if(gs != NULL)
//    {
//        Transform::getInstance()->scaleGeometricShape(gs,sX,sY);
//        Transform::getInstance()->scaleGeometricShape(cppGs,sX,sY);
//        this->redraw();
//    }

//}

//void Mediator::rotateObject(int index,int angle, rotateType type)
//{
//    QList<GeometricShape*> geometricShapeList = this->getGeometricShapes();
//    QList<GeometricShape*> cppGeometricShapeList = this->getCppGeometricShapes();

//    GeometricShape* gs = geometricShapeList.at(index);
//    GeometricShape* cppGs = cppGeometricShapeList.at(index);

//    Transform* transform = Transform::getInstance();
//    transform->setType(type);

//    if(gs != NULL)
//    {
//        transform->rotateGeometricShape(gs,angle);
//        transform->rotateGeometricShape(cppGs,angle);
//        this->redraw();
//    }

//}

//void Mediator::rotateObject(int index,int angle,double rX, double rY)
//{
//    QList<GeometricShape*> geometricShapeList = this->getGeometricShapes();
//    QList<GeometricShape*> cppGeometricShapeList = this->getCppGeometricShapes();

//    GeometricShape* gs = geometricShapeList.at(index);
//    GeometricShape* cppGs = cppGeometricShapeList.at(index);

//    if(gs != NULL)
//    {
//        Transform::getInstance()->rotateGeometricShape(gs,angle,rX,rY);
//        Transform::getInstance()->rotateGeometricShape(cppGs,angle,rX,rY);
//        this->redraw();
//    }
//}

//void Mediator::rotateWindow(double angle)
//{
//    this->window->rotate(angle);
//}



