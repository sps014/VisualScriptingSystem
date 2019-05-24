#include "hypotnode.h"

HypotNode::HypotNode()
{
    this->setTitle("Hypot");
    this->setHeight(180);
    this->setWidth(150);
    this->setPanelColor(QColor(121,159,12));
    this->setPanelGradColor(QColor(255,224,0));

    this->functionName="math.hypot";

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
    l1.Text="X";
    l1.Pos=QPoint(40,90);

    Label l2;
    l2.Text="Y";
    l2.Pos=QPoint(40,140);

    this->labelList.push_back(l1);
    this->labelList.push_back(l2);
}
