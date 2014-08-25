#include "displayfile.h"

DisplayFile::DisplayFile()
{

}

void DisplayFile::addGeometricShape(GeometricShape * geometricShape)
{
    this->geometricShapes.append(geometricShape);
}

void DisplayFile::deleteGeometricShape(int index)
{
    this->geometricShapes.removeAt(index);
}

QList<GeometricShape*> DisplayFile::getGeometricShapes()
{
    return this->geometricShapes;
}

