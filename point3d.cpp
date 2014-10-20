 #include "point3d.h"

Point3D::Point3D(QString *name, Coordinate3D *coord) : Shape3D(POINT3D)
{
    this->name = name;
    this->coord = coord;
}

Coordinate3D* Point3D::getCoordinate()
{
    return this->coord;
}

QList<Coordinate3D*> Point3D::getCoordinates()
{
    QList<Coordinate3D*> coordList;
    coordList << this->coord;
    return coordList;
}

Point3D* Point3D::clone()
{
    Coordinate3D* a = this->coord->clone();
    Point3D *p = new Point3D(this->name, a);
    p->setStrokeColor(this->strokeColor);
    return p;
}

float Point3D::getX()
{
    return this->coord->getX();
}

float Point3D::getY()
{
    return this->coord->getY();
}

float Point3D::getZ()
{
    return this->coord->getZ();
}

QList<GeometricShape*> Point3D::convertTo2D()
{
    QList<GeometricShape*> gsList;
    gsList << GeometricShapeFactory::getInstance()
            ->createPoint(this->getName(), this->getX(),
                          this->getY(), this->getStrokeColor());
    return gsList;
}
