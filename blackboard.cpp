#include "blackboard.h"
#include<nodecore.h>
BlackBoard::BlackBoard()
{
    setAcceptedMouseButtons(Qt::AllButtons);
}
void BlackBoard::setBackgroundColor(const QColor color)
{
    if(m_backgroundColor==color)
        return;
    else
    {
        m_backgroundColor=color;
        emit onBackgroundColorChanged(m_backgroundColor);
        this->update();
    }
}
void BlackBoard::setLargeLineColor(const QColor color)
{
    if(m_largeLineColor==color)
        return;
    else
    {
        m_largeLineColor=color;
        this->update();
    }
}
void BlackBoard::setSmallLineColor(const QColor color)
{
    if(m_smallLineColor==color)
        return;
    else
    {
        m_smallLineColor=color;
        this->update();
    }
}
void BlackBoard::setDimensionSquare(const int a)
{
    if(m_squareDimension==a)
        return;
    else
    {
        m_squareDimension=a;
        m_lock_squareDimension=a;
        emit onSquareDimensionChanged(m_squareDimension);
        this->update();
    }
}

void BlackBoard::setSquareNumber(const int a)
{
    if(m_squareNumber==a)
        return;
    else
    {
        m_squareNumber=a;
        emit onSquareDimensionChanged(m_squareNumber);
        this->update();
    }
}

void BlackBoard::setOffsetX(const int x)
{
    if(m_offsetX==x)
        return;
    else
    {
        m_offsetX=x;
        if(m_offsetX>BigBlock())
        {
            m_offsetX=m_offsetX%BigBlock();
        }
        if (m_offsetX <0)
        {
             m_offsetX =BigBlock()-abs(m_offsetX)%BigBlock();
        }

        this->update();
    }
}

void BlackBoard::setOffsetY(const int y)
{
    if(m_offsetY==y)
        return;
    else
    {
        m_offsetY=y;
        if(m_offsetY>BigBlock())
        {
            m_offsetY=m_offsetY%BigBlock();
        }
        if (m_offsetY <0)
        {
             m_offsetY =BigBlock()-abs(m_offsetY)%BigBlock();
        }

        this->update();
    }
}

QColor BlackBoard::backgroundColor() const
{
    return m_backgroundColor;
}
QColor BlackBoard::smallLineColor() const
{
    return  m_smallLineColor;
}
QColor BlackBoard::largeLineColor() const
{
    return  m_largeLineColor;
}
int BlackBoard::squareDimension() const
{
    return  m_squareDimension;
}
int BlackBoard::squareNumber() const
{
    return  m_squareNumber;
}

int BlackBoard::offsetX() const
{
    return  m_offsetX;
}
int BlackBoard::offsetY() const
{
    return m_offsetY;
}

void BlackBoard::paint(QPainter *painter)
{
      painter->setRenderHints(QPainter::Antialiasing,true);
      painter->setPen(Qt::black);
      DrawGridLines(painter);
      DrawConnectors(painter);
      DrawCurrentLines(painter);

}
void BlackBoard::DrawGridLines(QPainter *painter)
{
    int Width=static_cast<int>(this->width());
    int Height=static_cast<int>(this->height());

    painter->fillRect(0,0,Width,Height,QBrush(m_backgroundColor));

    int vertLines=Width/m_squareDimension+1;
    int horizLines=Height/m_squareDimension+1;

    painter->drawRect(0,0,Width,Height);

    for(int i=-m_squareDimension;i<vertLines;i++)
    {
        if(i%m_squareNumber==0)
            painter->setPen(QPen(m_largeLineColor,2.5));
        else
            painter->setPen(QPen(m_smallLineColor,1));

        painter->drawLine(i*m_squareDimension+m_offsetX,0,i*m_squareDimension+m_offsetX,Height);
    }
    for(int i=-m_squareDimension;i<horizLines;i++)
    {
        if(i%m_squareNumber==0)
            painter->setPen(QPen(m_largeLineColor,2.5));
        else
            painter->setPen(QPen(m_smallLineColor,1));
        painter->drawLine(0,i*m_squareDimension+m_offsetY,Width,i*m_squareDimension+m_offsetY);
    }
}
int BlackBoard::BigBlock() const
{
    return m_squareNumber*m_squareDimension;
}

