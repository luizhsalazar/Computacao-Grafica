#ifndef POINT_H
#define POINT_H

#include <geometricshape.h>
#include <coordinate.h>

class Point: public GeometricShape
{
private:
    Coordinate* coordinate;

public:
    Point(QString*, Coordinate*);
    Coordinate* getCoordinate();
    QList<Coordinate*> getCoordinates();
    Point* clone();
};

#endif // POINT_H
