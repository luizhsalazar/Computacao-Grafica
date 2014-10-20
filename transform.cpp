 #include "transform.h"
#include "point3d.h"

static Transform *instance = 0;

Transform* Transform::getInstance(){
    if(instance == 0)
        instance = new Transform();
    return instance;
}

Transform::Transform()
{
    this->projection_type = PERSPECTIVE;
}

void Transform::setProjectionType(projectionType type)
{
    this->projection_type = type;
}

void Transform::transform(Shape3D *shape, float m[4][4]) {
    QList<Coordinate3D*> coords = shape->getCoordinates();
    float r[4];
    float v[4] = {0,0,0,0};
    foreach (Coordinate3D* c, coords){
        c->toVector(v);
        multiplyVetMatrix44(v, m, r);
        c->setFromVector(r);
    }
}

void Transform::transform(Coordinate3D *c, float m[4][4])
{
    float v[4];
    float r[4];
    c->toVector(v);
    multiplyVetMatrix44(v, m, r);
    c->setFromVector(r);
}

Shape3D* Transform::project(Shape3D* shapeOriginal, Coordinate3D *t, Coordinate3D *s, Coordinate3D *vpn, Coordinate3D *vup) {
    float matrix[4][4];
    getTransformationMatrix(t, s, vpn, vup, matrix);
    Shape3D* clone = shapeOriginal->clone();
    float cop = 100 * s->getZ();
    QList<Coordinate3D*> coords = clone->getCoordinates();
    foreach(Coordinate3D* c, coords){
        transform(c, matrix);
        if(projection_type == PERSPECTIVE){
            float x = c->getX() * cop / (c->getZ() + cop);
            float y = c->getY() * cop / (c->getZ() + cop);
            c->setX(x);
            c->setY(y);
        }
    }
    return clone;
}


void Transform::getTransformationMatrix(Coordinate3D *t, Coordinate3D *s, Coordinate3D *vpn, Coordinate3D *vup, float r[4][4]) {
    Coordinate3D *angles = getAngles(vpn, vup);
    float a[4][4];
    float b[4][4];
    float c[4][4];
    getTranslationMatrix(t, a);
    getRotationMatrix(X_AXIS, angles->getX(), b);
    multiplyMatrix44(a, b, c);
    getRotationMatrix(Y_AXIS, angles->getY(), b);
    multiplyMatrix44(c, b, a);
    getRotationMatrix(Z_AXIS, angles->getZ(), b);
    multiplyMatrix44(a, b, c);
    getScaleMatrix(new Coordinate3D(), s, b);
    multiplyMatrix44(c, b, r);
}

Coordinate3D* Transform::getAngles(Coordinate3D* vpn, Coordinate3D* vup)
{
    vpn = vpn->clone();
    vup = vup->clone();

    Coordinate3D* yz = vpn->clone();
    yz->setX(0);
    float ax = 0;
    if (yz->normalize()) {
        ax = atan2(yz->getY(), yz->getZ()) * 180/M_PI;
        this->rotateShape3D(vpn, X_AXIS, ax);
        this->rotateShape3D(vup, X_AXIS, ax);
    }

    float ay = - atan2(vpn->getX(), vpn->getZ()) * 180/M_PI;
    this->rotateShape3D(vpn, Y_AXIS, ay);
    this->rotateShape3D(vup, Y_AXIS, ay);

    float az = atan2(vup->getX(), vup->getY()) * 180/M_PI;
    this->rotateShape3D(vpn, Z_AXIS, az);
    this->rotateShape3D(vup, Z_AXIS, az);

    return new Coordinate3D(ax, ay, az);
}

void Transform::rotateShape3D(Coordinate3D *c, Coordinate3D *anchor, Coordinate3D *axis, float angle) {
    Point3D* p = new Point3D(new QString("dummy"), c);
    rotateShape3D(p, anchor, axis, angle);
}

void Transform::rotateShape3D(Coordinate3D *c, axis axis, float angle){
    Point3D* p = new Point3D(new QString("dummy"), c);
    rotateShape3D(p, axis, angle);
}

void Transform::rotateShape3D(Shape3D *object, axis axis, float angle){
    float matrix[4][4];
    getRotationMatrix(axis, angle, matrix);
    transform(object, matrix);
}

