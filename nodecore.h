#ifndef NODECORE_H
#define NODECORE_H

#include<QtQuick/QQuickPaintedItem>

class NodeCore : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QColor BackgroundColor READ backgroundColor WRITE setBackgroundColor)
public:
    NodeCore();
    QColor backgroundColor() const;


protected:
    void paint(QPainter*)override;
signals:

public slots:
    void setBackgroundColor(const QColor backgroundColor);

};

#endif // NODECORE_H
