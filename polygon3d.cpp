 #include "polygon3d.h"

Polygon3D::Polygon3D(QString *name, QList<Face*> faces) : Shape3D(POLYGON3D)
{
    this->name = name;
    this->faces = faces;

    foreach(Face* f, this->faces){
        foreach(Coordinate3D* c, f->getCoordinates()){
            if(this->coords.indexOf(c) == -1)
                this->coords.append(c);
        }
    }

    this->filled = false;
}

QList<Coordinate3D*> Polygon3D::getCoordinates()
{    
    return this->coords;
}

Polygon3D* Polygon3D::clone()
{
    QList<Face*> facesClone;
    QHash<Coordinate3D*,Coordinate3D*> coordHash;
    foreach(Face* f, this->faces)
    {
        Face* faceClone = new Face();
        faceClone->setColor(f->getColor());
        foreach(Coordinate3D* c, f->getCoordinates())
        {
            Coordinate3D* a =  coordHash.value(c, 0);
            if(a == 0){
                a = c->clone();
                coordHash.insert(c, a);
            }
            faceClone->appendCoordinate(a);
        }
        facesClone.append(faceClone);
    }

    Polygon3D* p = new Polygon3D(this->name, facesClone);
    p->setFilled(this->filled);
    return p;
}

bool Polygon3D::getFilled()
{
    return this->filled;
}

void Polygon3D::setFilled(bool flag)
{
    this->filled = flag;
}

QList<Face*> Polygon3D::getFaces()
{
    return this->faces;
}

QList<GeometricShape*> Polygon3D::convertTo2D()
{
    QList<GeometricShape*> gShapes;
    GeometricShapeFactory* gsFactory = GeometricShapeFactory::getInstance();
    foreach(Face* f, this->faces)
    {
        QList<Coordinate*> coords;
        foreach(Coordinate3D* c, f->getCoordinates())
        {
            coords << new Coordinate(c->getX(), c->getY());
        }
        Polygon *p = gsFactory->createPolygon(this->getName(), coords, f->getColor());
        p->setFill(this->filled);
        gShapes.append(p);
    }
    return gShapes;
}
