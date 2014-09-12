#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <line.h>
#include <point.h>
#include <polygon.h>
#include <geometricshape.h>
#include <geometricshapefactory.h>

class Viewport
{
private:
    QGraphicsView* drawWindow;
    QGraphicsScene* currentScene;

    double xwmax, ywmax, xwmin, ywmin, r_min, r_max, r_max2, xvpmax, yvpmax;

    void drawLine(Line*);
    void drawPoint(Point*);
    void drawPolygon(Polygon*);

public:
    Viewport(double, QGraphicsView*);

    void prepareToRedraw(double, double, double, double);

    void drawGeometricShape(GeometricShape*);
    Coordinate* transformCoordinate(Coordinate*);

    void updateScene();
};

#endif // VIEWPORT_H