void Transform::rotateShape3D(Shape3D *shape, Coordinate3D *anchor, Coordinate3D *axis, float angle) {

    axis->normalize();

    float rad = angle * M_PI/180;

    float x = axis->getX();
    float y = axis->getY();
    float z = axis->getZ();

    float dx = anchor->getX();
    float dy = anchor->getY();
    float dz = anchor->getZ();

    float x2 = x*x;
    float y2 = y*y;
    float z2 = z*z;

    float ccos = cos(rad);
    float ssin = sin(rad);

    float m[4][4] = {
        {x2+(1-x2)*ccos,x*y*(1-ccos)-z*ssin,x*z*(1-ccos)+y*ssin,0},
        {x*y*(1-ccos)+z*ssin,y2+(1-y2)*ccos,y*z*(1-ccos)-x*ssin,0},
        {x*z*(1-ccos)-y*ssin,y*z*(1-ccos)+x*ssin, z2+(1-z2)*ccos,0},
        {0,0,0,1}
    };
    m[3][0] = -dx*m[0][0] -dy*m[1][0] -dz*m[2][0] +dx;
    m[3][1] = -dx*m[0][1] -dy*m[1][1] -dz*m[2][1] +dy;
    m[3][2] = -dx*m[0][2] -dy*m[1][2] -dz*m[2][2] +dz;

    transform(shape, m);
}

void Transform::translateShape3D(Coordinate3D *c, Coordinate3D *t)
{
    float matrix[4][4];
    this->getTranslationMatrix(t, matrix);
    return transform(c, matrix);
}

void Transform::translateShape3D(Shape3D *s, Coordinate3D *t)
{
    float matrix[4][4];
    this->getTranslationMatrix(t, matrix);

    QList<Coordinate3D*> coords = s->getCoordinates();

    foreach(Coordinate3D* c, coords){
        transform(c, matrix);
    }
}

void Transform::getRotationMatrix(axis axis, float angle, float r[4][4])
{
    float rad = angle * M_PI/180;
    float ssin = sin(rad);
    float ccos = cos(rad);
    if (axis == X_AXIS) {
        float m[4][4] = {
            {1,0,0,0},
            {0,ccos,ssin,0},
            {0,-ssin,ccos,0},
            {0,0,0,1}
        };
        copyMatrix44(m, r);
    } else if (axis == Y_AXIS) {
        float m[4][4] = {
            {ccos, 0,-ssin, 0},
            {0,1,0,0},
            {ssin,0,ccos,0},
            {0,0,0,1}
        };
        copyMatrix44(m, r);
    } else if (axis == Z_AXIS) {
        float m[4][4] = {
            {ccos,ssin,0,0},
            {-ssin,ccos,0,0},
            {0,0,1,0},
            {0,0,0,1}
        };
        copyMatrix44(m, r);
    }
}

void Transform::getTranslationMatrix(Coordinate3D *t, float r[4][4]){
    float dx = t->getX();
    float dy = t->getY();
    float dz = t->getZ();
    float m[4][4] = {
        {1,0,0,0},
        {0,1,0,0},
        {0,0,1,0},
        {dx,dy,dz,1}};
    copyMatrix44(m, r);
}

void Transform::scaleShape3D(Shape3D *shape, Coordinate3D *anchor, Coordinate3D *s)
{
    float m[4][4];
    this->getScaleMatrix(anchor, s, m);
    this->transform(shape, m);
}


void Transform::getScaleMatrix(Coordinate3D *anchor, Coordinate3D* s, float r[4][4]) {
    float dx = anchor->getX();
    float dy = anchor->getY();
    float dz = anchor->getZ();
    float sx = s->getX();
    float sy = s->getY();
    float sz = s->getZ();
    float m[4][4] = {
        {sx,0,0,0},
        {0,sy,0,0},
        {0,0,sz,0},
        {-dx*sx+dx, -dy*sy+dy, -dz*sz+dz, 1},
    };
    copyMatrix44(m, r);
}

void Transform::multiplyMatrix44(float a[4][4], float b[4][4], float r[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            r[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                r[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void Transform::multiplyVetMatrix44(float v[4], float m[4][4], float r[4]) {
    for (int j = 0; j < 4; j++) {
        r[j] = 0;
        for (int i = 0; i < 4; i++) {
            r[j] += v[i] * m[i][j];
        }
    }
}

void Transform::copyMatrix44(float m[4][4], float r[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            r[i][j] = m[i][j];
        }
    }
}

void Transform::MatMultMat42 (double Mat1[4][4], double Mat2[4][2], double matAns[4][2]) {

    int n, m,p;
    for (n=0;n<4;n++)
        for (m=0;m<2;m++)
             matAns[n][m] = 0;

   for (n=0;n<4;n++)
       for (m=0;m<2;m++)
           for (p=0;p<4;p++)
               matAns[n][m] += Mat1[n][p] * Mat2[p][m];
}

Coordinate3D* Transform::crossProduct(Coordinate3D *a, Coordinate3D *b)
{
    float x = a->getY()*b->getZ() - a->getZ()*b->getY();
    float y = a->getZ()*b->getX() - a->getX()*b->getZ();
    float z = a->getX()*b->getY() - a->getY()*b->getX();
    return new Coordinate3D(x,y,z);
}












