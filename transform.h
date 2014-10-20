 #ifndef TRANSFORM_H
#define TRANSFORM_H

#include <geometricshape.h>
#include <shape3d.h>
#include <math.h>

enum rotate_direction {
    ROTATE_LEFT, ROTATE_RIGHT
        };

enum rotationType
{
    ORIGIN   = 0,
    CENTER   = 1,
};

enum axis
{
    X_AXIS,
    Y_AXIS,
    Z_AXIS,
};

enum projectionType
{
    PARALLEL,
    PERSPECTIVE,
};

class Transform
{
private:
    Transform();
    projectionType projection_type;

public:
    static Transform* getInstance();

    void setProjectionType(projectionType);

    void rotateShape3D(Coordinate3D *, Coordinate3D *, Coordinate3D *, float);
    void rotateShape3D(Coordinate3D *, axis ,float);
    void rotateShape3D(Shape3D *, axis ,float);
    void rotateShape3D(Shape3D *, Coordinate3D *, Coordinate3D *, float);
    void translateShape3D(Shape3D*, Coordinate3D*);
    void translateShape3D(Coordinate3D*, Coordinate3D*);
    void scaleShape3D(Shape3D*, Coordinate3D*, Coordinate3D*);

    void transform(Coordinate3D*, float[4][4]);
    void transform(Shape3D*, float[4][4]);
    Shape3D* project(Shape3D*, Coordinate3D *, Coordinate3D *, Coordinate3D *, Coordinate3D *);

    Coordinate3D* getAngles(Coordinate3D*, Coordinate3D*);

    void getTransformationMatrix(Coordinate3D *, Coordinate3D *, Coordinate3D *, Coordinate3D *, float[4][4]);
    void getRotationMatrix(axis, float, float[4][4]);
    void getTranslationMatrix(Coordinate3D*, float[4][4]);
    void getScaleMatrix(Coordinate3D*, Coordinate3D*, float [4][4]);

    void copyMatrix44(float[4][4], float[4][4]);
    void multiplyMatrix44(float[4][4], float[4][4], float[4][4]);
    void multiplyVetMatrix44(float[4], float[4][4], float[4]);
    void MatMultMat42 (double Mat1[4][4], double Mat2[4][2], double matAns[4][2]);
    Coordinate3D* crossProduct(Coordinate3D*, Coordinate3D*);
};

#endif // TRANSFORM_H
