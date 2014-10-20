 #include "line3d.h"

Line3D::Line3D(QString* name, Coordinate3D* a, Coordinate3D* b) : Shape3D(LINE3D)
{
    this->name = name;
    this->coordA = a;
    this->coordB = b;
}

Line3D::Line3D(Coordinate3D* a, Coordinate3D* b) : Shape3D(LINE3D)
{
    this->coordA = a;
    this->coordB = b;
}

Coordinate3D* Line3D::getCoordA()
{
    return this->coordA;
}

Coordinate3D* Line3D::getCoordB()
{
    return this->coordB;
}

QList<Coordinate3D*> Line3D::getCoordinates()
{
    QList<Coordinate3D*> coordList;
    coordList << this->coordA << this->coordB;
    return coordList;
}

Line3D* Line3D::clone()
{
    Coordinate3D* a = this->coordA->clone();
    Coordinate3D* b = this->coordB->clone();

    Line3D *l = new Line3D(this->getName(), a, b);
    l->setStrokeColor(this->strokeColor);

    return l;
}

QList<GeometricShape*> Line3D::convertTo2D()
{
    QList<GeometricShape*> gsList;
    float ax = this->coordA->getX();
    float ay = this->coordA->getY();
    float bx = this->coordB->getX();
    float by = this->coordB->getY();
    gsList << GeometricShapeFactory::getInstance()->createLine(this->name, ax, ay, bx, by, this->strokeColor);
    return gsList;
}
