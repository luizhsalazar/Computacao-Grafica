#ifndef DISPLAYFILE_H
#define DISPLAYFILE_H

#include <geometricshape.h>

class DisplayFile
{
private:
    QList<GeometricShape*> geometricShapes;
    //QList<GeometricShape*> cppGeometricShapes;
public:
    DisplayFile();
    void addGeometricShape(GeometricShape*);
    void deleteGeometricShape(int);
    QList<GeometricShape*> getGeometricShapes();
};

#endif // DISPLAYFILE_H
