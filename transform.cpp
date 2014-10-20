#include "transform.h"

static Transform *instance = 0;

Transform* Transform::getInstance(){
    if(instance == 0)
        instance = new Transform();
    return instance;
}

Transform::Transform()
{
}

void Transform::setType(rotateType type)
{
    this->type = type;
}

void Transform::translateGeometricShape(GeometricShape* geometricShape, double dx, double dy)
{
    double matriz[3][3] = {{1,0,0},{0,1,0},{dx,dy,1}};
    double resultante[3] = {0,0,1};

    QList<Coordinate*> coordList = geometricShape->getCoordinates();

    foreach(Coordinate* coordinate, coordList)
    {
        double mult[3] = {coordinate->getXAxisCoord(),
                          coordinate->getYAxisCoord(),
                          1};
        multVetMatriz3x3(matriz, mult, resultante);
        coordinate->setXAxisCoord(resultante[0]);
        coordinate->setYAxisCoord(resultante[1]);
    }
}

void Transform::scaleGeometricShape(GeometricShape * geometricShape, double sX, double sY)
{

    QList<Coordinate*> coordList = geometricShape->getCoordinates();
    Coordinate* coordMedia = calcMedia(coordList);

    coordList = this->calcScale(coordList,coordMedia,sX,sY);

    foreach(Coordinate* coordinate,coordList)
    {
        coordinate->setXAxisCoord(coordinate->getXAxisCoord());
        coordinate->setYAxisCoord(coordinate->getYAxisCoord());
    }

}


QList<Coordinate*> Transform::calcScale(QList<Coordinate*> coordList,Coordinate* media, double sX, double sY)
{
    double matrixScale[3][3] = {{sX,0,0},{0,sY,0},{0,0,1}};
    double matrix[3][3] = {{0,0,0},{0,0,0},{0,0,0}} ;
    double resultante[3];
    double matrixTranslate[3][3] = {{1,0,0},{0,1,0},{-media->getXAxisCoord(),
                                                     -media->getYAxisCoord(),
                                                     1}};

    QList<Coordinate*> coordResultante;
    MatMultMat33(matrixTranslate, matrixScale,matrix);
    matrixTranslate[2][0] = -matrixTranslate[2][0];
    matrixTranslate[2][1] = -matrixTranslate[2][1];
    MatMultMat33(matrix, matrixTranslate, matrixScale);

    foreach(Coordinate* coordinate, coordList)
    {
        double vector[3] = {coordinate->getXAxisCoord(), coordinate->getYAxisCoord(), 1};
        multVetMatriz3x3(matrixScale, vector, resultante);
        coordinate->setXAxisCoord(resultante[0]);
        coordinate->setYAxisCoord(resultante[1]);
        coordResultante.append(coordinate);
    }
    return coordResultante;
}

void Transform::rotateGeometricShape(GeometricShape* geometricShape, int angle)
{
    QList<Coordinate*> coordList = geometricShape->getCoordinates();

    if(this->type == ORIGIN)
    {
        double rad = angle * M_PI/180;
        double sen = sin(rad);
        double coss = cos(rad);
        double matrix[3][3] = {{coss,-sen,0},{sen,coss,0},{0,0,1}};
        foreach(Coordinate* coordinate, coordList)
        {
            double resultante[3];
            double vector[3] = {coordinate->getXAxisCoord(), coordinate->getYAxisCoord(), 1};
            multVetMatriz3x3(matrix, vector, resultante);
            coordinate->setXAxisCoord(resultante[0]);
            coordinate->setYAxisCoord(resultante[1]);

        }
    }
    else if(this->type == CENTER)
    {
        Coordinate* coordMedia = calcMedia(coordList);
        coordList = this->calcRotation(coordList,coordMedia,angle);

        foreach(Coordinate* coordinate, coordList)
        {
            coordinate->setXAxisCoord(coordinate->getXAxisCoord());
            coordinate->setYAxisCoord(coordinate->getYAxisCoord());
        }
    }
}

void Transform::rotateGeometricShape(GeometricShape* geometricShape, int angle, double rX, double rY)
{
    QList<Coordinate*> coordList = geometricShape->getCoordinates();

    Coordinate* coord = new Coordinate(rX,rY);

    coordList = this->calcRotation(coordList,coord,angle);

    foreach(Coordinate* coordinate, coordList)
    {
        coordinate->setXAxisCoord(coordinate->getXAxisCoord());
        coordinate->setYAxisCoord(coordinate->getYAxisCoord());
    }
}

QList<Coordinate*> Transform::calcRotation(QList<Coordinate*> coordList, Coordinate* vector, int angle)
{
    double rad = angle * M_PI/180;
    double sen = sin(rad);
    double coss = cos(rad);
    double matrixRotation[3][3] = {{coss,-sen,0},{sen,coss,0},{0,0,1}};
    double matrix[3][3] = {{0,0,0},{0,0,0},{0,0,0}} ;
    double matrixTranslate[3][3] = {{1,0,0},{0,1,0},{-vector->getXAxisCoord(),-vector->getYAxisCoord(),1}};
    double resultante[3];
    QList<Coordinate*> coordResultante;
    MatMultMat33(matrixTranslate, matrixRotation,matrix);
    matrixTranslate[2][0] = -matrixTranslate[2][0];
    matrixTranslate[2][1] = -matrixTranslate[2][1];
    MatMultMat33(matrix, matrixTranslate, matrixRotation);
    foreach(Coordinate* coordinate, coordList)
    {
        double vector[3] = {coordinate->getXAxisCoord(), coordinate->getYAxisCoord(), 1};
        multVetMatriz3x3(matrixRotation, vector, resultante);
        coordinate->setXAxisCoord(resultante[0]);
        coordinate->setYAxisCoord(resultante[1]);
        coordResultante.append(coordinate);
    }
    return coordResultante;
}

void Transform::multVetMatriz3x3(double matriz[3][3], double vector[3], double resultante[3])
{
    for (int i = 0; i < 3; i++) {
        resultante[i] = 0;
        for (int j = 0; j < 3; j++) {
            resultante[i] += vector[j] * matriz[j][i];
        }
    }

}

void Transform::MatMultMat33(double mat1[3][3], double mat2[3][3], double matAns[3][3])
{
    int n, m,p;
    for (n=0;n<3;n++)
        for (m=0;m<3;m++)
            matAns[n][m] = 0;

    for (n=0;n<3;n++)
        for (m=0;m<3;m++)
            for (p=0;p<3;p++)
                matAns[n][m] += mat1[n][p] * mat2[p][m];
}

void Transform::MatMultMat42 (double Mat1[4][4], double Mat2[4][2], double matAns[4][2])
{

    int n, m,p;
    for (n=0;n<4;n++)
        for (m=0;m<2;m++)
             matAns[n][m] = 0;

   for (n=0;n<4;n++)
       for (m=0;m<2;m++)
           for (p=0;p<4;p++)
               matAns[n][m] += Mat1[n][p] * Mat2[p][m];
}

Coordinate* Transform::calcMedia(QList<Coordinate*> coordList)
{

    double x = 0;
    double y = 0;
    int count = 0;

    foreach(Coordinate* coordinate, coordList)
    {
        x += coordinate->getXAxisCoord();
        y += coordinate->getYAxisCoord();
        count++;
    }
    x = x/count;
    y = y/count;
    Coordinate* coord = new Coordinate(x,y);

    return coord;

}
