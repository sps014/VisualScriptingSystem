#ifndef CONNECTOR_H
#define CONNECTOR_H

#include<QPoint>
#include<QColor>

class Connector
{
public:
    Connector();
    QPoint from;
    QPoint to;
    QColor lineColor;
    float lineWidth=2.5f;
};

#endif // CONNECTOR_H
