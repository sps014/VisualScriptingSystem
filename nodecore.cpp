#include "nodecore.h"

NodeCore::NodeCore()
{
    setAcceptedMouseButtons(Qt::AllButtons);
}

void NodeCore::setBackgroundColor(const QColor color)
{
    if(color==m_backgroundColor)
        return;
    else
    {
        m_backgroundColor=color;
        update();
    }
}
void NodeCore::setHighlightColor(const QColor color)
{
    if(color==m_highlightColor)
        return;
    else
    {
        m_highlightColor=color;
        update();
    }
}
void NodeCore::setPanelColor(const QColor color)
{
    if(color==m_panelColor)
        return;
    else
    {
        m_panelColor=color;
        update();
    }
}
void NodeCore::setPanelGradColor(const QColor color)
{
    if(color==m_panelGradColor)
        return;
    else
    {
        m_panelGradColor=color;
        update();
    }
}
void NodeCore::setTitleFont(const QFont f)
{
    if(f==m_titleFont)
        return;
    else
    {
        m_titleFont=f;
        update();
    }
}
void NodeCore::setPanelHeight(const int h)
{
    if(h==m_panelHeight)
        return;
    else
    {
        m_panelHeight=h;
        update();
    }
}
void NodeCore::setTitleColor(const QColor c)
{
    if(c==m_titleColor)
        return;
    else
    {
        m_titleColor=c;
        update();
    }
}
void NodeCore::setTitle(const QString c)
{
    if(c==m_title)
        return;
    else
    {
        m_title=c;
        update();
    }
}


QColor NodeCore::backgroundColor() const
{
    return m_backgroundColor;
}
QColor NodeCore::highlightColor() const
{
    return m_highlightColor;
}
QColor NodeCore::panelColor() const
{
    return m_panelColor;
}
QColor NodeCore::panelGradColor() const
{
    return m_panelGradColor;
}
QColor NodeCore::titleColor() const
{
    return m_titleColor;
}
QString NodeCore::title() const
{
    return m_title;
}
QFont NodeCore::titleFont() const
{
    return m_titleFont;
}
int NodeCore::panelHeight() const
{
    return m_panelHeight;
}




void NodeCore::paint(QPainter *painter)
{
    DrawBody(painter);
    DrawTitle(painter);
}
void NodeCore::DrawBody(QPainter *painter)
{
    int w=static_cast<int>(width());
    int h=static_cast<int>(height());

    painter->fillRect(0,0,w,h,QBrush(m_backgroundColor));

    QLinearGradient g(QPoint(0,0),QPoint(w,m_panelHeight));
    g.setColorAt(0,m_panelColor);
    g.setColorAt(1,m_panelGradColor);
    painter->fillRect(0,0,w,m_panelHeight,QBrush(g));


    painter->setPen(m_highlightColor);
    painter->drawRect(1,1,w-2,h-2);
    painter->drawRect(1,1,w,m_panelHeight-2);


}
void NodeCore::DrawTitle(QPainter *e)
{
    e->setPen(m_titleColor);
    e->setFont(m_titleFont);
    QFontMetrics f(m_titleFont);
    int x=f.width(m_title);
    int y=f.height();
    e->drawText(x/2,y,m_title);
}

void NodeCore::mouseMoveEvent(QMouseEvent *e)
{
    if(isMouseDown)
    {
        QPoint curr=QPoint(static_cast<int>(position().x()),static_cast<int>(position().y()));
        QPoint l=curr-lastMousePosition+e->pos();
        setPosition(l);
    }
}


void NodeCore::mousePressEvent(QMouseEvent *e)
{
    isMouseDown=true;
    lastMousePosition=e->pos();
}
void NodeCore::mouseReleaseEvent(QMouseEvent *)
{
    isMouseDown=false;
}
