#ifndef XMLLOADER_H
#define XMLLOADER_H

#ifdef TIXML_USE_STL
        #include <iostream>
        #include <sstream>
        using namespace std;
#else
        #include <stdio.h>
#endif


#include "tinyxml/tinyxml.h"
#include "point.h"
#include "line.h"
#include "polygon.h"
#include "bezier.h"
#include "bspline.h"
#include <mediator.h>

class XMLLoader
{
private:
    Mediator *m;
    static QColor getColor(char* cor);

public:
    XMLLoader();
    virtual ~XMLLoader();
    static Point3D* constructPoint(TiXmlElement& pElem);
    static void constructOnePoint(TiXmlHandle hElem);
    static void constructReta(TiXmlHandle hElem);
    static void constructPoligono(TiXmlHandle hElem);
    static void constructObject3D(TiXmlHandle hElem);
    static void constructBezier(TiXmlHandle hElem);
    static void constructSpline(TiXmlHandle hElem);
    static void shapesAtLevel(TiXmlHandle handle);
    static void processShapes(TiXmlDocument& doc);

    static void loadXml(char* path);
};

#endif // XMLLOADER_H
