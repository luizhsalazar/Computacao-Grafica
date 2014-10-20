 #include "displayfile.h"

DisplayFile::DisplayFile()
{

}

void DisplayFile::deleteShape3D(int index)
{
    this->shapes3D.removeAt(index);
    this->cppShapes3D.removeAt(index);
}

void DisplayFile::addShape3D(Shape3D *s)
{
    this->shapes3D.append(s);
    Shape3D* cloneS = s->clone();
    this->cppShapes3D.append(cloneS);
}

QList<Shape3D*> DisplayFile::getShapes3D()
{
    return this->shapes3D;
}

QList<Shape3D*> DisplayFile::getCppShapes3D()
{
    return this->cppShapes3D;
}

QList<GeometricShape*> DisplayFile::getGeometricShapes()
{
    return this->geometricShapes;
}

QList<GeometricShape*> DisplayFile::getCppGeometricShapes()
{
    return this->cppGeometricShapes;
}


void DisplayFile::addGeometricShape(GeometricShape * geometricShape, float wa, float* wc)
{
    this->geometricShapes.append(geometricShape);

    GeometricShape* cloneGs = geometricShape->clone();
    cloneGs->calcCpp(wa, wc[0], wc[1]);

    this->cppGeometricShapes.append(cloneGs);
}



