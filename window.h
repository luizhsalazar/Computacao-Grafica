 #ifndef WINDOW_H
#define WINDOW_H

#include <QGraphicsView>
#include <geometricshape.h>
#include <shape3d.h>
#include <viewport.h>
#include <transform.h>

enum mov_dir{
    HORIZONTAL, VERTICAL
};

class Window
{
private:
    QGraphicsView* drawWindow;
    Viewport* viewport;

    double xwmin, ywmin, xwmax, ywmax;

    Coordinate3D *vrp;
    Coordinate3D *vpn;
    Coordinate3D *vup;

    float width;
    float height;

    void draw3DShapes(QList<Shape3D*>);
    void setupRedraw();

public:
    Window(QGraphicsView*);
    void reset();
    void redraw(QList<Shape3D*>);
    void redraw2D(QList<GeometricShape*> objectsToDraw);
    void zoom(float);
    void move(float, axis);
    void rotate(float, axis axis);
    Coordinate3D* getCenter();
    float* getCenter2D();
    float getAngle();
};

#endif // WINDOW_H
