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
    int ExtendedHeight=120;

    QPoint Pos;
    QFont Font=QFont("Segoe UI",12,-1,true);
    QColor BackgroundColor=QColor(60,60,60);
    QColor ForeGroundColor=QColor(Qt::white);
    QColor BorderColor=QColor(Qt::black);
    QColor HighlightColor=QColor(34,141,255);
	QColor ListExpandBackgroundColor = QColor(60,60,60);

    QList<QString> Choices;

    int CurrentChoice=0;
	QString CurrentString()
	{
		if (CurrentChoice >= 0 && CurrentChoice < Choices.length())
		{
			return Choices[CurrentChoice];
		}
		else
		{
			return "";
		}
	}

    void DrawBody(QPainter *e,ComboBox *currentComboBox)
    {
        if(currentComboBox!=nullptr)
        {
            QFontMetrics f(Font);
            f.width(Choices[CurrentChoice]);
            int y=f.height();
            e->fillRect(Pos.x(),Pos.y(),Width,ExtendedHeight,ListExpandBackgroundColor);

			//display arrow
			QFont ArrowFont = QFont("Arial");
			e->setFont(ArrowFont);
			e->drawText(QPoint(Width/2-5, 20)+Pos, "^");
			e->drawText(QPoint(Width/2-5, ExtendedHeight-4) + Pos, "v");
			e->setFont(Font);


			if (CurrentChoice != 0)
			{
				for (int i = CurrentChoice - 1; i <= CurrentChoice + 1; i++)
				{
					if (i >= 0 && i < Choices.length())
					{
							if (i == CurrentChoice)
							{
								e->fillRect(Pos.x(), Pos.y() + (1.5f) * y + y / 3, Width, Height, HighlightColor);
							}
							QPoint p = Pos + QPoint(5, Pos.y() + (i - CurrentChoice) * y + y / 3);
							e->drawText(p, Choices[i]);
					}
				}
			}
			else

			{
				for (int i = 0; i <= 2; i++)
				{
					if (i < Choices.length())
					{
						if (i == CurrentChoice)
						{
							e->fillRect(Pos.x(), Pos.y() + (0.5f) * y + y / 3, Width, Height, HighlightColor);
						}
						QPoint p = Pos + QPoint(5, Pos.y() + (i - CurrentChoice - 1) * y + y / 3);
						e->drawText(p, Choices[i]);
					}
				}
			}
			
        }
        else
        {
            //Draw Text
            QFontMetrics f(Font);
            f.width(Choices[CurrentChoice]);
            int y=f.height();
            e->setPen(ForeGroundColor);
            e->setFont(Font);
            QString text=Choices[CurrentChoice];
            QPoint p=Pos+QPoint(5,2*y/3);
            e->fillRect(Pos.x(),Pos.y(),Width,Height,BackgroundColor);
            e->drawText(p,text);

        }
    }
	void KeyPress(QKeyEvent* e,QQuickItem* node)
	{
		if (e->key() == Qt::Key::Key_Up)
		{
			if (CurrentChoice > 0)
			{
				CurrentChoice--;
			}
		}
		else if (e->key() == Qt::Key::Key_Return)
		{
			node->setFocus(false);
		}
		else if (e->key() == Qt::Key::Key_Down)
	
		{
			if (CurrentChoice < Choices.length() - 1)
			{
				CurrentChoice++;
			}
		}

	}
};

#endif // COMBOBOXCORE_H
