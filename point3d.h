 #ifndef POINT3D_H
#define POINT3D_H

#include <shape3d.h>

class Point3D: public Shape3D
{
private:
    Coordinate3D *coord;

public:
    Point3D(QString*, Coordinate3D*);
    Coordinate3D* getCoordinate();
    QList<Coordinate3D*> getCoordinates();
    Point3D* clone();
    float getX();
    float getY();
    float getZ();
    QList<GeometricShape*> convertTo2D();

};

#endif // POINT3D_H
