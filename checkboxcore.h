#ifndef CHECKBOXCORE_H
#define CHECKBOXCORE_H
#include<QColor>
#include<QPoint>
#include<QPainter>
#include<QDebug>
#include<coreui.h>

enum CheckBoxState
{
    On,Off
};

class CheckBox:public CoreUI
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
};

#endif // CHECKBOXCORE_H
