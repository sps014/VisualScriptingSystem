#include "port.h"
#include"NodeSystem/nodecore.h"

Port::Port()
{

}
QPoint Port::GetWorldPosition()
{
	return Position + QPoint(static_cast<int>(Parent->position().x()), static_cast<int>(Parent->position().y()));
}
Port *Port::GetPortNearestAtPosition(QPoint e,QObject *parent,QQuickItem *currentNode)
{
    Port *p=nullptr;
    QObjectList children=parent->children();
    for(int i=0;i<children.length();i++)
    {
        NodeCore* n=dynamic_cast<NodeCore*>(children[i]);
        if(n!=dynamic_cast<NodeCore*>(currentNode) &&n!=nullptr)
        {
            for(int j=0;j<n->inputPort.length();j++)
            {
                if(abs(e.x()-n->inputPort[j].GetWorldPosition().x())<=n->inputPort[j].Radius)
                {
                    if(abs(e.y()-n->inputPort[j].GetWorldPosition().y())<=n->inputPort[j].Radius)
                    {
                        p=&n->inputPort[j];
                    }
                }
            }
            for(int j=0;j<n->outputPort.length();j++)
            {
                if(abs(e.x()-n->outputPort[j].GetWorldPosition().x())<=n->outputPort[j].Radius)
                {
                    if(abs(e.y()-n->outputPort[j].GetWorldPosition().y())<=n->outputPort[j].Radius)
                    {
                        p=&n->outputPort[j];
                    }
                }
            }
        }
    }
    return p;
}
