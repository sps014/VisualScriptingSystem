#ifndef COMBOBOXCORE_H
#define COMBOBOXCORE_H
#include<QPoint>
#include<QColor>
#include<QFont>
#include<QApplication>
#include<QClipboard>
#include<QKeyEvent>
#include<QPainter>

class ComboBox
{
public:
    int Width=100;
    int Height=26;
    int ExtendedHeight=326;

    QPoint Pos;
    QFont Font=QFont("Segoe UI",12,-1,true);
    QColor BackgroundColor=QColor(60,60,60);
    QColor ForeGroundColor=QColor(Qt::white);
    QColor BorderColor=QColor(Qt::black);
    QColor HighlightColor=QColor(34,141,255);
    QList<QString> Choices;

    int CurrentChoice=0;
    QString CurrentString="";


    void DrawBody(QPainter *e,ComboBox *currentComboBox)
    {
        if(currentComboBox!=nullptr)
        {
            e->fillRect(Pos.x(),Pos.y(),Width,Height,HighlightColor);
        }
        else
        {
            e->fillRect(Pos.x(),Pos.y(),Width,Height,ForeGroundColor);
        }
    }
};

#endif // COMBOBOXCORE_H
