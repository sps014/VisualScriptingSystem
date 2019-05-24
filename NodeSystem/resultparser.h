/*
 * This Class Converts Raw Meta Language type code to python equivalent
 **/

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

    //Convert to python and Orders Output from Standard Console for executed python code converted
    QString OrderResult(QString);

};

#endif // RESULTPARSER_H
