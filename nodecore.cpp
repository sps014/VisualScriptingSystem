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
    DrawRopes();
    DrawBody(painter);
    DrawTitle(painter);
    DrawPorts(painter);
    DrawLabels(painter);
    DrawCheckBoxes(painter);
    DrawNumberBoxes(painter);
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
void NodeCore::DrawPorts(QPainter *e)
{
    e->setRenderHint(QPainter::RenderHint::Antialiasing,true);
    for(int i=0;i<inputPort.length();i++)
    {
        e->setBrush(inputPort[i].PortColor);
        int r=static_cast<int>(inputPort[i].Radius);
        e->drawEllipse(inputPort[i].Position,r,r);
    }
    for(int i=0;i<outputPort.length();i++)
    {
        e->setBrush(outputPort[i].PortColor);
        int r=static_cast<int>(outputPort[i].Radius);
        e->drawEllipse(outputPort[i].Position,r,r);
    }
}
void NodeCore::DrawLabels(QPainter *e)
{
    for(int i=0;i<labelList.length();i++)
    {
        e->setPen(labelList[i].Color);
        e->setFont(labelList[i].Font);
        e->drawText(labelList[i].Pos,labelList[i].Text);
    }
}
void NodeCore::DrawCheckBoxes(QPainter *e)
{
    for(int i=0;i<checkBoxList.length();i++)
    {
        CheckBox *c=&checkBoxList[i];
        e->setPen(c->BorderColor);
        e->drawRect(c->Pos.x(),c->Pos.y(),c->Width,c->Height);
        if(c->State==CheckBoxState::Off)
        {
            e->fillRect(c->Pos.x(),c->Pos.y(),c->Width,c->Height,c->BackColor);
        }
        else
        {
            e->fillRect(c->Pos.x(),c->Pos.y(),c->Width,c->Height,c->FillColor);
            e->setPen(QPen(c->TickColor,2));
            QPoint p1=c->Pos+QPoint(c->Width/6,1*c->Height/2);
            QPoint p2=c->Pos+QPoint(2*c->Width/5,7*c->Height/9);
            QPoint p3=c->Pos+QPoint(4*c->Width/5,1*c->Height/5);

            e->drawLine(p1,p2);
            e->drawLine(p2,p3);
        }
    }
}

void NodeCore::DrawNumberBoxes(QPainter *e)
{
    for(int i=0;i<numberBoxList.length();i++)
    {
        NumberBox *n=&numberBoxList[i];
        e->setPen(n->BorderColor);
        e->drawRect(n->Pos.x(),n->Pos.y(),n->Width,n->Height);
        QColor bcol=currentNumberBox==nullptr?n->BackgroundColor:n->HighlightColor;
        e->fillRect(n->Pos.x(),n->Pos.y(),n->Width,n->Height,bcol);
        QFontMetrics f(n->Font);
        int x=f.width(n->Text);
        int y=f.height();
        e->setPen(n->ForeGroundColor);
        e->setFont(n->Font);
        QString text=n->Text;
        if(currentNumberBox!=nullptr)
            text.insert(n->CursorPos,'|');
        QPoint p=n->Pos+QPoint(5,2*y/3);
        e->drawText(p,text);
    }
}

bool NodeCore::IsMouseOnHeader(QPoint p)
{
    if(p.x()>0&&p.x()<=width())
    {
        if(p.y()>0 && p.y()<=panelHeight())
            return true;
    }
    return false;
}


void NodeCore::mousePressEvent(QMouseEvent *e)
{
    setFocus(true);
    lastMousePosition=e->pos();
    if(IsMouseOnHeader(e->pos()))
    {
        mouseClickedOnHeader=true;
    }
    else
    {
        PortClickHelper(e->pos());
        CheckBoxClickHelper(e->pos());
        NumberBoxClickHelper(e->pos());
    }
}


void NodeCore::mouseMoveEvent(QMouseEvent *e)
{
    if(mouseClickedOnHeader)
    {
        QPoint curr=QPoint(static_cast<int>(position().x()),static_cast<int>(position().y()));
        QPoint l=curr-lastMousePosition+e->pos();
        setPosition(l);
    }
    PortLineMoveHelper(e->pos());

}

void NodeCore::mouseReleaseEvent(QMouseEvent *e)
{
    mouseClickedOnHeader=false;
    ReleasePortTargeter(e->pos());

}
void NodeCore::focusOutEvent(QFocusEvent *e)
{
    if(e->lostFocus())
    {
        currentNumberBox=nullptr;
        update();
    }
}

