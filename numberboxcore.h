#ifndef NUMBERBOXCORE_H
#define NUMBERBOXCORE_H

#include<QPoint>
#include<QColor>
#include<coreui.h>
#include<QFont>

class NumberBox:public CoreUI
{
public:
    int Width=100;
    int Height=26;
    QPoint Pos;
    QString Text="";
    QFont Font=QFont("Segoe UI",12,-1,true);
    QColor BackgroundColor=QColor(60,60,60);
    QColor ForeGroundColor=QColor(Qt::white);
    QColor BorderColor=QColor(Qt::black);
    QColor HighlightColor=QColor(34,141,255);
    int CursorPos=0;
    NumberBox()
    {
        CursorPos=Text.length();
    }
    double value()const
    {
        return Text.toDouble();
    }

};

#endif // NUMBERBOXCORE_H
