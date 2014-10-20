 #include "viewport.h"

Viewport::Viewport(double viewPortSize, QGraphicsView* drawWindow)
{
    this->drawWindow = drawWindow;

    this->r_min = 10;
    this->r_max = viewPortSize - this->r_min;

    this->xvpmax = viewPortSize;
    this->yvpmax = viewPortSize;

    this->currentScene = new QGraphicsScene(0, 0, this->xvpmax, this->yvpmax);
    this->currentScene->setBackgroundBrush(Qt::black);
    this->currentScene->addRect(this->r_min, this->r_min, this->r_max - this->r_min, this->r_max - this->r_min, QPen(QColor(255,255,255)));
    this->updateScene();
}

void Viewport::prepareToRedraw(double xwmin, double ywmin, double xwmax, double ywmax)
{
    this->xwmax = xwmax;
    this->ywmax = ywmax;
    this->xwmin = xwmin;
    this->ywmin = ywmin;

    this->currentScene->clear();
    this->currentScene->setBackgroundBrush(Qt::black);
    this->currentScene->addRect(this->r_min, this->r_min, this->r_max - this->r_min, this->r_max - this->r_min, QPen(QColor(255,255,255)));
}

void Viewport::drawGeometricShape(QList<GeometricShape*> geometricShapes)
{
    foreach(GeometricShape* g, geometricShapes)
    {
        GeometricShapeType type = g->getType();

        switch(type)
        {
        case POINT:
            this->drawPoint((Point*)g);
            break;
        case LINE:
            this->drawLine((Line*)g);
            break;
        case POLYGON:
            this->drawPolygon((Polygon*)g);
            break;
        case BEZIER:
            this->drawBezierCurve((Bezier*)g);
            break;
        case BSPLINE:
            this->drawBsplineCurve((Bspline*)g);
            break;
        }
    }
}


void Viewport::drawGeometricShape(GeometricShape* geometricShape)
{
    GeometricShapeType type = geometricShape->getType();

    switch(type)
    {
    case POINT:
        this->drawPoint((Point*)geometricShape);
        break;
    case LINE:
        this->drawLine((Line*)geometricShape);
        break;
    case POLYGON:
        this->drawPolygon((Polygon*)geometricShape);
        break;
    case BEZIER:
        this->drawBezierCurve((Bezier*)geometricShape);
        break;
    case BSPLINE:
        this->drawBsplineCurve((Bspline*)geometricShape);
        break;
    }

}

void Viewport::drawBezierCurve(Bezier* curve)
{
    QList<Coordinate*> coordinates = curve->generateCurveCoordinates();

    int c_count = coordinates.count();

    GeometricShapeFactory* gf = GeometricShapeFactory::getInstance();

    QColor strokeColor = curve->getStrokeColor();

    for(int i = 0; i < c_count - 1; i++)
    {
        Line* line = gf->createLine(coordinates.at(i), coordinates.at(i + 1), strokeColor);
        this->drawLine(line);
    }
}

void Viewport::drawBsplineCurve(Bspline* cspline)
{
    QList<Coordinate*> coordinates = cspline->generateCurveCoordinates();

    int c_count = coordinates.count();

    GeometricShapeFactory* gf = GeometricShapeFactory::getInstance();

    QColor strokeColor = cspline->getStrokeColor();

    for(int i = 0; i < c_count - 1; i++)
    {
        Line* line = gf->createLine(coordinates.at(i), coordinates.at(i + 1), strokeColor);
        this->drawLine(line);
    }
}

bool Viewport::insideClipEdge(Coordinate* p, OutCode clipEdgeOutcode)
{
    float px = p->getXAxisCoord();
    float py = p->getYAxisCoord();

    OutCode outcode = this->computeOutCode(px, py);

    if(outcode == INSIDE)
        return true;
    else{
        if(clipEdgeOutcode == TOP){
            if(outcode == 9 || outcode == 8 || outcode == 10)
                return false;
        }else if(clipEdgeOutcode == BOTTOM){
            if(outcode == 5 || outcode == 4 || outcode == 6)
                return false;
        }else if(clipEdgeOutcode == RIGHT){
            if(outcode == 10 || outcode == 2 || outcode == 6)
                return false;
        } else if(clipEdgeOutcode == LEFT){
            if(outcode == 9 || outcode == 1 || outcode == 5)
                return false;
        }
    }

    return true;
}