Port *NodeCore::GetClickedPort(QPoint e)
{
    Port* p=nullptr;

    for(int i=0;i<outputPort.length();i++)
    {
        if(abs(e.x()-outputPort[i].Position.x())<=outputPort[i].Radius)
        {
            if(abs(e.y()-outputPort[i].Position.y())<=outputPort[i].Radius)
            {
                p=&outputPort[i];
            }
        }
    }
    for(int i=0;i<inputPort.length();i++)
    {
        if(abs(e.x()-inputPort[i].Position.x())<=inputPort[i].Radius)
        {
            if(abs(e.y()-inputPort[i].Position.y())<=inputPort[i].Radius)
            {
                p=&inputPort[i];
            }
        }
    }
    return p;
}
void NodeCore::DrawRopes()
{
	if (inputPort.length() == 0 && outputPort.length() == 0)
	{
		Port P, p,p1,p2;
		P.Position = QPoint(180, 75);
		p.Position = QPoint(20, 75);
		P.Type = PortType::OutPut;
		p.Type = PortType::Input;
		p.PortColor = QColor(Qt::yellow);
		QObject* q = parent()->findChild<QObject*>("node2");
		//P.MultiConnections=true;
		p.Parent = this;
		P.Parent = this;
		if (q == nullptr)
		{
			return;
		}

		if (this != q)
		{
			p1 = P;
			p1.Position += QPoint(0, 30);
			outputPort.push_back(P);
			p1.PortColor = QColor(Qt::magenta);
            Label l;
            l.Text="X";
            l.Pos=P.Position-QPoint(40,-5);
            labelList.push_back(l);
            NumberBox n;
            n.Pos=QPoint(20,65);
            numberBoxList.append(n);
			outputPort.push_back(p1);

		}
		else
		{
			p2 = p;
			p2.Position += QPoint(0, 30);
			inputPort.push_back(p);
			p2.PortColor = QColor(Qt::magenta);
			inputPort.push_back(p2);
		}
		update();
	}
}

void NodeCore::PortClickHelper(QPoint e)
{
    Port* p=GetClickedPort(e);
    if(p!=nullptr)
    {
        BlackBoard* b=Parent();
        b->drawCurrentLine=true;
        b->currentPortType=p->Type;
        b->currentLineColor=p->PortColor;
        b->fromCurrentLine=p->GetWorldPosition();
        b->toCurrentLine=e+ConvertQPoint(position());
       if(p->Type==PortType::Input)
       {
           inputPortClicked=true;

       }
       else
       {
           outPutPortClicked=true;
       }
       currentPort=p;
    }
}

void NodeCore::CheckBoxClickHelper(QPoint e)
{
    CheckBox* c=GetClickedCheckBox(e);
    if(c!=nullptr)
    {
        if(c->State==CheckBoxState::On)
        {
            c->State=CheckBoxState::Off;
        }
        else
        {
            c->State=CheckBoxState::On;
        }
        update();
    }
}
void NodeCore::NumberBoxClickHelper(QPoint e)
{
    NumberBox* c=GetClickedNumberBox(e);
    if(c!=nullptr)
    {
        currentNumberBox=c;
    }
    else
    {
        currentNumberBox=nullptr;

    }
    update();

}
void NodeCore::PortLineMoveHelper(QPoint e)
{
    if(inputPortClicked||outPutPortClicked)
    {
        BlackBoard* b=Parent();
        b->toCurrentLine=e+ConvertQPoint(position());
        b->fromCurrentLine=currentPort->GetWorldPosition();
    }
    dynamic_cast<QQuickItem*>(parent())->update();
}
void NodeCore::ReleasePortTargeter(QPoint e)
{
	BlackBoard* b = Parent();
    b->drawCurrentLine=false;
    b->update();
    if(inputPortClicked)
    {
        inputPortClicked=false;
        Port *p=GetPortNearestAtPosition(e+ConvertQPoint(position()));
        if(p!=nullptr)
        {
            if(p->Type==PortType::OutPut)
                BindPort(p,currentPort);
        }
        else
        {
            ConnectionRemover();
        }
    }
    if(outPutPortClicked)
    {
        outPutPortClicked=false;
        Port *p=GetPortNearestAtPosition(e+ConvertQPoint(position()));
        if(p!=nullptr)
        {
            if(p->Type==PortType::Input)
                BindPort(currentPort,p);
        }
        else
        {
            ConnectionRemover();
        }
    }
    currentPort=nullptr;
}

