/*This Class is resposible for calculting raw output data by  traverses  all the nodes
 * */

#ifndef NODEVALUEFINDER_H
#define NODEVALUEFINDER_H

#include <QObject>
#include"blackboard.h"
#include"nodecore.h"

class NodeValueFinder : public QObject
{
    Q_OBJECT
public:
    explicit NodeValueFinder(QObject *parent = nullptr);


    //Method Taking PArent object where all nodes resides
    Q_INVOKABLE QString getResult(BlackBoard *);

};

#endif // NODEVALUEFINDER_H
