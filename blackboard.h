#ifndef BLACKBOARD_H
#define BLACKBOARD_H

#include <QtQuick/QQuickPaintedItem>
#include<QPainter>
#include<math.h>
#include<QList>
#include"port.h"

class BlackBoard : public QQuickPaintedItem
{
    Q_OBJECT

    Q_PROPERTY(QColor backgroundColor READ backgroundColor WRITE setBackgroundColor NOTIFY onBackgroundColorChanged)
    Q_PROPERTY(QColor smallLineColor READ smallLineColor WRITE setSmallLineColor)
    Q_PROPERTY(QColor largeLineColor READ largeLineColor WRITE setLargeLineColor)

    Q_PROPERTY(int squareDimension READ squareDimension WRITE setDimensionSquare NOTIFY onSquareDimensionChanged)
    Q_PROPERTY(int squareNumber READ squareNumber WRITE setSquareNumber NOTIFY onSquareNumberChanged)
    Q_PROPERTY(int offsetX READ offsetX WRITE setOffsetX)
    Q_PROPERTY(int offsetY READ offsetY WRITE setOffsetY)
    Q_PROPERTY(bool rightClicked READ rightClicked NOTIFY onRightMouseClickChanged)

public:
    BlackBoard();
    QColor backgroundColor() const;
    QColor smallLineColor()const;
    QColor largeLineColor()const;
    int squareDimension() const;
    int squareNumber()const;
    int offsetX()const;
    int offsetY()const;

    Q_INVOKABLE
    void zoom(float);

    QPoint fromCurrentLine;
    QPoint toCurrentLine;
    bool drawCurrentLine;
    PortType currentPortType;
    QColor currentLineColor;
    bool rightClicked()const;

protected:
     void paint(QPainter*)override;
     void mouseMoveEvent(QMouseEvent*) override;
     void mousePressEvent(QMouseEvent*) override;
     void mouseReleaseEvent(QMouseEvent*) override;
     void wheelEvent(QWheelEvent*) override;
     void keyPressEvent(QKeyEvent*) override;

signals:
    void onBackgroundColorChanged(const QColor &color);
    void onSquareDimensionChanged(const int &dim);
    void onSquareNumberChanged(const int &n);
    void onRightMouseClickChanged(const bool&);

public slots:
    void setBackgroundColor(const QColor backgroundColor);
    void setSmallLineColor(const QColor color);
    void setLargeLineColor(const QColor color);

    void setDimensionSquare(const int a);
    void setSquareNumber(const int n);
    void setOffsetX(const int x);
    void setOffsetY(const int y);

private:
    QColor m_backgroundColor=QColor(50,50,50);
    QColor m_smallLineColor=QColor(38,38,38);
    QColor m_largeLineColor=QColor(28,28,28);

    int m_squareDimension=25;
    int m_lock_squareDimension=25;
    int m_squareNumber=5;
    int m_offsetX=0;
    int m_offsetY=0;

    float curZoom = 1;
    float MaxZoom=1.25f;
    float MinZoom=0.75f;

    QPoint m_mouseDownPosition;
    bool m_isMouseDown;

    void DrawGridLines(QPainter*);
    void DrawConnectors(QPainter*);

    int BigBlock() const;

    void ZoomAmountModifier(int);
    void MoveNodes(QPoint);
    void ZoomNodes();

    void DrawCurrentLines(QPainter*);

    bool m_righClicked;

};

#endif // BLACKBOARD_H
