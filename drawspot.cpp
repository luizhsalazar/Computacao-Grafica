 #include "drawspot.h"
#include "controller.h"

DrawSpot::DrawSpot(QWidget *qw)
{    
    this->setParent(qw);
    this->mx = 0;
    this->my = 0;
}

void DrawSpot::mousePressEvent(QMouseEvent *e){
    if(e->button()==Qt::LeftButton){
        this->setDragMode(QGraphicsView::ScrollHandDrag);
    }
    QGraphicsView::mousePressEvent(e);
}

void DrawSpot::mouseReleaseEvent(QMouseEvent *e){
    this->setDragMode(QGraphicsView::NoDrag);
    QGraphicsView::mousePressEvent(e);
}

void DrawSpot::mouseMoveEvent(QMouseEvent *e)
{
    QPointF pos = mapToScene(e->pos());
    float x = pos.x();
    float y = pos.y();

    int rx = 1;
    int ry = 1;

    Controller *m = Controller::getInstance();

    if(mx != x){
        if(mx < x)
            rx = -1;
        m->rotateWindow(rx, Y_AXIS);
        mx = x;
    }

    if(my != y){
        if(my > y)
            ry = -1;
        m->rotateWindow(ry, X_AXIS);
        my = y;
    }
}
