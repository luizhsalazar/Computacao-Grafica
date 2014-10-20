 #ifndef LINE3D_H
#define LINE3D_H

#include <shape3d.h>

class Line3D : public Shape3D
{
private:
    Coordinate3D* coordA;
    Coordinate3D* coordB;

public:

    Line3D(QString*, Coordinate3D*, Coordinate3D*);
    Line3D(Coordinate3D*, Coordinate3D*);

    Coordinate3D* getCoordA();
    Coordinate3D* getCoordB();
    QList<Coordinate3D*> getCoordinates();
    Line3D* clone();
    QList<GeometricShape*> convertTo2D();
};

#endif // LINE3D_H
