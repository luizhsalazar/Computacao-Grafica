#ifndef LINE_H
#define LINE_H

#include <geometricshape.h>
#include <coordinate.h>

class Line: public GeometricShape
{
private:
    Coordinate* coordA;
    Coordinate* coordB;

public:
    Line(Coordinate*, Coordinate*);
    Line(QString*, Coordinate*, Coordinate*);
    Coordinate* getCoordA();
    Coordinate* getCoordB();
    void setCoordA(Coordinate*);
    void setCoordB(Coordinate*);
    QList<Coordinate*> getCoordinates();
    Line* clone();
};

#endif // LINE_H
