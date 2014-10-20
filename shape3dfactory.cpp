 #include "shape3dfactory.h"

static Shape3DFactory* instance = 0;

Shape3DFactory::Shape3DFactory()
{
}

Shape3DFactory* Shape3DFactory::getInstance(){
    if(instance == 0)
        instance = new Shape3DFactory();
    return instance;
}

Point3D* Shape3DFactory::createPoint3D(QString *name, float x, float y, float z, QColor strokeColor)
{
    Coordinate3D *a = new Coordinate3D(x,y,z);
    Point3D *p = new Point3D(name, a);
    p->setStrokeColor(strokeColor);
    return p;
}

Line3D* Shape3DFactory::createLine3D(QString *name, Coordinate3D* a, Coordinate3D* b, QColor strokeColor)
{
    Line3D* l = new Line3D(name, a, b);
    l->setStrokeColor(strokeColor);
    return l;
}

Polygon3D* Shape3DFactory::createPolygon3D(QString *name, QList<Face*> faces)
{
    Polygon3D *p = new Polygon3D(name, faces);
    return p;
}
