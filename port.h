#ifndef PORT_H
#define PORT_H

#include<QQuickItem>
#include<QList>

enum PortType
{
    Input,
    OutPut
};


class Port
{
public:
    Port();
    QQuickItem *Parent;
    float Radius=10;
    QColor PortColor=QColor(Qt::green);
    PortType Type=PortType::Input;
    QPoint Position;
    QList<Port*> Target;

    QPoint GetWorldPosition()
    {
        return Position+QPoint(static_cast<int>(Parent->position().x()),static_cast<int>(Parent->position().y()));
    }

    bool MultiConnections=false;

};

#endif // PORT_H
