#ifndef RESULTPARSER_H
#define RESULTPARSER_H

#include <QObject>
#include<QDebug>
#include<QFile>
#include<QProcess>

class ResultParser : public QObject
{
    Q_OBJECT
public:
    explicit ResultParser(QObject *parent = nullptr);
    QString OrderResult(QString);

signals:

public slots:
};

#endif // RESULTPARSER_H
