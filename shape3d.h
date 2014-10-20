 #ifndef SHAPE3D_H
#define SHAPE3D_H

#include <qstring.h>
#include <qcolor.h>
#include <qlist.h>
#include <coordinate3d.h>
#include <geometricshape.h>
#include <geometricshapefactory.h>

enum SHAPE_3D_TYPE
{
    POINT3D   = 0,
    LINE3D    = 1,
    POLYGON3D = 2,
};

class Shape3D
{
protected:
    QString *name;
    SHAPE_3D_TYPE type;
    QColor strokeColor;

public:
    Shape3D(SHAPE_3D_TYPE);
    SHAPE_3D_TYPE getType();

    QString* getName();
    void setName(QString*);

    void setStrokeColor(QColor);
    QColor getStrokeColor();

    virtual QList<Coordinate3D*> getCoordinates();
    virtual Shape3D* clone();    
    virtual QList<GeometricShape*> convertTo2D();

    Coordinate3D* calcCenter();

    void calcCpp(float, float, float);
};

#endif // SHAPE3D_H
