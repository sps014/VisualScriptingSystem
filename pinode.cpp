#include "pinode.h"

PiNode::PiNode()
{
    this->setTitle("PI");
    this->setHeight(120);
    this->setWidth(150);
    this->setPanelColor(QColor(Qt::green));
    this->setPanelGradColor(QColor(10,160,45));

    this->functionName="math.pi";

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
