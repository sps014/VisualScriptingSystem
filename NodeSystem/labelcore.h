#ifndef LABELCORE_H
#define LABELCORE_H
#include<QString>
#include<QPoint>
#include<QColor>
#include<QFont>
#include<QPainter>

class Label
{
public:
    QString Text;
    QFont Font=QFont("Segoe UI",12,-1,true);
    QPoint Pos=QPoint(0,0);
    QColor Color=QColor(Qt::white);

    QString getValue() 
    {
        return Text;
    }

    void DrawBody(QPainter *e)
    {
        e->setPen(Color);
        e->setFont(Font);
        e->drawText(Pos,Text);
    }
};

#endif // LABELCORE_H
