#include "line.h"

Line::Line(Coordinate* coordA, Coordinate* coordB) : GeometricShape(LINE)
{
    this->coordA = coordA;
    this->coordB = coordB;
}

Line::Line(QString* name, Coordinate* coordA, Coordinate* coordB) : GeometricShape(LINE)
{
    this->coordA = coordA;
    this->coordB = coordB;
    this->name = name;
}

Coordinate* Line::getCoordA(){
    return this->coordA;
}

Coordinate* Line::getCoordB(){
    return this->coordB;
}

void Line::setCoordA(Coordinate* coordA)
{
    this->coordA = coordA;
}

void Line::setCoordB(Coordinate* coordB)
{
    this->coordB = coordB;
}

QList<Coordinate*> Line::getCoordinates()
{
    QList<Coordinate*> coordinates;
    coordinates << this->coordA << this->coordB;
    return coordinates;
}

Line* Line::clone()
{
    Coordinate* coordA = new Coordinate(this->coordA->getXAxisCoord(), this->coordA->getYAxisCoord());
    Coordinate* coordB = new Coordinate(this->coordB->getXAxisCoord(), this->coordB->getYAxisCoord());
    Line* l = new Line(this->name, coordA, coordB);
    l->setStrokeColor(this->getStrokeColor());
    return l;
}
