#include "window.h"

#include <controller.h>
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

    this->width = 100;
    this->height = 100;

    this->vrp = new Coordinate3D(0,0,0);
    this->vpn = new Coordinate3D(0,0,1);
    this->vup = new Coordinate3D(0,1,0);

    this->viewport = new Viewport(450, drawWindow);
}

void Window::redraw(QList<Shape3D*> objects3DToDraw)
{
    this->viewport->prepareToRedraw(this->xwmin, this->ywmin, this->xwmax, this->ywmax);
    this->draw3DShapes(objects3DToDraw);
    this->viewport->updateScene();
}

void Window::redraw2D(QList<GeometricShape*> objectsToDraw)
{
    this->viewport->prepareToRedraw(this->xwmin, this->ywmin, this->xwmax, this->ywmax);

    foreach(GeometricShape* geometricShape, objectsToDraw)
    {
        this->viewport->drawGeometricShape(geometricShape);
    }

    this->viewport->updateScene();
}

void Window::draw3DShapes(QList<Shape3D *> objects3DToDraw)
{
    Transform *t = Transform::getInstance();
    Coordinate3D* scale = new Coordinate3D(2/width, 2/height, 0.01);

    foreach(Shape3D* s, objects3DToDraw)
    {
        Shape3D* clone = t->project(s, this->vrp->negate(), scale, vpn, vup);
        bool draw = true;
        foreach(Coordinate3D *c, clone->getCoordinates()){
            if(c->getZ() > 1 || c->getZ() < 0){
                draw = false;
                break;
            }
        }
        if(draw)
            this->viewport->drawGeometricShape(clone->convertTo2D());
    }
}

void Window::zoom(float percent)
{
    percent /= 100;
    this->width *= (1-percent);
    this->height *= (1-percent);
    this->setupRedraw();
}

void Window::move(float variation, axis axis)
{
    Transform *t = Transform::getInstance();

    Coordinate3D* t_vector;

    switch (axis) {
    case X_AXIS:
        t_vector = t->crossProduct(this->vpn, this->vup);
        t_vector->scalarMult(variation);
        t->translateShape3D(this->vrp, t_vector);
        break;
    case Y_AXIS:
        t_vector = this->vup->clone();
        t_vector->scalarMult(-variation);
        t->translateShape3D(this->vrp, t_vector);
        break;
    case Z_AXIS:
        t_vector = this->vpn->clone();
        t_vector->scalarMult(-variation);
        t->translateShape3D(this->vrp, t_vector);
        break;
    }
    this->setupRedraw();
}

void Window::rotate(float angle, axis axis)
{

    Transform *t = Transform::getInstance();

    Coordinate3D *c;

    switch (axis) {
    case X_AXIS:
        c = t->crossProduct(this->vpn, this->vup);
        t->rotateShape3D(this->vpn, new Coordinate3D(), c, angle);
        t->rotateShape3D(this->vup, new Coordinate3D(), c, angle);
        this->vpn->normalize();
        this->vup->normalize();
        break;
    case Y_AXIS:
        t->rotateShape3D(this->vpn, new Coordinate3D(), this->vup, angle);
        this->vpn->normalize();
        break;
    case Z_AXIS:
        t->rotateShape3D(this->vup, new Coordinate3D(), this->vpn, angle);
        this->vup->normalize();
        break;
    }

    this->setupRedraw();
}

Coordinate3D* Window::getCenter()
{
    return this->vrp->clone();
}

float* Window::getCenter2D()
{
    float rx = (this->xwmin + this->xwmax)/2;
    float ry = (this->ywmin + this->ywmax)/2;

    float a[2] = {rx, ry};

    return a;
}


void Window::setupRedraw()
{
    Controller *m = Controller::getInstance();
    this->redraw(m->getCppShapes3D());
//    this->redraw2D(m->getCppGeometricShapes());
}

void Window::reset()
{
    float vrp[4] = {0,0,0,0};
    float vpn[4] = {0,0,1,0};
    float vup[4] = {0,1,0,0};

    this->vrp->setFromVector(vrp);
    this->vpn->setFromVector(vpn);
    this->vup->setFromVector(vup);

    this->width = 100;
    this->height = 100;
}

//float Window::getAngle()
//{
//    Coordinate3D = this->vup[0];
//
//
//
////    Coordinate* coordA = this->vup[0];
////    Coordinate* coordB = this->vup[1];
////
////    double v[2] = {coordB->getXAxisCoord() - coordA->getXAxisCoord(),
////                   coordB->getYAxisCoord() - coordA->getYAxisCoord()};
////
////    float a = v[1] / sqrt(v[0]*v[0] + v[1]*v[1]);
////
////    a = acos(a)*(180/M_PI);
////
////    if(v[0] < 0)
////        a = -a;
////
////    return a;
//}


