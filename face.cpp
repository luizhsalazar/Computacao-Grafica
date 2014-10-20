 #include "face.h"

Face::Face(QList<Coordinate3D *> coords, QColor color)
{
    this->coords = coords;
    this->color = color;
}

Face::Face(QList<Coordinate3D *> coords)
{
    this->coords = coords;
    this->color = QColor(255,255,255);
}

Face::Face()
{
    this->color = QColor(255,255,255);
}

QList<Coordinate3D*> Face::getCoordinates()
{
    return this->coords;
}

void Face::appendCoordinate(Coordinate3D* c)
{
    this->coords.append(c);
}

void Face::setColor(QColor color){
    this->color = color;
}

QColor Face::getColor()
{
    return this->color;
}
