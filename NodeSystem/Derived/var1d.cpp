#include "var1d.h"

Var1D::Var1D()
{
    this->setTitle("Var 1D");
    this->setHeight(120);
    this->setWidth(150);
    this->setPanelColor(QColor(Qt::green));
    this->setPanelGradColor(QColor(10,160,45));

    this->functionName="";

    Port p;
    p.Parent=this;
    p.Position=QPoint(125,75);
    p.PortColor=panelGradColor();
    p.Type=PortType::OutPut;

    ComboBox n;
    n.Pos=QPoint(10,60);

    this->comboBoxList.push_back(n);
    //this->numberBoxList.push_back(n);

    //p.NumberBoxList.push_back(n);

    this->outputPort.push_back(p);


}
