#include "window.h"

#include <mediator.h>
#include <transform.h>
#include <stdio.h>

Window::Window(QGraphicsView* drawWindow)
{
    this->drawWindow = drawWindow;

    double width = drawWindow->geometry().width() / 2;
    double height = drawWindow->geometry().height() / 2;

    this->xwmin = -width;
    this->ywmin = -height;
    this->xwmax = width;
    this->ywmax = height;

    this->vup << new Coordinate(this->xwmin, this->ywmin) << new Coordinate(this->xwmin, this->ywmax);

    this->viewport = new Viewport(450, drawWindow);
}

void Window::redraw(QList<GeometricShape*> objectsToDraw)
{
    this->viewport->prepareToRedraw(this->xwmin, this->ywmin, this->xwmax, this->ywmax);

    foreach(GeometricShape* geometricShape, objectsToDraw)
    {
        this->viewport->drawGeometricShape(geometricShape);
    }

    this->viewport->updateScene();
}

void Window::zoomIn(int percent)
{
    if(this->xwmax - this->xwmin > percent * 2 && this->ywmax - this->ywmin > percent * 2)
    {
        this->xwmax -= percent;
        this->xwmin += percent;
        this->ywmax -= percent;
        this->ywmin += percent;
        this->redraw(Mediator::getInstance()->getCppGeometricShapes());
    }
}

void Window::zoomOut(int percent)
{
    this->xwmax += percent;
    this->xwmin -= percent;
    this->ywmax += percent;
    this->ywmin -= percent;
    this->redraw(Mediator::getInstance()->getCppGeometricShapes());
}

void Window::move(int u, mov_dir direction)
{
    if(u != 0)
    {
        //Novas Coordenadas para o vup
        double ax = this->vup[0]->getXAxisCoord() + u;
        double ay = this->vup[0]->getYAxisCoord() + u;
        double bx = this->vup[1]->getXAxisCoord() + u;
        double by = this->vup[1]->getYAxisCoord() + u;

        this->vup[0]->setXAxisCoord(ax);
        this->vup[0]->setYAxisCoord(ay);
        this->vup[1]->setXAxisCoord(bx);
        this->vup[1]->setYAxisCoord(by);

        float xvar = 0;
        float yvar = 0;
        if(direction == HORIZONTAL){
            xvar = u;
        }else{
//            if(this->vup[0]->getYAxisCoord() > this->vup[1]->getYAxisCoord())
//                u = -u;
            yvar = u;
        }



        //movendo a window
        this->xwmax += xvar;
        this->xwmin += xvar;
        this->ywmax += yvar;
        this->ywmin += yvar;

        //redesenhando os objetos
        redraw(Mediator::getInstance()->getCppGeometricShapes());
    }
}

//void Window::move(int u, mov_dir direction)
//{
//    if(u != 0)
//    {
//        //Novas Coordenadas para o vup
//        double ax = this->vup[0]->getXAxisCoord() + u;
//        double ay = this->vup[0]->getYAxisCoord() + u;
//        double bx = this->vup[1]->getXAxisCoord() + u;
//        double by = this->vup[1]->getYAxisCoord() + u;

//        this->vup[0]->setXAxisCoord(ax);
//        this->vup[0]->setYAxisCoord(ay);
//        this->vup[1]->setXAxisCoord(bx);
//        this->vup[1]->setYAxisCoord(by);

//        //Calculando vetor normalizado de vup com tamanho "u" e mesmo sentido
//        float rx = bx - ax;
//        float ry = by - ay;
//        float sqrt1 = sqrt(rx*rx + ry*ry);
//        float v[2] = {(bx - ax)/sqrt1, (by - ay)/sqrt1};

//        //Calculando vetor ortorgonal a vup se a direção do movimento for horizontal
//        if(direction == HORIZONTAL)
//        {
//            if(v[1]!=0)
//            {
//                v[1] = -v[0]/v[1];
//                v[0] = 1;
//            }
//            else
//            {
//                v[0] = 0;
//                v[1] = -1;
//            }

//            sqrt1 = sqrt(v[0]*v[0] + v[1]*v[1]);
//            v[0] = v[0]/sqrt1;
//            v[1] = v[1]/sqrt1;

//            //Verifica se o vup está virado para baixo
//            //se sim inverte a direção da movimentação
//            if(this->vup[0]->getYAxisCoord() > this->vup[1]->getYAxisCoord())
//                u = -u;

//        }

//        v[0] *= u;
//        v[1] *= u;

//        //movendo a window
//        this->xwmax += v[0];
//        this->xwmin += v[0];
//        this->ywmax += v[1];
//        this->ywmin += v[1];

//        //redesenhando os objetos
//        redraw(Mediator::getInstance()->getCppGeometricShapes());
//    }
//}

//void Window::rotate(double angle)
//{
//    Coordinate* coordA = this->vup[0];
//    Coordinate* coordB = this->vup[1];

//    float* wc = this->getCenter();

//    float rx = wc[0];
//    float ry = wc[1];

//    Transform* t = Transform::getInstance();
//    t->rotateGeometricShape(new Line(coordA, coordB), -angle, rx, ry);

//    QList<GeometricShape*> objectsToRotate = Mediator::getInstance()->getCppGeometricShapes();

//    foreach(GeometricShape* gs, objectsToRotate)
//    {
//        gs->calcCpp(angle, rx, ry);
//    }

//    this->redraw(objectsToRotate);
//}

float* Window::getCenter()
{
    float rx = (this->xwmin + this->xwmax)/2;
    float ry = (this->ywmin + this->ywmax)/2;

    float a[2] = {rx, ry};

    return a;
}

float Window::getAngle()
{
    Coordinate* coordA = this->vup[0];
    Coordinate* coordB = this->vup[1];

    double v[2] = {coordB->getXAxisCoord() - coordA->getXAxisCoord(),
                   coordB->getYAxisCoord() - coordA->getYAxisCoord()};

    float a = v[1] / sqrt(v[0]*v[0] + v[1]*v[1]);

    a = acos(a)*(180/M_PI);

    if(v[0] < 0)
        a = -a;

    return a;
}


