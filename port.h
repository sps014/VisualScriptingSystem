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
    Port* Target=nullptr;

	QPoint GetWorldPosition();

   // bool MultiConnections=false;

};

#endif // PORT_H