void Viewport::drawPolygon(Polygon* polygon)
{
    QList<Coordinate*> vertices = polygon->getCoordinates();

    int v_count = vertices.count();

    GeometricShapeFactory* gf = GeometricShapeFactory::getInstance();

    QColor strokeColor = polygon->getStrokeColor();

    if(polygon->isFilled())
    {
        QList<Line*> clipPolygon;

        GeometricShapeFactory* gsf = GeometricShapeFactory::getInstance();

        Coordinate* clipPolA = new Coordinate(this->r_min, this->r_min);
        Coordinate* clipPolB = new Coordinate(this->r_min, this->r_max);
        Coordinate* clipPolC = new Coordinate(this->r_max, this->r_max);
        Coordinate* clipPolD = new Coordinate(this->r_max, this->r_min);

        clipPolygon << gsf->createLine(clipPolA, clipPolD);
        clipPolygon << gsf->createLine(clipPolD, clipPolC);
        clipPolygon << gsf->createLine(clipPolC, clipPolB);
        clipPolygon << gsf->createLine(clipPolB, clipPolA);

        QList<Coordinate*> outputList;
        foreach(Coordinate* v, vertices){
            outputList.append(this->transformCoordinate(v));
        }

        OutCode clipEdgesOutcode[4] = {BOTTOM, RIGHT, TOP, LEFT};

        QList<Coordinate*> inputList;
        int count = 0;
        foreach(Line* clipEdge, clipPolygon){
            OutCode clipEdgeOutcode = clipEdgesOutcode[count];

            inputList = outputList;
            outputList.clear();
            if(!inputList.empty()){
                Coordinate* s = inputList.last();

                foreach(Coordinate* e, inputList){

                    if(this->insideClipEdge(e, clipEdgeOutcode)){
                        if(!this->insideClipEdge(s, clipEdgeOutcode)){
                            Coordinate* c = clipEdge->computeIntersection(gsf->createLine(s, e));
                            if(c != NULL)
                                outputList.append(c);
                        }
                        outputList.append(e);
                    }else if(this->insideClipEdge(s, clipEdgeOutcode)){
                        Coordinate* a = clipEdge->computeIntersection(gsf->createLine(s, e));
                        if(a != NULL)
                            outputList.append(a);
                    }
                    s = e;
                }
            }
            count++;
        }

        QPolygonF pol;        
        foreach(Coordinate* coord, outputList)
        {
            pol << QPoint(coord->getXAxisCoord(),coord->getYAxisCoord());
        }

        QPen pen;
        pen.setColor(polygon->getStrokeColor());

        currentScene->addPolygon(pol,pen,pen.brush());
    }
    else
    {
        for(int i = 0; i < v_count - 1; i++)
        {
            Line* line = gf->createLine(vertices.at(i), vertices.at(i + 1), strokeColor);
            this->drawLine(line);
        }
        Line* line = gf->createLine(vertices.at(0), vertices.at(v_count - 1), strokeColor);
        this->drawLine(line);
    }
}

void Viewport::drawPoint(Point* point)
{
    Coordinate* coordinate = this->transformCoordinate(point->getCoordinate());

    double ax = coordinate->getXAxisCoord();
    double ay = coordinate->getYAxisCoord();

    currentScene->addLine(ax, ay, ax, ay, QPen(point->getStrokeColor()));
}

void Viewport::drawLine(Line *line)
{
    Coordinate *coordA = this->transformCoordinate(line->getCoordA());
    Coordinate *coordB = this->transformCoordinate(line->getCoordB());

    double ax = coordA->getXAxisCoord();
    double bx = coordB->getXAxisCoord();
    double ay = coordA->getYAxisCoord();
    double by = coordB->getYAxisCoord();

    //Line Clipping

    OutCode outcode0 = computeOutCode(ax, ay);
    OutCode outcode1 = computeOutCode(bx, by);

    bool accept = false;

    while (true) {
        if (!(outcode0 | outcode1)) {
            accept = true;
            break;
        } else if (outcode0 & outcode1) {
            break;
        } else {

            double x, y;

            OutCode outcodeOut = outcode0 ? outcode0 : outcode1;

            if (outcodeOut & TOP) {
                x = ax + (bx - ax) * (this->r_max - ay) / (by - ay);
                y = this->r_max;
            } else if (outcodeOut & BOTTOM) {
                x = ax + (bx - ax) * (this->r_min - ay) / (by - ay);
                y = this->r_min;
            } else if (outcodeOut & RIGHT) {
                y = ay + (by - ay) * (this->r_max - ax) / (bx - ax);
                x = this->r_max;
            } else if (outcodeOut & LEFT) {
                y = ay + (by - ay) * (this->r_min - ax) / (bx - ax);
                x = this->r_min;
            }

            if (outcodeOut == outcode0) {
                ax = x;
                ay = y;
                outcode0 = computeOutCode(ax, ay);
            } else {
                bx = x;
                by = y;
                outcode1 = computeOutCode(bx, by);
            }
        }
    }

    //Line Clipping End
    if(accept){
        currentScene->addLine(ax, ay, bx, by, QPen(line->getStrokeColor()));
    }

}

Coordinate* Viewport::transformCoordinate(Coordinate* coordinate) {
    double x = coordinate->getXAxisCoord();
    double y = coordinate->getYAxisCoord();

    double halfWindowWidth = 250;
    double halfWindowHeight = 250 ;

    double ax = halfWindowWidth * x - 20 + halfWindowWidth;
    double ay = -((halfWindowHeight + 20) * y + halfWindowHeight) + 460;

    return new Coordinate(ax,ay);
}

void Viewport::updateScene()
{
    this->drawWindow->setScene(currentScene);
}

OutCode Viewport::computeOutCode(double x, double y)
{
    OutCode code = INSIDE;

    if (x < this->r_min)
        code |= LEFT;
    else if (x > this->r_max)
        code |= RIGHT;

    if (y < this->r_min)
        code |= BOTTOM;
    else if (y > this->r_max)
        code |= TOP;

    return code;
}
