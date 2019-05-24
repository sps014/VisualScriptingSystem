#include "econstnode.h"

EconstNode::EconstNode()
{
    this->setTitle("E");
    this->setHeight(120);
    this->setWidth(150);
    this->setPanelColor(QColor(Qt::green));
    this->setPanelGradColor(QColor(Qt::red));

    this->functionName="math.e";

    Port p;
    p.Parent=this;
    p.Position=QPoint(125,75);
    p.PortColor=panelGradColor();
    p.Type=PortType::OutPut;

    Label n;
    n.Text="const";
    n.Pos=QPoint(10,82);

    this->labelList.push_back(n);

    this->outputPort.push_back(p);
}
