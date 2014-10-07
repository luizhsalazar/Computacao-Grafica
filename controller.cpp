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

void Controller::deleteGeometricShape(int index)
{
    this->displayFile->deleteGeometricShape(index);
    this->redraw();
}


void Controller::addGeometricShapeToDisplayFile(GeometricShape* geometricShape)
{
    this->displayFile->addGeometricShape(geometricShape, this->window->getAngle(), this->window->getCenter());
    this->mainWindow->addObjectName(geometricShape->getName()->toStdString().data());
}

void Controller::addLine(QString* name, double ax, double ay, double bx, double by, QColor strokeColor)
{
    Line* line = GeometricShapeFactory::getInstance()->createLine(name, ax, ay, bx, by, strokeColor);
    this->addGeometricShapeToDisplayFile(line);
    this->redraw();
}

void Controller::addPoint(QString* name, double ax, double ay, QColor strokeColor)
{
    Point* point = GeometricShapeFactory::getInstance()->createPoint(name, ax, ay, strokeColor);
    this->addGeometricShapeToDisplayFile(point);
    this->redraw();
}

void Controller::addPolygon(QString* name, QList<Coordinate*> vertices, bool isFilled)
{
    Polygon* polygon = GeometricShapeFactory::getInstance()->createPolygon(name, vertices);
    this->addGeometricShapeToDisplayFile(polygon);

    this->redraw();
}

void Controller::redraw()
{
    this->window->redraw(this->getGeometricShapes());
}

QList<GeometricShape*> Controller::getGeometricShapes()
{
    return this->displayFile->getGeometricShapes();
}

QList<GeometricShape*> Controller::getCppGeometricShapes()
{
    return this->displayFile->getCppGeometricShapes();
}

void Controller::zoomInWindow(int percent)
{
    this->window->zoomIn(percent);
}

void Controller::zoomOutWindow(int percent)
{
    this->window->zoomOut(percent);
}

void Controller::moveWindowVertical(int u)
{
    this->window->move(u, VERTICAL);
}

void Controller::moveWindowHorizontal(int u)
{
    this->window->move(u, HORIZONTAL);
}

void Controller::resizeObject(int index, double sX, double sY)
{
    QList<GeometricShape*> geometricShapeList = this->getGeometricShapes();

    GeometricShape* gs = geometricShapeList.at(index);

    if(gs != NULL)
    {
        Transform::getInstance()->scaleGeometricShape(gs,sX,sY);
        this->redraw();
    }

}

void Controller::rotateObject(int index,int angle, rotateType type)
{
    QList<GeometricShape*> geometricShapeList = this->getGeometricShapes();

    GeometricShape* gs = geometricShapeList.at(index);

    Transform* transform = Transform::getInstance();
    transform->setType(type);

    if(gs != NULL)
    {
        transform->rotateGeometricShape(gs,angle);
        this->redraw();
    }

}

void Controller::rotateObject(int index,int angle,double rX, double rY)
{
    QList<GeometricShape*> geometricShapeList = this->getGeometricShapes();

    GeometricShape* gs = geometricShapeList.at(index);

    if(gs != NULL)
    {
        Transform::getInstance()->rotateGeometricShape(gs,angle,rX,rY);
        this->redraw();
    }
}

void Controller::moveObject(int index, double dx, double dy)
{
    QList<GeometricShape*> geometricShapeList = this->getGeometricShapes();

    GeometricShape* gs = geometricShapeList.at(index);

    if(gs != NULL)
    {
        Transform::getInstance()->translateGeometricShape(gs, dx, dy);
        this->redraw();
    }

}

void Controller::rotateWindow(double angle)
{
    this->window->rotate(angle);
}

void Controller::addBezierCurve(QString* name, QList<Coordinate*> coordinates)
{
    Bezier* curve = GeometricShapeFactory::getInstance()->createBezierCurve(name, coordinates);
    this->addGeometricShapeToDisplayFile(curve);
    this->redraw();
}

void Controller::addBsplineCurve(QString* name, QList<Coordinate *> coordinates)
{
    Bspline* cspline = GeometricShapeFactory::getInstance()->createBsplineCurve(name,coordinates);
    this->addGeometricShapeToDisplayFile(cspline);
    this->redraw();
}
