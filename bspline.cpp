#include "bspline.h"
#include "transform.h"

Bspline::Bspline(QString* name, QList<Coordinate*> coordinates) : GeometricShape(BSPLINE)
{
    this->name = name;
    this->coordinates = coordinates;
}

QList<Coordinate*> Bspline::getCoordinates()
{
    return this->coordinates;
}

Bspline* Bspline::clone()
{
    QList<Coordinate*> coordinates;

    foreach(Coordinate* c, this->coordinates)
    {
        coordinates << new Coordinate(c->getXAxisCoord(), c->getYAxisCoord());
    }

    Bspline* curve = new Bspline(this->name, coordinates);
    curve->setStrokeColor(this->getStrokeColor());

    return curve;
}


QList<Coordinate*> Bspline::generateCurveCoordinates()
{
    double acurracy = 0.01;
    QList<Coordinate*> bsp;
    double mbs[4][4] = {{-1.0/6,  1.0/2,   -1.0/2, 1.0/6},
                        { 1.0/2,    -1,     1.0/2, 0},
                        {-1.0/2,     0,     1.0/2, 0},
                        { 1.0/6,    4.0/6,  1.0/6, 0}};

    double f0[2], deltaF0[2], delta2F0[2], delta3F0[2];
    double t2 = acurracy * acurracy;
    double t3 = acurracy*t2;

    double matrixCoef[4][2];
    for(int i =0; i<coordinates.size()-3; i++)
    {
        for (int z = 0; z < 4; z++) {
            matrixCoef[z][0] = coordinates.value(z+i)->getXAxisCoord();
            matrixCoef[z][1] = coordinates.value(z+i)->getYAxisCoord();
        }
        double coef[4][2];

        Transform::getInstance()->MatMultMat42(mbs,matrixCoef, coef);

        for(int j = 0; j < 2; j++)
        {
            f0[j] = coef[3][j];
            deltaF0[j]  = (coef[0][j]*t3) + (coef[1][j]*t2) + (coef[2][j]*acurracy);
            delta2F0[j] = (6*coef[0][j]*t3) + (2*coef[1][j]*t2);
            delta3F0[j] = (6*coef[0][j]*t3);
        }

        for(double p = 0; p<=1; p+= acurracy)
        {
            Coordinate* b = new Coordinate(f0[0],f0[1]);
            bsp.append(b);
            f0[0] += deltaF0[0]; deltaF0[0] += delta2F0[0]; delta2F0[0] += delta3F0[0];
            f0[1] += deltaF0[1]; deltaF0[1] += delta2F0[1]; delta2F0[1] += delta3F0[1];
        }
    }
    return bsp;

}
