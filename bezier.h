 #ifndef BEZIER_H
#define BEZIER_H

#include <geometricshape.h>

class Bezier : public GeometricShape{

private:
    QList<Coordinate*> coordinates;

public:
    Bezier(QString*, QList<Coordinate*>);
    QList<Coordinate*> getCoordinates();
    QList<Coordinate*> generateCurveCoordinates();
    Bezier* clone();

};

#endif // BEZIER_H
