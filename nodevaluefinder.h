#ifndef NODEVALUEFINDER_H
#define NODEVALUEFINDER_H

#include <QObject>
#include<blackboard.h>
#include<nodecore.h>

class NodeValueFinder : public QObject
{
    Q_OBJECT
public:
    explicit NodeValueFinder(QObject *parent = nullptr);
    Q_INVOKABLE void getResult(BlackBoard *);
signals:

public slots:
private:

};

#endif // NODEVALUEFINDER_H
