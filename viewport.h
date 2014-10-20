 #ifndef VIEWPORT_H
#define VIEWPORT_H

#include <QGraphicsView>
#include <QGraphicsScene>

#include <line.h>
#include <point.h>
#include <polygon.h>
#include <geometricshapefactory.h>

#include <point3d.h>
#include <shape3dfactory.h>

#define OutCode int

const int INSIDE = 0; // 0000
const int LEFT   = 1;   // 0001
const int RIGHT  = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP    = 8;    // 1000

class Viewport
{
private:
    QGraphicsView* drawWindow;
    QGraphicsScene* currentScene;

    double xwmax, ywmax, xwmin, ywmin, r_min, r_max, r_max2, xvpmax, yvpmax;

    void drawLine(Line*);
    void drawPoint(Point*);
    void drawPolygon(Polygon*);
    void drawBezierCurve(Bezier*);
    void drawBsplineCurve(Bspline*);
    bool insideClipEdge(Coordinate*, OutCode);

public:
    Viewport(double, QGraphicsView*);

    void prepareToRedraw(double, double, double, double);

    void drawGeometricShape(GeometricShape*);
    void drawGeometricShape(QList<GeometricShape*>);

    Coordinate* transformCoordinate(Coordinate*);

    OutCode computeOutCode(double, double);

    void updateScene();


};

#endif // VIEWPORT_H
