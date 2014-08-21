#ifndef POLYGON_H
#define POLYGON_H

#include <QList>
#include <coordinate.h>
#include <geometricshape.h>

class Polygon : public GeometricShape
{
private:
    QList<Coordinate*> vertices;    
    bool fill;

public:
    Polygon(QString*, QList<Coordinate*>);
    QList<Coordinate*> getCoordinates();
    void addVertex(Coordinate*);
    Polygon* clone();

    void setFill(bool);
    bool isFilled();

};

#endif // POLYGON_H
