#ifndef TEXTBOXCORE_H
#define TEXTBOXCORE_H


#include<QPoint>
#include<QColor>
#include<QFont>
#include<QApplication>
#include<QClipboard>
#include<QKeyEvent>
#include<QPainter>
#include<cctype>

class TextBox
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
    TextBox()
    {
        CursorPos=Text.length();
    }

    int MaxCharacters=8;

    QString getValue()
    {
        return Text;
    }
    void DrawBody(QPainter *e,TextBox *currentTextBox)
    {
        e->setPen(BorderColor);
        e->drawRect(Pos.x(),Pos.y(),Width,Height);
        QColor bcol=currentTextBox==nullptr?BackgroundColor:HighlightColor;
        e->fillRect(Pos.x(),Pos.y(),Width,Height,bcol);

        //Draw Text
        QFontMetrics f(Font);
        f.width(Text);
        int y=f.height();
        e->setPen(ForeGroundColor);
        e->setFont(Font);
        QString text=Text;

        //Draw Cursor
        if(currentTextBox!=nullptr)
            text.insert(CursorPos,'|');

        //Draw .. for extended Line
        if(Text.length()>MaxCharacters)
        {
            CursorPos=Text.length();
            text.resize(MaxCharacters-3);
            text+="..";
        }
        QPoint p=Pos+QPoint(5,2*y/3);
        e->drawText(p,text);
    }

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
        else if(e->key()==Qt::Key::Key_Delete)
        {
            Text.remove(CursorPos,1);
        }
        else if(e->key()==Qt::Key::Key_Left)
        {
            if(CursorPos>0)
            {
                CursorPos--;
            }
        }
        else if(e->key()==Qt::Key::Key_Right)
        {
            if(CursorPos<Text.length())
            {
                CursorPos++;
            }
        }
        else if(e->key()==Qt::Key::Key_CapsLock)
        {
        }
        else if(e->key()==Qt::Key::Key_Tab)
        {
            for(int i=0;i<8;i++){
                Text.insert(CursorPos,' ');
                CursorPos++;
            }
        }
        else if(isprint(e->key()))
        {
            if(e->modifiers().testFlag(Qt::ShiftModifier))
            {
                Text.insert(CursorPos,toupper(static_cast<char>(e->key())));
            }
            else
                Text.insert(CursorPos,tolower(static_cast<char>(e->key())));
            CursorPos++;
        }
        else if( e->modifiers().testFlag(Qt::ControlModifier))
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

#endif // TEXTBOXCORE_H
