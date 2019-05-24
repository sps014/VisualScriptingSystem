#include "modulonode.h"

ModuloNode::ModuloNode()
{

    this->setTitle("Modulo");
    this->setHeight(180);
    this->setWidth(150);
    this->setPanelColor(QColor(240,152,25));
    this->setPanelGradColor(QColor(237, 222, 93));

    this->functionName="modulo";

    Port p1;
    p1.Parent=this;
    p1.Position=QPoint(20,80);
    p1.PortColor=panelColor();

    Port p2;
    p2.Parent=this;
    p2.Position=QPoint(20,130);
    p2.PortColor=panelColor();


    this->inputPort.push_back(p1);
    this->inputPort.push_back(p2);

    Port p3;

    p3.Parent=this;
    p3.Position=QPoint(125,105);
    p3.PortColor=panelGradColor();
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
