 #ifndef POLYGON3D_H
#define POLYGON3D_H

#include <shape3d.h>
#include <QHash>
#include <face.h>

class Polygon3D : public Shape3D
{
private:
    QList<Face*> faces;
    QList<Coordinate3D*> coords;
    bool filled;

public:
    Polygon3D(QString*, QList<Face*>);
    QList<Coordinate3D*> getCoordinates();
    Polygon3D* clone();
    bool getFilled();
    void setFilled(bool);
    QList<GeometricShape*> convertTo2D();
    QList<Face*> getFaces();

};

#endif // POLYGON3D_H
