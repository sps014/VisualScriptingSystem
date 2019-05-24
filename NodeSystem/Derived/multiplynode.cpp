#include "multiplynode.h"

Multiply::Multiply()
{
    this->setTitle("Multiply");
    this->setHeight(180);
    this->setWidth(150);
    this->setPanelColor(QColor(142,68,173));
    this->setPanelGradColor(QColor(86, 101, 115));

    this->functionName="multiply";

    Port p1;
    p1.Parent=this;
    p1.Position=QPoint(20,80);
    p1.PortColor=this->panelColor();

    Port p2;
    p2.Parent=this;
    p2.Position=QPoint(20,130);
    p2.PortColor=this->panelColor();


    this->inputPort.push_back(p1);
    this->inputPort.push_back(p2);

    Port p3;

    p3.Parent=this;
    p3.Position=QPoint(125,105);
    p3.PortColor=this->panelGradColor();
    p3.Type=PortType::OutPut;

    this->outputPort.push_back(p3);

    Label l1;
    l1.Text="A";
    l1.Pos=QPoint(40,90);

    Label l2;
    l2.Text="B";
    l2.Pos=QPoint(40,140);

    this->labelList.push_back(l1);
    this->labelList.push_back(l2);
}
