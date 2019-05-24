#include "nodevaluefinder.h"

NodeValueFinder::NodeValueFinder(QObject *parent) : QObject(parent)
{

}
QString NodeValueFinder::getResult(BlackBoard *b)
{
    QList<NodeCore*> allNodes;
    QList<NodeCore*> inputNodeOnly;

    QObjectList children=b->children();
    for(int i=0;i<children.size();i++)
    {
        NodeCore *c=dynamic_cast<NodeCore*>(children[i]);
        if(c!=nullptr)
        {
            allNodes.push_back(c);
            if(c->outputPort.length()==0)
                inputNodeOnly.append(c);
        }
    }

    QString res="";
    for(int i=0;i<inputNodeOnly.size();i++)
    {

        res+=inputNodeOnly[i]->ResultString()+"\n";
    }

    ResultParser p;
    return p.OrderResult(res);

}

