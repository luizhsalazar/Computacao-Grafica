#ifndef BSPLINE_H
#define BSPLINE_H

#include <geometricshape.h>

class Bspline : public GeometricShape
{

private:
    QList<Coordinate*> coordinates;

public:
    Bspline(QString*, QList<Coordinate*>);
    QList<Coordinate*> getCoordinates();
    QList<Coordinate*> generateCurveCoordinates();
    Bspline* clone();
};

#endif // BSPLINE_H
