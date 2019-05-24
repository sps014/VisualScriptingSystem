#include "coshnode.h"

CosHNode::CosHNode()
{
    this->setTitle("Cosh");
    this->setHeight(120);
    this->setWidth(140);
    this->setPanelColor(QColor(195,20,50));
    this->setPanelGradColor(QColor(36,11,54));

    this->functionName="math.cosh";

    Port p1;
    p1.Parent=this;
    p1.Position=QPoint(20,75);
    p1.PortColor=panelColor();



    this->inputPort.push_back(p1);

    Port p3;

    p3.Parent=this;
    p3.Position=QPoint(125,75);
    p3.PortColor=panelColor();
    p3.Type=PortType::OutPut;

    this->outputPort.push_back(p3);

    Label l1;
    l1.Text="Value";
    l1.Pos=QPoint(40,85);



    this->labelList.push_back(l1);
}
