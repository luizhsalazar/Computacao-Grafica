#include "displayfile.h"

DisplayFile::DisplayFile()
{

}

void DisplayFile::addGeometricShape(GeometricShape * geometricShape, float wa, float* wc)
{
    this->geometricShapes.append(geometricShape);

    GeometricShape* cloneGs = geometricShape->clone();
    cloneGs->calcCpp(wa, wc[0], wc[1]);

    this->cppGeometricShapes.append(cloneGs);
}

void DisplayFile::deleteGeometricShape(int index)
{
    this->geometricShapes.removeAt(index);
    this->cppGeometricShapes.removeAt(index);
}

QList<GeometricShape*> DisplayFile::getGeometricShapes()
{
    return this->geometricShapes;
}

QList<GeometricShape*> DisplayFile::getCppGeometricShapes()
{
    return this->cppGeometricShapes;
}

