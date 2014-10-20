 #include "bezier.h"

Bezier::Bezier(QString* name, QList<Coordinate*> coordinates) : GeometricShape(BEZIER)
{
    this->name = name;
    this->coordinates = coordinates;
}

QList<Coordinate*> Bezier::getCoordinates()
{
    return this->coordinates;
}

Bezier* Bezier::clone()
{
    QList<Coordinate*> coordinates;

    foreach(Coordinate* c, this->coordinates)
    {
        coordinates << new Coordinate(c->getXAxisCoord(), c->getYAxisCoord());
    }

    Bezier* curve = new Bezier(this->name, coordinates);
    curve->setStrokeColor(this->getStrokeColor());

    return curve;
}

QList<Coordinate*> Bezier::generateCurveCoordinates()
{
    QList<Coordinate*> coords;

    if(this->coordinates.count() >= 4){
        float acurracy = 0.01;

        Coordinate* c1 = this->coordinates.at(0);
        Coordinate* c2 = this->coordinates.at(1);
        Coordinate* c3 = this->coordinates.at(2);
        Coordinate* c4 = this->coordinates.at(3);

        for (float t = 0; t <= 1; t += acurracy) {

            double x,y;

            x = (1-t)*(1-t)*(1-t)*c1->getXAxisCoord()
                + 3*t*((1-t)*(1-t))*c2->getXAxisCoord()
                + 3*t*t*(1-t)*c3->getXAxisCoord()
                + t*t*t*c4->getXAxisCoord();

            y = (1-t)*(1-t)*(1-t)*c1->getYAxisCoord()
                + 3*t*((1-t)*(1-t)*c2->getYAxisCoord())
                + 3*t*t*(1-t)*c3->getYAxisCoord()
                + t*t*t*c4->getYAxisCoord();

            coords << new Coordinate(x, y);
        }
    }

    return coords;
}

