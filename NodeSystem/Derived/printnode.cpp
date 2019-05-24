#include "printnode.h"

PrintNode::PrintNode()
{
    this->setTitle("Print");
    this->setHeight(120);
    this->setWidth(150);
    this->setPanelColor(QColor(165,42,42));
    this->setPanelGradColor(QColor(Qt::yellow));

    this->functionName="print";

    Port p;
    p.Parent=this;
    p.Position=QPoint(20,70);
    p.PortColor=panelGradColor();
    this->inputPort.push_back(p);

}
