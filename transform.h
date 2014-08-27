#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <geometricshape.h>
#include <math.h>

enum rotate_direction {
    ROTATE_LEFT, ROTATE_RIGHT
};
enum rotateType
{
    ORIGIN   = 0,
    CENTER   = 1,
    POINT2    = 2
          };

class Transform
{
protected:
    rotateType type;

private:
    Transform();

public:
    static Transform* getInstance();
    void setType(rotateType);

    rotateType getType();

    void rotateGeometricShape(GeometricShape*, int);
    void rotateGeometricShape(GeometricShape* , int ,double,double);
    void translateGeometricShape(GeometricShape*, double, double);
    void scaleGeometricShape(GeometricShape*,double,double);

    //Multiplica matriz 3x3 por vetor 1x3
    void multVetMatriz3x3(double[3][3],double[3],double[3]);
    //Multiplica matriz 3x3 por outra 3x3
    void MatMultMat33(double[3][3], double[3][3], double[3][3]);

    void MatMultMat42(double[4][4],double[4][2],double[4][2]);

    Coordinate* calcMedia(QList<Coordinate*>);

    QList<Coordinate*> calcScale(QList<Coordinate*>,Coordinate*,double,double);
    QList<Coordinate*> calcRotation(QList<Coordinate*> , Coordinate*, int);


};

#endif // TRANSFORM_H
