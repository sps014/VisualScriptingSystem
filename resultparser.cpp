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

        QString import1="import math\n";
        QString addFunc="def add(a,b):\n return a+b\n";
        QString subFunc="def subtract(a,b):\n return a-b\n";
        QString mulFunc="def multiply(a,b):\n return a*b\n";
        QString divFunc="def divide(a,b):\n return a/b\n";
        QString moduFunc="def modulo(a,b):\n return a%b\n";



        if(s.indexOf("math")>=0)
        stream<<import1<<endl;
        if(s.indexOf("add")>=0)
        stream<<addFunc<<endl;
        if(s.indexOf("subtract")>=0)
        stream<<subFunc<<endl;
        if(s.indexOf("multiply")>=0)
        stream<<mulFunc<<endl;
        if(s.indexOf("divide")>=0)
        stream<<divFunc<<endl;
        if(s.indexOf("modulo")>=0)
        stream<<moduFunc<<endl;




        stream<<"\n"<<s<<endl;
    }
    file.close();

    QProcess q;
    q.start("python "+path);
    q.waitForFinished();
    QString output(q.readAllStandardOutput());
    if(output.size()<=0)
        output=q.readAllStandardError();
    output.replace("\r\n","");
    return output;

}


