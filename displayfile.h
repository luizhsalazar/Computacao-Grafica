 #ifndef DISPLAYFILE_H
#define DISPLAYFILE_H

#include <geometricshape.h>
#include <shape3d.h>

class DisplayFile
{
private:
    QList<Shape3D*> shapes3D;
    QList<Shape3D*> cppShapes3D;

    QList<GeometricShape*> geometricShapes;
    QList<GeometricShape*> cppGeometricShapes;

public:
    DisplayFile();
    void addShape3D(Shape3D*);
    void deleteShape3D(int);
    void addGeometricShape(GeometricShape*, float, float*);
    QList<Shape3D*> getShapes3D();
    QList<Shape3D*> getCppShapes3D();

    QList<GeometricShape*> getGeometricShapes();
    QList<GeometricShape*> getCppGeometricShapes();
};

#endif // DISPLAYFILE_H

