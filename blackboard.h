#ifndef BLACKBOARD_H
#define BLACKBOARD_H

#include <QtQuick/QQuickPaintedItem>
#include<QPainter>
#include<math.h>

class BlackBoard : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QColor backgroundColor READ backgroundColor WRITE setBackgroundColor NOTIFY onBackgroundColorChanged)
    Q_PROPERTY(int squareDimension READ squareDimension WRITE setDimensionSquare NOTIFY onSquareDimensionChanged)
    Q_PROPERTY(int squareNumber READ squareNumber WRITE setSquareNumber NOTIFY onSquareNumberChanged)
    Q_PROPERTY(int offsetX READ offsetX WRITE setOffsetX)
    Q_PROPERTY(int offsetY READ offsetY WRITE setOffsetY)

public:
    BlackBoard();
    QColor backgroundColor() const;
    int squareDimension() const;
    int squareNumber()const;
    int offsetX()const;
    int offsetY()const;

protected:
     void paint(QPainter*)override;
     void mouseMoveEvent(QMouseEvent*) override;
     void mousePressEvent(QMouseEvent*) override;
     void mouseReleaseEvent(QMouseEvent*) override;
     void wheelEvent(QWheelEvent*) override;

signals:
    void onBackgroundColorChanged(const QColor &color);
    void onSquareDimensionChanged(const int &dim);
    void onSquareNumberChanged(const int &n);


public slots:
    void setBackgroundColor(const QColor backgroundColor);
    void setDimensionSquare(const int a);
    void setSquareNumber(const int n);
    void setOffsetX(const int x);
    void setOffsetY(const int y);

private:
    QColor m_backgroundColor;
    int m_squareDimension;
    int m_squareNumber;
    int m_offsetX;
    int m_offsetY;

    QPoint m_mouseDownPosition;
    bool m_isMouseDown;

    void DrawGridLines(QPainter*);
    int BigBlock() const;
};

#endif // BLACKBOARD_H
