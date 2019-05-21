#ifndef PORT_H
#define PORT_H

#include<QQuickItem>

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
    Port* Target=nullptr;

    QPoint GetWorldPosition()
    {
        return Position+QPoint(static_cast<int>(Parent->position().x()),static_cast<int>(Parent->position().y()));
    }
};

#endif // PORT_H
