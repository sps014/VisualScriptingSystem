#include "erfcnode.h"

ErfcNode::ErfcNode()
{
    this->setTitle("Erfc");
    this->setHeight(120);
    this->setWidth(140);
    this->setPanelColor(QColor(0,180,219));
    this->setPanelGradColor(QColor(0,131,176));

    this->functionName="math.erfc";

    Port p1;
    p1.Parent=this;
    p1.Position=QPoint(20,75);
    p1.PortColor=panelColor();



    this->inputPort.push_back(p1);

    Port p3;

    p3.Parent=this;
    p3.Position=QPoint(125,75);
    p3.PortColor=panelGradColor();
    p3.Type=PortType::OutPut;

    this->outputPort.push_back(p3);

    Label l1;
    l1.Text="Value";
    l1.Pos=QPoint(40,85);



    this->labelList.push_back(l1);
}
