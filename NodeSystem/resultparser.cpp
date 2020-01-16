#include "resultparser.h"

ResultParser::ResultParser(QObject *parent) : QObject(parent)
{

}

//Convert to python and Orders Output from Standard Console for executed python code converted

QString ResultParser::OrderResult(QString s)
{
    QString path =
            QString("%1/graphRes.py").arg(QStandardPaths::writableLocation(QStandardPaths::DesktopLocation));

    //qDebug()<<autoexec;
    //QString path="C:\\Users\\shive\\OneDrive\\Desktop\\m.py"; //output .py path
    QFile file(path); //create file stream

    //open file in write text mode
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        //gets file stream
        QTextStream stream(&file);

        //Write your Functions Custom definition or import staement here

        QString import1="import math\n";
        QString addFunc="def add(a,b):\n return a+b\n";
        QString subFunc="def subtract(a,b):\n return a-b\n";
        QString mulFunc="def multiply(a,b):\n return a*b\n";
        QString divFunc="def divide(a,b):\n return a/b\n";
        QString moduFunc="def modulo(a,b):\n return a%b\n";

        //If your function node is used write your definition to file

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

    //close file
    file.close();

    //Create Process
    QProcess q;
    //Supply python file
    q.start("python "+path);
    //wait for it to finish
    q.waitForFinished();
    //Read output
    QString output(q.readAllStandardOutput());
    //if error ie. output is not there
    if(output.size()<=0)
    {
        //send ERR to specify its error
        output="ERR";
        //read error console
        output+=q.readAllStandardError();
    }
    //send output or error
    return output;

}


