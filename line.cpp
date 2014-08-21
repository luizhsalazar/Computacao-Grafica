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

Coordinate* Line::computeIntersection(Line* l){
    float x1 = this->coordA->getXAxisCoord();
    float y1 = this->coordA->getYAxisCoord();
    float x2 = this->coordB->getXAxisCoord();
    float y2 = this->coordB->getYAxisCoord();

    float x3 = l->coordA->getXAxisCoord();
    float y3 = l->coordA->getYAxisCoord();
    float x4 = l->coordB->getXAxisCoord();
    float y4 = l->coordB->getYAxisCoord();

    float d = (x1-x2)*(y3-y4) - (y1-y2)*(x3-x4);
    if (d == 0)
        return (Coordinate*) 0;

    float xi = ((x3-x4)*(x1*y2-y1*x2)-(x1-x2)*(x3*y4-y3*x4))/d;
    float yi = ((y3-y4)*(x1*y2-y1*x2)-(y1-y2)*(x3*y4-y3*x4))/d;

    return new Coordinate(xi,yi);
}

Line* Line::clone()
{
    Coordinate* coordA = new Coordinate(this->coordA->getXAxisCoord(), this->coordA->getYAxisCoord());
    Coordinate* coordB = new Coordinate(this->coordB->getXAxisCoord(), this->coordB->getYAxisCoord());
    Line* l = new Line(this->name, coordA, coordB);
    l->setStrokeColor(this->getStrokeColor());
    return l;
}
