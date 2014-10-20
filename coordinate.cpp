 #include "coordinate.h"

Coordinate::Coordinate(double x, double y)
{
    this->xAxisCoord = x;
    this->yAxisCoord = y;
}

double Coordinate::getXAxisCoord()
{
    return this->xAxisCoord;
}

double Coordinate::getYAxisCoord()
{
    return this->yAxisCoord;
}

void Coordinate::setXAxisCoord(double x)
{
    this->xAxisCoord = x;
}

void Coordinate::setYAxisCoord(double y)
{
    this->yAxisCoord = y;
}

void Coordinate::show()
{
    qWarning("x = %f - y = %f", xAxisCoord, yAxisCoord);
}
