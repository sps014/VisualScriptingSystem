#include "resultparser.h"

ResultParser::ResultParser(QObject *parent) : QObject(parent)
{

}
QString ResultParser::OrderResult(QString s)
{
    QString path="C:\\Users\\shive\\OneDrive\\Desktop\\m.py";
    QFile file(path);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {

        QTextStream stream(&file);

        QString addFunc="def add(a,b):\n return a+b\n";
        QString subFunc="def subtract(a,b):\n return a-b\n";
        QString mulFunc="def multiply(a,b):\n return a*b\n";
        QString divFunc="def divide(a,b):\n return a/b\n";


        stream<<addFunc<<endl;
        stream<<subFunc<<endl;
        stream<<mulFunc<<endl;
        stream<<divFunc<<endl;


        stream<<"\n"<<s<<endl;
    }
    file.close();

    QProcess q;
    q.start("python "+path);
    q.waitForFinished();
    QString output(q.readAllStandardOutput());
    output.replace("\r\n","");
    return output;

}


