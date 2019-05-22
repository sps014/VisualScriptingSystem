#include "addnode.h"

AddNode::AddNode()
{
    this->setTitle("Add");
    this->setHeight(180);
    this->setWidth(150);
    this->setPanelColor(QColor(7,138,123));
    this->setPanelGradColor(QColor(45,53,187));

    Port p1;
    p1.Parent=this;
    p1.Position=QPoint(20,80);
    p1.PortColor=QColor(7,138,123);

    Port p2;
    p2.Parent=this;
    p2.Position=QPoint(20,130);
    p2.PortColor=QColor(7,138,123);


    this->inputPort.push_back(p1);
    this->inputPort.push_back(p2);

    Port p3;

    p3.Parent=this;
    p3.Position=QPoint(125,105);
    p3.PortColor=QColor(7,138,123);
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
