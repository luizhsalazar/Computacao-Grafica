#ifndef GEOMETRICSHAPEFACTORY_H
#define GEOMETRICSHAPEFACTORY_H

#include <QList>
#include <QString>
#include <line.h>
#include <point.h>
#include <polygon.h>
#include <coordinate.h>
#include <QColor>

class GeometricShapeFactory
{
private:
    GeometricShapeFactory();

public:
    static GeometricShapeFactory* getInstance();
    Line* createLine(QString*, double, double, double, double, QColor);
    Line* createLine(Coordinate*, Coordinate*, QColor);
    Line* createLine(Coordinate*, Coordinate*);
    Point* createPoint(QString*, double, double, QColor);
    Polygon* createPolygon(QString*, QList<Coordinate*>);
};

#endif // GEOMETRICSHAPEFACTORY_H
