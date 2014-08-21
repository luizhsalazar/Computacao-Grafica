#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate
{
private:
    double xAxisCoord;
    double yAxisCoord;

public:
    Coordinate(double, double);
    double getXAxisCoord();
    double getYAxisCoord();
    void setXAxisCoord(double);
    void setYAxisCoord(double);
};

#endif // COORDINATE_H
