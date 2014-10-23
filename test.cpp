 #include "test.h"
#include "objparser.h"

Test::Test()
{
    this->m = Controller::getInstance();
}

void Test::run()
{
//    Controller *m = Controller::getInstance();

    m->moveWindow(50, Z_AXIS);

    char *path = "/home/ricardo/Downloads/teapot2.obj";

    ObjParser *parser = new ObjParser();

    Polygon3D *p = parser->getPolygon3D(path);

    m->addPolygon3D(p);


//    Coordinate3D* c1 = new Coordinate3D(-10,-10,-40);
//    Coordinate3D* c2 = new Coordinate3D(10,-10,-40);
//    Coordinate3D* c3 = new Coordinate3D(10,10,-40);
//    Coordinate3D* c4 = new Coordinate3D(-10,10,-40);
//    Coordinate3D* c5 = new Coordinate3D(10,-10,40);
//    Coordinate3D* c6 = new Coordinate3D(10,10,40);
//    Coordinate3D* c7 = new Coordinate3D(-10,10,40);
//    Coordinate3D* c8 = new Coordinate3D(-10,-10,40);

//    QList<Coordinate3D*> f1;
//    QList<Coordinate3D*> f2;
//    QList<Coordinate3D*> f3;
//    QList<Coordinate3D*> f4;
//    QList<Coordinate3D*> f5;
//    QList<Coordinate3D*> f6;

//    f1 << c1 << c2 << c3 << c4;
//    f2 << c2 << c3 << c6 << c5;
//    f3 << c8 << c5 << c6 << c7;
//    f4 << c4 << c1 << c8 << c7;
//    f5 << c1 << c2 << c5 << c8;
//    f6 << c4 << c7 << c6 << c3;

//    QList<Face*> faces1;
//    faces1.append(new Face(f1));
//    faces1.append(new Face(f2));
//    faces1.append(new Face(f3));
//    faces1.append(new Face(f4));
//    faces1.append(new Face(f5));
//    faces1.append(new Face(f6));

//   m->addPolygon3D(new QString("polig1"), faces1, false);


}


