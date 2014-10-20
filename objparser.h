 #ifndef OBJPARSER_H
#define OBJPARSER_H

#include <shape3dfactory.h>
#include <polygon3d.h>
#include <QList>
#include <coordinate3d.h>
#include <face.h>
#include <cstdio>
#include <cstdlib>

enum PARSED_ELEMENT {
    PARSED_ELEMENT_COMMENT = '#',
    PARSED_ELEMENT_VERTEX = 'v',
    PARSED_ELEMENT_NORMAL = 'n',
    PARSED_ELEMENT_TEXTURE = 't',
    PARSED_ELEMENT_FACE = 'f',
    PARSED_ELEMENT_GROUP = 'g',
    PARSED_ELEMENT_OBJECT = 'o',
    PARSED_ELEMENT_SMOOTH = 's',
    PARSED_ELEMENT_MATERIAL = 'm'
};

class ObjParser
{
private:
    void getElement(char*);
    void readVertex(char*);
    void readFace(char*);
    void readGroup(char*);
    QList<Coordinate3D*> cList;
    QList<Face*> fList;
    QString *name;
public:
    ObjParser();
    Polygon3D* getPolygon3D(char*);
};

#endif // OBJPARSER_H
