 #include "coordinate3d.h"
#include <math.h>
#include <QDebug>

Coordinate3D::Coordinate3D(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Coordinate3D::Coordinate3D()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

float Coordinate3D::getX()
{
    return this->x;
}

float Coordinate3D::getY()
{
    return this->y;
}

float Coordinate3D::getZ()
{
    return this->z;
}

void Coordinate3D::setX(float a)
{
    this->x = a;
}

void Coordinate3D::setY(float a)
{
    this->y = a;
}

void Coordinate3D::setZ(float a)
{
    this->z = a;
}

Coordinate3D* Coordinate3D::clone()
{
    return new Coordinate3D(x, y, z);
}

float Coordinate3D::getNorm()
{
    return sqrt(x*x+y*y+z*z);
}

bool Coordinate3D::normalize()
{

    float norm = this->getNorm();
    if(norm == 0)
        return false;

    x = x/norm;
    y = y/norm;
    z = z/norm;
    return true;
}

Coordinate3D* Coordinate3D::negate()
{
    return new Coordinate3D(-x, -y, -z);
}

void Coordinate3D::toVector(float r[4])
{
    r[0] = x;
    r[1] = y;
    r[2] = z;
    r[3] = 1;
}

void Coordinate3D::setFromVector(float r[4])
{
    this->x = r[0];
    this->y = r[1];
    this->z = r[2];
}

void Coordinate3D::show()
{
    qWarning("x=%f y=%f z=%f", x, y, z);
}

void Coordinate3D::scalarMult(float scalar)
{
    x = x * scalar;
    y = y * scalar;
    z = z * scalar;
}

