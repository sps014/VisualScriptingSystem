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
    DrawPorts(painter);
    DrawLabels(painter);
    DrawCheckBoxes(painter);
    DrawNumberBoxes(painter);
    DrawComboBoxes(painter);
    DrawTextBoxes(painter);
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
      labelList[i].DrawBody(e);
    }
}
void NodeCore::DrawCheckBoxes(QPainter *e)
{
    for(int i=0;i<checkBoxList.length();i++)
    {
        checkBoxList[i].DrawBody(e);
    }
}

void NodeCore::DrawNumberBoxes(QPainter *e)
{
    for(int i=0;i<numberBoxList.length();i++)
    {
        numberBoxList[i].DrawBody(e,currentNumberBox);
    }
}
void NodeCore::DrawTextBoxes(QPainter *e)
{
    for(int i=0;i<textBoxList.length();i++)
    {
        textBoxList[i].DrawBody(e,currentTextBox);
    }
}

void NodeCore::DrawComboBoxes(QPainter *e)
{
    for(int i=0;i<comboBoxList.length();i++)
    {
        comboBoxList[i].DrawBody(e,currentComboBox);
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
        TextBoxClickHelper(e->pos());
        ComboBoxClickHelper(e->pos());
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
        currentTextBox=nullptr;
        currentComboBox=nullptr;
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

void NodeCore::ComboBoxClickHelper(QPoint e)
{
    ComboBox* c=GetClickedComboBox(e);
    if(c!=nullptr)
    {
        currentComboBox=c;
    }
    else
    {
        currentComboBox=nullptr;

    }
    update();

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
void NodeCore::TextBoxClickHelper(QPoint e)
{
    TextBox* c=GetClickedTextBox(e);
    if(c!=nullptr)
    {
        currentTextBox=c;
    }
    else
    {
        currentTextBox=nullptr;

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
        Port *p=nullptr;
        p=p->GetPortNearestAtPosition(e+ConvertQPoint(position()),parent(),this);
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
        Port *p=nullptr;
        p=p->GetPortNearestAtPosition(e+ConvertQPoint(position()),parent(),this);
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

ComboBox* NodeCore::GetClickedComboBox(QPoint e)
{
    ComboBox* p=nullptr;

    for(int i=0;i<comboBoxList.length();i++)
    {
        if(abs(e.x()-comboBoxList[i].Pos.x())<=comboBoxList[i].Width)
        {
            if(abs(e.y()-comboBoxList[i].Pos.y())<=comboBoxList[i].Height)
            {
                p=&comboBoxList[i];
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
TextBox* NodeCore::GetClickedTextBox(QPoint e)
{
    TextBox* p=nullptr;

    for(int i=0;i<textBoxList.length();i++)
    {
        if(abs(e.x()-textBoxList[i].Pos.x())<=textBoxList[i].Width)
        {
            if(abs(e.y()-textBoxList[i].Pos.y())<=textBoxList[i].Height)
            {
                p=&textBoxList[i];
            }
        }
    }
    return p;
}

void NodeCore::keyPressEvent(QKeyEvent *e)
{
    if(currentNumberBox!=nullptr)
    {
        currentNumberBox->KeyPress(e);
        update();
    }
    if(currentTextBox!=nullptr)
    {
        currentTextBox->KeyPress(e);
        update();
    }
	if (currentComboBox != nullptr)
	{
		currentComboBox->KeyPress(e,this);
		update();
	}
    if(e->key()==Qt::Key::Key_Delete)
    {
        for (int i=0;i<outputPort.length();i++)
        {
         Port *p=outputPort[i].InputPort;
         if(p!=nullptr)
         {
             p->Target=nullptr;
         }
        }
        this->deleteLater();
        Parent()->update();
    }
}

QString NodeCore::ResultString()
{
   QString Result=functionName;
   for(int j=0;j<outputPort.length();j++)
   {
       for(int k=0;k<outputPort[j].NumberBoxList.length();k++)
       {
           NumberBox nb= outputPort[j].NumberBoxList[k];

           for(int l=0;l<numberBoxList.length();l++)
           {
                   Result+=numberBoxList[l].Text+"";
           }
       }
	   for (int k = 0; k < outputPort[j].ComboBoxList.length(); k++)
	   {
		   ComboBox nb = outputPort[j].ComboBoxList[k];

		   for (int l = 0; l < comboBoxList.length(); l++)
		   {
			   Result += comboBoxList[l].CurrentString() + "";
		   }
	   }
       for(int k=0;k<outputPort[j].TextBoxList.length();k++)
       {
           TextBox nb= outputPort[j].TextBoxList[k];

           for(int l=0;l<textBoxList.length();l++)
           {
               if(textBoxList[l].Pos==nb.Pos)
                   Result+=textBoxList[l].Text+"";
           }
       }
   }
   if(inputPort.length()!=0)
   Result+="(";
   for(int i=0;i<inputPort.length();i++)
   {
       Port *p=inputPort[i].Target;
       if (p == nullptr)continue;
       Result+=dynamic_cast<NodeCore*>(inputPort[i].Target->Parent)->ResultString();
       if(i!=inputPort.length()-1)
           Result+=",";
   }
   if(inputPort.length()!=0)
   Result+=")";
   return Result;
}