QPoint NodeCore::ConvertQPoint(QPointF q)
{
    return QPoint(static_cast<int>(q.x()),static_cast<int>(q.y()));
}

Port* NodeCore::GetPortNearestAtPosition(QPoint e)
{
    Port *p=nullptr;
    QObjectList children=parent()->children();
    for(int i=0;i<children.length();i++)
    {
        NodeCore* n=dynamic_cast<NodeCore*>(children[i]);
        if(n!=this&&n!=nullptr)
        {
            for(int j=0;j<n->inputPort.length();j++)
            {
                if(abs(e.x()-n->inputPort[j].GetWorldPosition().x())<=n->inputPort[j].Radius)
                {
                    if(abs(e.y()-n->inputPort[j].GetWorldPosition().y())<=n->inputPort[j].Radius)
                    {
                        p=&n->inputPort[j];
                    }
                }
            }
            for(int j=0;j<n->outputPort.length();j++)
            {
                if(abs(e.x()-n->outputPort[j].GetWorldPosition().x())<=n->outputPort[j].Radius)
                {
                    if(abs(e.y()-n->outputPort[j].GetWorldPosition().y())<=n->outputPort[j].Radius)
                    {
                        p=&n->outputPort[j];
                    }
                }
            }
        }
    }
    return p;
}

void NodeCore::BindPort(Port* p1, Port* p2)
{
    p2->Target=p1;
    p1->InputPort=p2;
}

bool NodeCore::FindInList(QList<Port*> list,Port* p)
{
    return  (std::find(list.begin(), list.end(), p) != list.end());
}

BlackBoard* NodeCore::Parent()
{
	return dynamic_cast<BlackBoard*>(parent());
}
void NodeCore::ConnectionRemover()
{
    if(currentPort==nullptr)
    {
        return;
    }
    if(currentPort->Type==PortType::Input)
    {
        currentPort->Target=nullptr;
    }
    else
    {
        if(currentPort->InputPort!=nullptr)
        currentPort->InputPort->Target=nullptr;
    }
}
CheckBox* NodeCore::GetClickedCheckBox(QPoint e)
{
    CheckBox* p=nullptr;

    for(int i=0;i<checkBoxList.length();i++)
    {
        if(abs(e.x()-checkBoxList[i].Pos.x())<=checkBoxList[i].Width)
        {
            if(abs(e.y()-checkBoxList[i].Pos.y())<=checkBoxList[i].Height)
            {
                p=&checkBoxList[i];
            }
        }
    }
    return p;
}

NumberBox* NodeCore::GetClickedNumberBox(QPoint e)
{
    NumberBox* p=nullptr;

    for(int i=0;i<numberBoxList.length();i++)
    {
        if(abs(e.x()-numberBoxList[i].Pos.x())<=numberBoxList[i].Width)
        {
            if(abs(e.y()-numberBoxList[i].Pos.y())<=numberBoxList[i].Height)
            {
                p=&numberBoxList[i];
            }
        }
    }
    return p;
}

void NodeCore::keyPressEvent(QKeyEvent *e)
{
    if(currentNumberBox!=nullptr)
    {
        if(e->key()==Qt::Key::Key_Backspace)
        {
            if(currentNumberBox->CursorPos>0)
            {
                currentNumberBox->Text.remove(currentNumberBox->CursorPos-1,1);
                currentNumberBox->CursorPos--;
            }
        }
        if(e->key()==Qt::Key::Key_Delete)
        {
           // if(currentNumberBox->CursorPos<currentNumberBox->Text.length())
            {
                currentNumberBox->Text.remove(currentNumberBox->CursorPos,1);
            }
        }
        if(e->key()==Qt::Key::Key_Left)
        {
            if(currentNumberBox->CursorPos>0)
            {
                currentNumberBox->CursorPos--;
            }
        }
        if(e->key()==Qt::Key::Key_Right)
        {
            if(currentNumberBox->CursorPos<currentNumberBox->Text.length())
            {
                currentNumberBox->CursorPos++;
            }
        }
        if((e->key()>=48 && e->key()<=57 )|| e->key()==46)
        {
            currentNumberBox->Text.insert(currentNumberBox->CursorPos,static_cast<QChar>(e->key()));
            currentNumberBox->CursorPos++;
        }
        update();
    }
}
