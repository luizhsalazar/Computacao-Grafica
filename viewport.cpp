#include "viewport.h"

Viewport::Viewport(double viewPortSize, QGraphicsView* drawWindow)
{
    this->drawWindow = drawWindow;

    this->r_min = 10;
    this->r_max = viewPortSize - this->r_min;

    this->xvpmax = viewPortSize;
    this->yvpmax = viewPortSize;

    this->currentScene = new QGraphicsScene(0, 0, this->xvpmax, this->yvpmax);
    this->currentScene->addRect(this->r_min, this->r_min, this->r_max - this->r_min, this->r_max - this->r_min);
    this->updateScene();
}

void Viewport::prepareToRedraw(double xwmin, double ywmin, double xwmax, double ywmax)
{
    this->xwmax = xwmax;
    this->ywmax = ywmax;
    this->xwmin = xwmin;
    this->ywmin = ywmin;

    this->currentScene->clear();

    this->currentScene->addRect(this->r_min, this->r_min, this->r_max - this->r_min, this->r_max - this->r_min);
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
    }

}

void Viewport::drawPolygon(Polygon* polygon)
{
    QList<Coordinate*> vertices = polygon->getCoordinates();

    int v_count = vertices.count();

    GeometricShapeFactory* gf = GeometricShapeFactory::getInstance();

    for(int i = 0; i < v_count - 1; i++)
    {
        Line* line = gf->createLine(vertices.at(i), vertices.at(i + 1));
        this->drawLine(line);
    }
    Line* line = gf->createLine(vertices.at(v_count - 1), vertices.at(0));
    this->drawLine(line);
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

    currentScene->addLine(ax, ay, bx, by, QPen(line->getStrokeColor()));
}

Coordinate* Viewport::transformCoordinate(Coordinate* coordinate) {
    double x = coordinate->getXAxisCoord();
    double y = coordinate->getYAxisCoord();

    double windowWidth = xwmax - xwmin;
    double windowHeigth = ywmax - ywmin;

    double ax = r_min + double((x - xwmin) * (this->r_max - r_min)) / windowWidth;
    double ay = r_min + (1 - (double((y - ywmin))/(windowHeigth))) * (this->r_max - r_min);

    return new Coordinate(ax,ay);
}

void Viewport::updateScene()
{
    this->drawWindow->setScene(currentScene);
}
