 #include "point.h"

Point::Point(QString* name, Coordinate* coordinate) : GeometricShape(POINT)
{
    this->coordinate = coordinate;
    this->name = name;
}

Coordinate* Point::getCoordinate()
{
    return this->coordinate;
}

QList<Coordinate*> Point::getCoordinates()
{
    QList<Coordinate*> coordinates;
    coordinates << this->coordinate;
    return coordinates;
}

Point* Point::clone()
{
    Coordinate* coord = new Coordinate(this->coordinate->getXAxisCoord(), this->coordinate->getYAxisCoord());
    Point* p = new Point(this->name, coord);
    p->setStrokeColor(this->getStrokeColor());
    return p;
}
