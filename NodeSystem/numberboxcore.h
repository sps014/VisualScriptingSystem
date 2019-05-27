#ifndef NUMBERBOXCORE_H
#define NUMBERBOXCORE_H


#include"resultparser.h"

#include<QPoint>
#include<QColor>
#include<QFont>
#include<QApplication>
#include<QClipboard>
#include<QKeyEvent>

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

    void KeyPress(QKeyEvent *e)
    {
        if(e->key()==Qt::Key::Key_Backspace)
        {
            if(CursorPos>0)
            {
                Text.remove(CursorPos-1,1);
                CursorPos--;
            }
        }
        if(e->key()==Qt::Key::Key_Delete)
        {
            Text.remove(CursorPos,1);
        }
        if(e->key()==Qt::Key::Key_Left)
        {
            if(CursorPos>0)
            {
                CursorPos--;
            }
        }
        if(e->key()==Qt::Key::Key_Right)
        {
            if(CursorPos<Text.length())
            {
                CursorPos++;
            }
        }
        if((e->key()>=48 && e->key()<=57 )|| e->key()==46)
        {
            Text.insert(CursorPos,static_cast<QChar>(e->key()));
            CursorPos++;
        }
        if(e->key()==Qt::Key::Key_Plus)
        {
            Text.insert(CursorPos,'+');
            CursorPos++;
        }
        if(e->key()==Qt::Key::Key_Minus)
        {
            Text.insert(CursorPos,'-');
            CursorPos++;
        }
        if(e->key()==Qt::Key::Key_E)
        {
            Text.insert(CursorPos,'E');
            CursorPos++;
        }

        if( e->modifiers().testFlag(Qt::ControlModifier))
        {
            if(e->key()==Qt::Key::Key_C)
            {
                QClipboard *clipboard = QApplication::clipboard();
                clipboard->setText(Text);
            }
            else if(e->key()==Qt::Key::Key_V)
            {
                QClipboard *clipboard = QApplication::clipboard();
                QRegExp re("\\d*");
                if (re.exactMatch(clipboard->text()))
                Text=clipboard->text();
                CursorPos=Text.length();
            }

        }

    }

};

#endif // NUMBERBOXCORE_H
