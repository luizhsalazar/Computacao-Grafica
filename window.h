#ifndef WINDOW_H
#define WINDOW_H

#include <QGraphicsView>
#include <geometricshape.h>
#include <viewport.h>

enum mov_dir{
    HORIZONTAL, VERTICAL
};

class Window
{
private:
    QGraphicsView* drawWindow;
    Viewport* viewport;

    double xwmin, ywmin, xwmax, ywmax;

    QList<Coordinate*> vup;

public:
    Window(QGraphicsView*);
    void redraw(QList<GeometricShape*>);
    void zoomIn(int);
    void zoomOut(int);
    void move(int, mov_dir);
//    void rotate(double);
    float* getCenter();
    float getAngle();
};

#endif // WINDOW_H