void BlackBoard::mousePressEvent(QMouseEvent *event)
{
    m_isMouseDown=true;
    m_mouseDownPosition=event->pos();
    this->setFocus(true);
}
void BlackBoard::mouseReleaseEvent(QMouseEvent*)
{
   m_isMouseDown=false;
   m_mouseDownPosition=QPoint(0,0);
}
void BlackBoard::mouseMoveEvent(QMouseEvent *event)
{
    if(m_isMouseDown)
    {
        QPoint p=event->pos()-m_mouseDownPosition;
        m_mouseDownPosition=event->pos();
        setOffsetX(m_offsetX+p.x());
        setOffsetY(m_offsetY+p.y());
        MoveNodes(p);
    }
}
void BlackBoard::MoveNodes(QPoint q)
{
    QObject* cur=static_cast<QObject*>(this);
    QObjectList allc=cur->children();
    for(int i=0;i<allc.length();i++)
    {
        QQuickItem* c=dynamic_cast<QQuickItem*>(allc[i]);
        if(c!=nullptr)
        {
             c->setPosition(c->position()+q);
        }
    }
}
void BlackBoard::wheelEvent(QWheelEvent *event)
{
    ZoomAmountModifier(event->delta());
}

void BlackBoard::ZoomAmountModifier(int amt)
{
    if(amt>0)
    {
        if(curZoom+0.05f<MaxZoom)
            curZoom+=0.05f;
    }
    else
    {
        if(curZoom-0.05f>MinZoom)
            curZoom-=0.05f;
    }
    zoom(curZoom);
}

void BlackBoard::zoom(float amount)
{

    m_squareDimension = static_cast<int>(amount * m_lock_squareDimension);
    ZoomNodes();
    update();
}
void BlackBoard::ZoomNodes()
{
    QObject* cur=static_cast<QObject*>(this);
    QObjectList allc=cur->children();
    for(int i=0;i<allc.length();i++)
    {
        QQuickItem* c=dynamic_cast<QQuickItem*>(allc[i]);
        if(c!=nullptr)
        {
             c->setScale(static_cast<qreal>(curZoom));
        }
    }
}

void BlackBoard::keyPressEvent(QKeyEvent *e)
{
    if( e->modifiers().testFlag(Qt::ControlModifier))
    {
        if(e->key()==Qt::Key::Key_Plus)
        {
                ZoomAmountModifier(1);

        }
        else if(e->key()==Qt::Key::Key_Minus)
        {
            ZoomAmountModifier(-1);

        }
    }
}
void BlackBoard::DrawConnectors(QPainter *painter)
{
    QObjectList pare=children();
    for(int i=0;i<pare.length();i++)
    {
        NodeCore* c=dynamic_cast<NodeCore*>(pare[i]);
        if(c!=nullptr)
        {

            for(int j=0;j<c->inputPort.length()&&c->inputPort[j].Target!=nullptr;j++)
            {

                QPoint p1=c->inputPort[j].Target->GetWorldPosition();
                QPoint p2 = c->inputPort[j].GetWorldPosition();

                painter->setPen(QPen(c->inputPort[j].PortColor,5));
                painter->drawLine(p1.x(),p1.y(),p1.x()+40,p1.y());
                painter->drawLine(p1.x()+40,p1.y(),p2.x()-40,p2.y());
                painter->drawLine(p2.x()-40,p2.y(),p2.x(),p2.y());
            }
        }
    }
}
void BlackBoard::DrawCurrentLines(QPainter *e)
{
    if(drawCurrentLine)
    {
        if(currentPortType==PortType::OutPut)
        {
            QPoint p1=fromCurrentLine;
            QPoint p2=toCurrentLine;

            e->setPen(QPen(currentLineColor,5));
            e->drawLine(p1.x(),p1.y(),p1.x()+40,p1.y());
            e->drawLine(p1.x()+40,p1.y(),p2.x()-40,p2.y());
            e->drawLine(p2.x()-40,p2.y(),p2.x(),p2.y());

        }
        else
        {
            QPoint p1=fromCurrentLine;
            QPoint p2=toCurrentLine;

            e->setPen(QPen(currentLineColor,5));
            e->drawLine(p1.x(),p1.y(),p1.x()-40,p1.y());
            e->drawLine(p1.x()-40,p1.y(),p2.x()+40,p2.y());
            e->drawLine(p2.x()+40,p2.y(),p2.x(),p2.y());
        }
    }
}

