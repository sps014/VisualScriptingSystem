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

        QString sinFunc="def sin(a):\n return math.sin(a)\n";
        QString cosFunc="def cos(a):\n return math.cos(a)\n";
        QString tanFunc="def tan(a):\n return math.tan(a)\n";
        QString aSinFunc="def asin(a):\n return math.asin(a)\n";
        QString aCosFunc="def acos(a):\n return math.acos(a)\n";
        QString aTanFunc="def atan(a):\n return math.atan(a)\n";
        QString aTan2Func="def atan2(a,b):\n return math.atan2(a,b)\n";
        QString hypotFunc="def hypot(a,b):\n return math.hypot(a,b)\n";
        QString logFunc="def log(a,b):\n return math.log(a,b)\n";
        QString powFunc="def pow(a,b):\n return math.pow(a,b)\n";
        QString expFunc="def exp(a):\n return math.exp(a)\n";
        QString sqrtFunc="def sqrt(a):\n return math.sqrt(a)\n";

        QString sinhFunc="def sinh(a):\n return math.sinh(a)\n";
        QString coshFunc="def cosh(a):\n return math.cosh(a)\n";
        QString tanhFunc="def tanh(a):\n return math.tanh(a)\n";
        QString aSinhFunc="def asinh(a):\n return math.asinh(a)\n";
        QString aCoshFunc="def acosh(a):\n return math.acosh(a)\n";
        QString aTanhFunc="def atanh(a):\n return math.atanh(a)\n";



        stream<<import1<<endl;
        stream<<addFunc<<endl;
        stream<<subFunc<<endl;
        stream<<mulFunc<<endl;
        stream<<divFunc<<endl;
        stream<<moduFunc<<endl;

        stream<<sinFunc<<endl;
        stream<<cosFunc<<endl;
        stream<<tanFunc<<endl;
        stream<<aSinFunc<<endl;
        stream<<aCosFunc<<endl;
        stream<<aTanFunc<<endl;

        stream<<aTan2Func<<endl;
        stream<<hypotFunc<<endl;

        stream<<logFunc<<endl;
        stream<<powFunc<<endl;

        stream<<expFunc<<endl;
        stream<<sqrtFunc<<endl;

        stream<<sinhFunc<<endl;
        stream<<coshFunc<<endl;
        stream<<tanhFunc<<endl;
        stream<<aSinhFunc<<endl;
        stream<<aCoshFunc<<endl;
        stream<<aTanhFunc<<endl;


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


