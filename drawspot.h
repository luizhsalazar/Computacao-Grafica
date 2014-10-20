 #ifndef DRAWSPOT_H
#define DRAWSPOT_H

#include <QGraphicsView>
#include <QMouseEvent>

class DrawSpot : public QGraphicsView
{
private:
    float mx;
    float my;
public:
    DrawSpot(QWidget*);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
};

#endif // DRAWSPOT_H
