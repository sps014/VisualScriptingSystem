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
};

#endif // CHECKBOXCORE_H
