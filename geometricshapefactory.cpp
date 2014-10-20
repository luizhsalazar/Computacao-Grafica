#include "geometricshapefactory.h"

static GeometricShapeFactory *instance = 0;

GeometricShapeFactory::GeometricShapeFactory()
{

}

GeometricShapeFactory* GeometricShapeFactory::getInstance(){
    if(instance == 0)
        instance = new GeometricShapeFactory();
    return instance;
}

Line* GeometricShapeFactory::createLine(QString* name, double ax, double ay, double bx, double by, QColor strokeColor)
{
    Line* line = new Line(name, new Coordinate(ax, ay), new Coordinate(bx, by));
    line->setStrokeColor(strokeColor);
    return line;
}

Line* GeometricShapeFactory::createLine(Coordinate* coordA, Coordinate* coordB, QColor strokeColor)
{
    Line* line = new Line(coordA, coordB);
    line->setStrokeColor(strokeColor);
    return line;
}

Line* GeometricShapeFactory::createLine(Coordinate* coordA, Coordinate* coordB)
{
    return new Line(coordA, coordB);
}

Point* GeometricShapeFactory::createPoint(QString* name, double ax, double ay, QColor strokeColor)
{
    Point* point = new Point(name, new Coordinate(ax, ay));
    point->setStrokeColor(strokeColor);
    return point;
}

Polygon* GeometricShapeFactory::createPolygon(QString* name, QList<Coordinate*> vertices)
{
    Polygon* polygon = new Polygon(name, vertices);
    return polygon;
}

Bezier* GeometricShapeFactory::createBezierCurve(QString* name, QList<Coordinate*> coordinates)
{
    Bezier* curve = new Bezier(name, coordinates);

    return curve;
}

Bspline* GeometricShapeFactory::createBsplineCurve(QString * name, QList<Coordinate *> coordinates)
{
    Bspline* cspline = new Bspline(name,coordinates);


    return cspline;
}
