#ifndef GEOMETRICSHAPE_H
#define GEOMETRICSHAPE_H

#include <QList>
#include <QString>
#include <coordinate.h>
#include <QColor>
#include <string.h>

enum GeometricShapeType
{
    POINT   = 0,
    LINE    = 1,
    POLYGON = 2,
};

class GeometricShape
{
protected:
    QString* name;
    GeometricShapeType type;
    QColor strokeColor;

public:
    GeometricShape(GeometricShapeType type);
    GeometricShapeType getType();
    QString* getName();
    void setName(QString*);
    void setStrokeColor(QColor);
    QColor getStrokeColor();
    virtual QList<Coordinate*> getCoordinates(); //É sobrescrito em todas classes que herdam esta.
    virtual GeometricShape* clone();
    void calcCpp(double, double, double);

};

#endif // GEOMETRICSHAPE_H
