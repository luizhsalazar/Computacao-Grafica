 #include "objparser.h"

#define MAX_LINE_SIZE 256

ObjParser::ObjParser()
{

}

Polygon3D* ObjParser::getPolygon3D(char *objFilePath)
{

    FILE *obj = fopen(objFilePath,"r");
    char buffer[MAX_LINE_SIZE];

    this->name = new QString("dummy");

    if (obj)
    {
        while (fgets(buffer,MAX_LINE_SIZE,obj))
            getElement(buffer);
    }

    Shape3DFactory* sf = Shape3DFactory::getInstance();

    return sf->createPolygon3D(this->name, this->fList);
}

void ObjParser::getElement(char *buffer)
{
    switch(buffer[0])
    {
    case PARSED_ELEMENT_VERTEX:
        switch(buffer[1])
        {
        default:
            readVertex(buffer);
        }
        break;

     case PARSED_ELEMENT_FACE:
        readFace(buffer);
        break;

     case PARSED_ELEMENT_GROUP:
        readGroup(buffer);
        break;

        //ignore
            case PARSED_ELEMENT_TEXTURE:
            case PARSED_ELEMENT_NORMAL:
            case PARSED_ELEMENT_SMOOTH:
            case PARSED_ELEMENT_COMMENT:
            case PARSED_ELEMENT_MATERIAL:
            default:
        //printf("%s",buffer);
        break;
    }
}

void ObjParser::readVertex(char *objString)
{
    float x;
    float y;
    float z;
    sscanf(objString,"%*s %f %f %f\n",&x,&y,&z);
    this->cList.append(new Coordinate3D(x,y,z));
}

void ObjParser::readGroup(char *objString)
{
    char* name = (char*)malloc(256*sizeof(char));
    sscanf(objString,"g %s\n", name);
    free(this->name);
    this->name = new QString(name);
}

void ObjParser::readFace(char *objString)
{
    int a,b,c;

    sscanf(objString,"f %d %d %d\n", &a,&b,&c);

    Face *f = new Face();
    f->appendCoordinate(this->cList.value(a-1));
    f->appendCoordinate(this->cList.value(b-1));
    f->appendCoordinate(this->cList.value(c-1));

    this->fList.append(f);
}

