 #ifndef COORDINATE3D_H
#define COORDINATE3D_H

class Coordinate3D
{
private:
    float x;
    float y;
    float z;

public:
    Coordinate3D();
    Coordinate3D(float, float, float);
    float getX();
    float getY();
    float getZ();
    void setX(float);
    void setY(float);
    void setZ(float);
    Coordinate3D* clone();
    float getNorm();
    bool normalize();
    Coordinate3D* negate();
    void toVector(float[4]);
    void setFromVector(float[4]);
    void scalarMult(float);
    void show();
};

#endif // COORDINATE3D_H
