#include "polygon.h"

Polygon::Polygon(QString* name, QList<Coordinate*> vertices) : GeometricShape(POLYGON)
{
    this->vertices = vertices;
    this->name = name;
    this->fill = false;
}

QList<Coordinate*> Polygon::getCoordinates()
{
    return this->vertices;
}

void Polygon::addVertex(Coordinate* vertex)
{
    this->vertices.append(vertex);
}

Polygon* Polygon::clone()
{
    QList<Coordinate*> vertices;

    foreach(Coordinate* v, this->vertices)
    {
        vertices << new Coordinate(v->getXAxisCoord(), v->getYAxisCoord());
    }

    Polygon* p = new Polygon(this->name, vertices);
    p->setStrokeColor(this->getStrokeColor());

    return p;
}
