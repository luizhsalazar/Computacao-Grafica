 #ifndef SHAPE3DFACTORY_H
#define SHAPE3DFACTORY_H

#include <coordinate3d.h>
#include <point3d.h>
#include <line3d.h>
#include <polygon3d.h>

class Shape3DFactory
{
private:
    Shape3DFactory();

public:
    static Shape3DFactory* getInstance();

    Point3D* createPoint3D(QString*, float, float, float, QColor);
    Line3D* createLine3D(QString*, Coordinate3D*, Coordinate3D*, QColor);
    Polygon3D* createPolygon3D(QString*, QList<Face*>);

};

#endif // SHAPE3DFACTORY_H
