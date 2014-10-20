 #ifndef FACE_H
#define FACE_H

#include <coordinate3d.h>
#include <QList>
#include <QColor>

class Face
{
private:
    QList<Coordinate3D*> coords;
    QColor color;

public:
    Face();
    Face(QList<Coordinate3D*>, QColor);
    Face(QList<Coordinate3D*>);
    void appendCoordinate(Coordinate3D*);
    void setColor(QColor);
    QColor getColor();
    QList<Coordinate3D*> getCoordinates();
};

#endif // FACE_H
