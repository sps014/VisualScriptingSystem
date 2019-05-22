#ifndef LABELCORE_H
#define LABELCORE_H
#include<QString>
#include<QPoint>
#include<QColor>
#include<QFont>
#include<coreui.h>
class Label:public CoreUI
{
public:
    QString Text;
    QFont Font=QFont("Segoe UI",12,-1,true);
    QPoint Pos=QPoint(0,0);
    QColor Color=QColor(Qt::white);
};

#endif // LABELCORE_H
