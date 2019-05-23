#ifndef CURSOR_H
#define CURSOR_H

#include <QObject>
#include<QCursor>
class Cursor : public QObject
{
    Q_OBJECT
public:
    explicit Cursor(QObject *parent = nullptr);
    Q_INVOKABLE QPoint getCursor(int x,int y) {return QCursor::pos()-QPoint(x,y); } //Get

signals:

public slots:

};

#endif // CURSOR_H
