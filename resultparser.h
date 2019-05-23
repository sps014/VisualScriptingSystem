#ifndef RESULTPARSER_H
#define RESULTPARSER_H

#include <QObject>
#include<QDebug>

class ResultParser : public QObject
{
    Q_OBJECT
public:
    explicit ResultParser(QObject *parent = nullptr);
    QString OrderResult(QString);
    QString ValidExpression(QString);
    double Add(QStringList);
    double Subtract(QStringList);
signals:

public slots:
};

#endif // RESULTPARSER_H
