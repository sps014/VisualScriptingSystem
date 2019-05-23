#ifndef NUMBERBOXCORE_H
#define NUMBERBOXCORE_H


#include<resultparser.h>

#include<QPoint>
#include<QColor>
#include<QFont>

class NumberBox
{
public:
    int Width=100;
    int Height=26;
    QPoint Pos;
    QString Text="0";
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
    
    QString getValue() 
    {
        return Text;
    }

    int MaxCharacters=8;

};

#endif // NUMBERBOXCORE_H
