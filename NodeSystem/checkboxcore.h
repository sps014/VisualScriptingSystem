#ifndef CHECKBOXCORE_H
#define CHECKBOXCORE_H
#include<QColor>
#include<QPoint>
#include<QPainter>
#include<QDebug>

enum CheckBoxState
{
    On=1,Off=0
};

class CheckBox
{
public:
QPoint Pos;
CheckBoxState State=CheckBoxState::Off;
QColor BackColor=QColor(52,52,52);
QColor FillColor=QColor(30,141,255);
QColor TickColor=QColor(Qt::white);
QColor BorderColor=QColor(Qt::black);
int Width=20;
int Height=20;

QString getValue()
{
    return State==1?"true":"false";
}
void DrawBody(QPainter *e)
{
    e->setPen(BorderColor);
    e->drawRect(Pos.x(),Pos.y(),Width,Height);

    if(State==CheckBoxState::Off)
    {
        e->fillRect(Pos.x(),Pos.y(),Width,Height,BackColor);
    }
    else
    {
        e->fillRect(Pos.x(),Pos.y(),Width,Height,FillColor);
        e->setPen(QPen(TickColor,2));
        QPoint p1=Pos+QPoint(Width/6,1*Height/2);
        QPoint p2=Pos+QPoint(2*Width/5,7*Height/9);
        QPoint p3=Pos+QPoint(4*Width/5,1*Height/5);

        e->drawLine(p1,p2);
        e->drawLine(p2,p3);
    }
}
};

#endif // CHECKBOXCORE_H
