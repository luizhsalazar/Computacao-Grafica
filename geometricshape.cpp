 #include "geometricshape.h"
#include <transform.h>

GeometricShape::GeometricShape(GeometricShapeType type)
{
    this->type = type;
    this->strokeColor = QColor(255,255,255);
}

GeometricShapeType GeometricShape::getType()
{
    return this->type;
}

QString* GeometricShape::getName()
{
    return this->name;
}

void GeometricShape::setName(QString* name)
{
    this->name = name;
}

void GeometricShape::setStrokeColor(QColor strokeColor)
{
    this->strokeColor = strokeColor;
}

QColor GeometricShape::getStrokeColor()
{
    return this->strokeColor;
}

QList<Coordinate*> GeometricShape::getCoordinates()
{

}

GeometricShape* GeometricShape::clone()
{
    return NULL;
}

void GeometricShape::calcCpp(double angle, double rx, double ry)
{
    Transform* t = Transform::getInstance();
//    t->setType(ORIGIN);
//    t->rotateGeometricShape(this, angle, rx, ry);
}
