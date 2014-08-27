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
    this->displayFile->addGeometricShape(geometricShape);
    this->mainWindow->addObjectName(geometricShape->getName()->toStdString().data());
}

void Mediator::addLine(QString* name, double ax, double ay, double bx, double by, QColor strokeColor)
{
    Line* line = GeometricShapeFactory::getInstance()->createLine(name, ax, ay, bx, by, strokeColor);
    this->addGeometricShapeToDisplayFile(line);
    this->redraw();
}

void Mediator::addPoint(QString* name, double ax, double ay, QColor strokeColor)
{
    Point* point = GeometricShapeFactory::getInstance()->createPoint(name, ax, ay, strokeColor);
    this->addGeometricShapeToDisplayFile(point);
    this->redraw();
}

void Mediator::addPolygon(QString* name, QList<Coordinate*> vertices, bool isFilled)
{
    Polygon* polygon = GeometricShapeFactory::getInstance()->createPolygon(name, vertices);
    this->addGeometricShapeToDisplayFile(polygon);

    this->redraw();
}

void Mediator::redraw()
{
    this->window->redraw(this->getGeometricShapes());
}

QList<GeometricShape*> Mediator::getGeometricShapes()
{
    return this->displayFile->getGeometricShapes();
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

void Mediator::resizeObject(int index, double sX, double sY)
{
    QList<GeometricShape*> geometricShapeList = this->getGeometricShapes();

    GeometricShape* gs = geometricShapeList.at(index);

    if(gs != NULL)
    {
        Transform::getInstance()->scaleGeometricShape(gs,sX,sY);
        this->redraw();
    }

}

void Mediator::rotateObject(int index,int angle, rotateType type)
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

void Mediator::rotateObject(int index,int angle,double rX, double rY)
{
    QList<GeometricShape*> geometricShapeList = this->getGeometricShapes();

    GeometricShape* gs = geometricShapeList.at(index);

    if(gs != NULL)
    {
        Transform::getInstance()->rotateGeometricShape(gs,angle,rX,rY);
        this->redraw();
    }
}

void Mediator::moveObject(int index, double dx, double dy)
{
    QList<GeometricShape*> geometricShapeList = this->getGeometricShapes();

    GeometricShape* gs = geometricShapeList.at(index);

    if(gs != NULL)
    {
        Transform::getInstance()->translateGeometricShape(gs, dx, dy);
        this->redraw();
    }

}
