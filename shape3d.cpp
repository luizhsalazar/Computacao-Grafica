 #include "shape3d.h"

Shape3D::Shape3D(SHAPE_3D_TYPE type)
{
    this->type = type;
}

SHAPE_3D_TYPE Shape3D::getType()
{
    return this->type;
}

Shape3D* Shape3D::clone()
{
    return NULL;
}

QList<GeometricShape*> Shape3D::convertTo2D()
{
    QList<GeometricShape*> gsList;
    return gsList;
}

QList<Coordinate3D*> Shape3D::getCoordinates()
{

}

QString* Shape3D::getName()
{
    return this->name;
}

void Shape3D::setName(QString *name)
{
    this->name = name;
}

void Shape3D::calcCpp(float angle, float rx, float ry)
{

}

QColor Shape3D::getStrokeColor()
{
    return this->strokeColor;
}

void Shape3D::setStrokeColor(QColor strokeColor)
{
    this->strokeColor = strokeColor;
}

Coordinate3D* Shape3D::calcCenter()
{
    QList<Coordinate3D*> coords = this->getCoordinates();

    int count = coords.count();

    float x = 0;
    float y = 0;
    float z = 0;

    foreach(Coordinate3D* c, coords){
        x += c->getX();
        y += c->getY();
        z += c->getZ();
    }

    x = x/count;
    y = y/count;
    z = z/count;

    return new Coordinate3D(x,y,z);
}
