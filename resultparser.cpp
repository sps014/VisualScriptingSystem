#include "resultparser.h"

ResultParser::ResultParser(QObject *parent) : QObject(parent)
{

}
QString ResultParser::OrderResult(QString s)
{
    QStringList splited=s.split(" ");
    for(int i=0;i<splited.length()/2;i++)
    {
        QString temp=splited[i];
        splited[i]=splited[splited.length()-1-i];
        splited[splited.length()-1-i]=temp;
    }

    QString CalResult="";

    for(int i=0;i<splited.length();i++)
    {
        QString temp=splited[i];
        if(temp=="add")
        {
            CalResult+="+ ";
        }
        else if("multiply"==temp)
        {
            CalResult+="*";
        }
        else if(temp=="subtract")
        {
            CalResult+="- ";
        }
        else if(temp=="print")
            CalResult+="";
        else
        {
            CalResult+=splited[i]+" ";

        }
    }
    return CalResult;
}


