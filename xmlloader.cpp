#include "xmlloader.h"
#include <QDebug>
#include <sstream>
#include "point3d.h"

XMLLoader::XMLLoader()
{

}

XMLLoader::~XMLLoader(){}

Point3D* XMLLoader::constructPoint(TiXmlElement& pElem){

    double x,y,z;
    pElem.QueryDoubleAttribute("x", &x);
    pElem.QueryDoubleAttribute("y", &y);
    pElem.QueryDoubleAttribute("z", &z);

    QColor color = QColor(255,255,0);
    Shape3DFactory *s = Shape3DFactory::getInstance();
    Point3D* p = s->createPoint3D(new QString("p"), x, y, z, color);

    return p;
}

void XMLLoader::constructOnePoint(TiXmlHandle hElem)
{

    TiXmlElement* pElem = hElem.Element();
    double x,y,z;
    pElem->QueryDoubleAttribute("x", &x);
    pElem->QueryDoubleAttribute("y", &y);
    pElem->QueryDoubleAttribute("z", &z);
    const char* cor  = pElem->Attribute("cor");
    char *texto = const_cast<char *>(cor);
    QColor color = XMLLoader::getColor(texto);
    QString a = pElem->Attribute("nome");

    Mediator *m = Mediator::getInstance();

    qDebug() << pElem->Attribute("nome");
    m->addPoint3D(new QString("ponto1"),x,y,z,color);

}

void XMLLoader::constructReta(TiXmlHandle hElem){

        TiXmlElement* pElem = hElem.FirstChildElement("ponto").Element();
        const char* cor  = pElem->Attribute("cor");
        char *texto = const_cast<char *>(cor);
        QColor color = XMLLoader::getColor(texto);

        Point3D* p1 = constructPoint(*pElem);
        pElem = pElem->NextSiblingElement("ponto");
        Point3D* p2 = constructPoint(*pElem);

        Mediator *m = Mediator::getInstance();
        m->addLine3D(new QString("reta1"),p1->getX(),p1->getY(),p1->getZ(),p2->getX(),p2->getY(),p2->getZ(),color);
}

void XMLLoader::shapesAtLevel(TiXmlHandle handle){

       TiXmlElement *pElem, *pElem2;

        pElem = handle.FirstChild( "ponto" ).Element();
        if (pElem){
            for( ; pElem; pElem=pElem->NextSiblingElement("ponto")){
                    qDebug() << "Encontro o ponto";
                    constructOnePoint(pElem);
                }
        }

        pElem=handle.FirstChild( "reta" ).Element();
        if (pElem){
            for( ; pElem; pElem=pElem->NextSiblingElement("reta")){
                    qDebug() << "reta";
                    constructReta(pElem);
            }
        }

        pElem=handle.FirstChild( "poligono" ).Element();
        if (pElem){
            qDebug() << "poligono";
            constructPoligono(pElem);
        }

        pElem=handle.FirstChild( "curvaBSpline" ).Element();
        if (pElem){
            qDebug() << "bspline.....";
            constructSpline(pElem);
        }

        pElem=handle.FirstChild( "curvaBezier" ).Element();
        if (pElem){
            qDebug() << "bezier.....";
            constructBezier(pElem);
        }

        pElem=handle.FirstChild( "objeto3d" ).Element();
        if (pElem){
            qDebug() << "objeto3D.....";
            constructObject3D(pElem);
        }


        pElem=handle.FirstChild( "formas" ).Element();
        if (pElem){
                shapesAtLevel(pElem);
        }
}

void XMLLoader::processShapes(TiXmlDocument& doc){

        TiXmlHandle hDoc(&doc);
        shapesAtLevel(hDoc);
}

void XMLLoader::constructPoligono(TiXmlHandle hElem){

        QList <Coordinate3D*> pontos;
        TiXmlElement* e = hElem.Element();

        for(TiXmlElement* pElem = hElem.FirstChild( "ponto" ).Element() ; pElem; pElem=pElem->NextSiblingElement("ponto")){

            Point3D* p = constructPoint(*pElem);
            pontos.append(p->getCoordinate());
        }

        const char* cor  = e->Attribute("cor");
        char *texto = const_cast<char *>(cor);
        QColor color = XMLLoader::getColor(texto);


        Face* f = new Face(pontos,color);

        QList <Face*> faces;

        faces.append(f);

        Mediator *m = Mediator::getInstance();
        m->addPolygon3D(new QString('pol'),faces,false);

        if(strcmp(e->Attribute("cheio"),"verdadeiro") == 0 ) {
            m->addPolygon3D(new QString('pol'),faces,true);
        } else {
            m->addPolygon3D(new QString('pol'),faces,false);
        }
}

