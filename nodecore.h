#ifndef NODECORE_H
#define NODECORE_H

#include <QtQuick/QQuickPaintedItem>
#include<QPainter>
#include "port.h"
#include<QList>
#include<QApplication>
#include<QClipboard>
#include"blackboard.h"
#include<labelcore.h>
#include<checkboxcore.h>
#include<numberboxcore.h>
#include<textboxcore.h>

class NodeCore : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QColor backgroundColor READ backgroundColor WRITE setBackgroundColor)
    Q_PROPERTY(QColor highlightColor READ highlightColor WRITE setHighlightColor)
    Q_PROPERTY(QColor panelColor READ panelColor WRITE setPanelColor)
    Q_PROPERTY(QColor panelGradColor READ panelGradColor WRITE setPanelGradColor)
    Q_PROPERTY(QColor titleColor READ titleColor WRITE setTitleColor)
    Q_PROPERTY(int panelHeight READ panelHeight WRITE setPanelHeight)
    Q_PROPERTY(QString title READ title WRITE setTitle)
    Q_PROPERTY(QFont titleFont READ titleFont WRITE setTitleFont)


public:
    NodeCore();

    QColor backgroundColor() const;
    QColor highlightColor()const;
    QColor panelColor()const;
    QColor panelGradColor()const;
    QString title()const;
    QColor titleColor()const;
    int panelHeight()const;
    QFont titleFont()const;
    QList<Port> inputPort;
    QList<Port> outputPort;
    QList<Label> labelList;
    QList<CheckBox> checkBoxList;
    QList<NumberBox> numberBoxList;
    QList<TextBox> textBoxList;

protected:
    void paint(QPainter*) override;
    void mouseMoveEvent(QMouseEvent*)override;
    void mousePressEvent(QMouseEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;
    void focusOutEvent(QFocusEvent*) override;
    void keyPressEvent(QKeyEvent *)override;

signals:

public slots:
    void setBackgroundColor(const QColor);
    void setHighlightColor(const QColor);
    void setPanelColor(const QColor);
    void setPanelGradColor(const QColor);
    void setTitleColor(const QColor);
    void setPanelHeight(const int);
    void setTitle(const QString);
    void setTitleFont(const QFont);


private:
    QColor m_backgroundColor=QColor(40,40,40);
    QColor m_highlightColor=QColor(Qt::yellow);
    QColor m_panelColor=QColor(Qt::blue);
    QColor m_panelGradColor=QColor(Qt::green);
    QColor m_titleColor=QColor(Qt::white);
    QString m_title="Node";
    QFont m_titleFont=QFont("Segoe UI",12,-1,true);

    int m_panelHeight=40;

    bool mouseClickedOnHeader=false;
    bool outPutPortClicked=false;
    bool inputPortClicked=false;

    QPoint lastMousePosition;

    void DrawBody(QPainter*);
    void DrawTitle(QPainter*);
    void DrawPorts(QPainter*);
    void DrawLabels(QPainter*);
    void DrawCheckBoxes(QPainter*);
    void DrawNumberBoxes(QPainter*);
    void DrawTextBoxes(QPainter*);

    bool IsMouseOnHeader(QPoint);

    Port* GetClickedPort(QPoint);
    CheckBox* GetClickedCheckBox(QPoint);
    NumberBox* GetClickedNumberBox(QPoint);
    TextBox* GetClickedTextBox(QPoint);

    QPoint ConvertQPoint(QPointF);
    Port* GetPortNearestAtPosition(QPoint);
    void BindPort(Port*,Port*);

    Port* currentPort;
    NumberBox* currentNumberBox=nullptr;
    TextBox* currentTextBox=nullptr;

    void PortClickHelper(QPoint);
    void CheckBoxClickHelper(QPoint);
    void NumberBoxClickHelper(QPoint);
    void TextBoxClickHelper(QPoint);

    void PortLineMoveHelper(QPoint);
    void ReleasePortTargeter(QPoint);
    bool FindInList(QList<Port*>,Port*);

    void ConnectionRemover();
	BlackBoard* Parent();
};

#endif // NODECORE_H
