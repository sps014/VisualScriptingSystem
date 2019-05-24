#include "nodevaluefinder.h"

NodeValueFinder::NodeValueFinder(QObject *parent) : QObject(parent)
{

}

/*
 * Here this function Takes the parent object where all nodes resides and return the string transplied output
 */
QString NodeValueFinder::getResult(BlackBoard *b)
{

    QList<NodeCore*> allNodes; //List of all Nodes Residing on parent
    QList<NodeCore*> inputNodeOnly; //List of all Nodes  on parent with input port only

    QObjectList children=b->children(); //Gets All object of the Parent
    for(int i=0;i<children.size();i++)
    {
        NodeCore *c=dynamic_cast<NodeCore*>(children[i]); //Try Converting to NodeCore Type of object
        if(c!=nullptr)    
        {
            allNodes.push_back(c); //If successful the we got a node add to our node

            //Try checking if it has zero output ports and update inport Port List
            if(c->outputPort.length()==0)
                inputNodeOnly.append(c);
        }
    }

    //our Raw Result Input string

    QString res="";

    //All Input Nodes Are only responsible for creating output hence transverse then solve them

    for(int i=0;i<inputNodeOnly.size();i++)
    {

        res+=inputNodeOnly[i]->ResultString()+"\r\n";
    }

    //Basic Python Transpiler Class
    ResultParser p;

    // Returns Transpiled Output
    return p.OrderResult(res);

}