void XMLLoader::constructObject3D(TiXmlHandle hElem) {

    //pegar os pontos
    TiXmlElement* pElem;
    QList<Coordinate3D*> points;

    TiXmlElement* e = hElem.Element();
    const char* cor  = e->Attribute("cor");
    char *texto = const_cast<char *>(cor);
    QColor color = XMLLoader::getColor(texto);

    double x,y,z;

    TiXmlHandle pontos = hElem.FirstChild( "pontos" );
    for(pElem = pontos.FirstChild( "ponto" ).Element() ; pElem; pElem=pElem->NextSiblingElement("ponto")){

        pElem->QueryDoubleAttribute("x", &x);
        pElem->QueryDoubleAttribute("y", &y);
        pElem->QueryDoubleAttribute("z", &z);

        Coordinate3D* c = new Coordinate3D(x,y,z);
        points.append(c);
    }

    QList<Face*> faces;
    Face* f = new Face(points,color);

    TiXmlHandle arestas = hElem.FirstChild( "arestas" );
    for(pElem = arestas.FirstChild( "aresta" ).Element() ; pElem; pElem=pElem->NextSiblingElement("aresta")){

            int v1,v2;
            pElem->QueryIntAttribute("v1", &v1);
            pElem->QueryIntAttribute("v2", &v2);

            QList <Coordinate3D*> p;

            p.append(points.at(v1));
            p.append(points.at(v2));
            p.append(points.at(3));

            Face* f = new Face(p,color);
            faces.append(f);
    }

    Mediator *m = Mediator::getInstance();
    m->addPolygon3D(new QString("obj3d"),faces,false);
}

void XMLLoader::constructSpline(TiXmlHandle hElem){

        QList <Coordinate*> pontos;
        TiXmlElement* e = hElem.Element();
        const char* cor  = e->Attribute("cor");
        char *texto = const_cast<char *>(cor);
        QColor color = XMLLoader::getColor(texto);

        for(TiXmlElement* pElem = hElem.FirstChild( "ponto" ).Element() ; pElem; pElem=pElem->NextSiblingElement("ponto")){

            double x,y;
            pElem->QueryDoubleAttribute("x", &x);
            pElem->QueryDoubleAttribute("y", &y);

            Coordinate* c = new Coordinate(x,y);
            pontos.append(c);
        }

        Mediator *m = Mediator::getInstance();
        m->addBsplineCurve(new QString("bSpline"),pontos,color);
}

void XMLLoader::constructBezier(TiXmlHandle hElem){

      QList <Coordinate*> pontos;
      double x,y;

      TiXmlElement* el = hElem.Element();
      const char* cor  = el->Attribute("cor");
      char *texto = const_cast<char *>(cor);
      QColor color = XMLLoader::getColor(texto);

      TiXmlElement*element = hElem.FirstChild( "geometria" ).Element();
      TiXmlHandle e = element;

      if (element) {
          for(int i = 1; i<=4; i++){

              char *p =(char*) malloc(2*sizeof(char));
              p[0]= 'p';
              sprintf(&p[1],"%d",i);

              TiXmlElement* pElem = e.FirstChild(p).Element();
              if (pElem) {
                  pElem->QueryDoubleAttribute("x", &x);
                  pElem->QueryDoubleAttribute("y", &y);

                  Coordinate* c = new Coordinate(x,y);
                  pontos.append(c);
              }
          }
      }
      Mediator *m = Mediator::getInstance();
      m->addBezierCurve(new QString("bezier"),pontos,color);
}

void XMLLoader::loadXml(char* path){

    qDebug() << path;

    TiXmlDocument doc(path);
    bool loadOkay = doc.LoadFile();

    if (loadOkay) {
        qDebug() << ".xml loaded!";
        XMLLoader::processShapes(doc);
    }else {
        qDebug() << "Failed to load file!";
    }
}

QColor XMLLoader::getColor(char* cor) {

    if(cor == NULL){ return QColor(255,255,255); }

    std::stringstream ss;
    int R,G,B;
    char p[2];

    //RED
    p[0] = cor[0];
    p[1] = cor[1];
    p[2] = 0;
    ss << std::hex << p;
    ss >> R;

    qDebug() << R;

    //GREEN
    ss.clear();
    p[0] = cor[2];
    p[1] = cor[3];
    ss << std::hex << p;
    ss >> G;

     qDebug() << G;

    //Blue
    ss.clear();
    p[0] = cor[4];
    p[1] = cor[5];
    ss << std::hex << p;
    ss >> B;

    qDebug() << B;

    return QColor(R,G,B);
}
