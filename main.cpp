#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include<blackboard.h>
#include<nodevaluefinder.h>
#include<printnode.h>
#include<addnode.h>
#include<var1d.h>
#include<subtract.h>
#include <multiplynode.h>
#include<cursor.h>
#include<dividenode.h>
#include"modulonode.h"

#include"sinnode.h"
#include<cosnode.h>
#include<tannode.h>
#include<atannode.h>
#include<acosnode.h>
#include<asinnode.h>
#include<hypotnode.h>
#include<atan2node.h>
#include<hypotnode.h>

#include<lognode.h>
#include<pownode.h>
#include"sqrtnode.h"
#include<expnode.h>

#include"sinhnode.h"
#include<coshnode.h>
#include<tanhnode.h>
#include<atanhnode.h>
#include<acoshnode.h>
#include<asinhnode.h>

#include"pinode.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<BlackBoard>("blackBoard",1,0,"Board");
    qmlRegisterType<NodeValueFinder>("noderesults",1,0,"Result");
    qmlRegisterType<Cursor>("cursor",1,0,"Cursor");


    qmlRegisterType<PrintNode>("printnode",1,0,"Print");

    qmlRegisterType<Var1D>("var1d",1,0,"Var1D");

    qmlRegisterType<AddNode>("addnode",1,0,"Add");
    qmlRegisterType<Subtract>("subtractnode",1,0,"Subtract");
    qmlRegisterType<Multiply>("multiplynode",1,0,"Multiply");
    qmlRegisterType<Divide>("dividenode",1,0,"Divide");
    qmlRegisterType<ModuloNode>("modulonode",1,0,"Modulo");

    qmlRegisterType<SinNode>("sinnode",1,0,"Sin");
    qmlRegisterType<cosnode>("cosnode",1,0,"Cos");
    qmlRegisterType<tannode>("tannode",1,0,"Tan");

    qmlRegisterType<ATan>("atannode",1,0,"ATan");
    qmlRegisterType<ACosNode>("acosnode",1,0,"ACos");
    qmlRegisterType<asinnode>("asinnode",1,0,"ASin");

    qmlRegisterType<ATan2Node>("atan2node",1,0,"ATan2");
    qmlRegisterType<HypotNode>("hypotnode",1,0,"Hypot");

    qmlRegisterType<PowNode>("pownode",1,0,"Pow");
    qmlRegisterType<LogNode>("lognode",1,0,"Log");
    qmlRegisterType<ExpNode>("expnode",1,0,"Exp");
    qmlRegisterType<SqrtNode>("sqrtnode",1,0,"Sqrt");

    qmlRegisterType<ASinHNode>("sinhnode",1,0,"Sinh");
    qmlRegisterType<CosHNode>("coshnode",1,0,"Cosh");
    qmlRegisterType<TanHNode>("tanhnode",1,0,"Tanh");

    qmlRegisterType<ATanHNode>("atanhnode",1,0,"ATanh");
    qmlRegisterType<ACosHNode>("acoshnode",1,0,"ACosh");
    qmlRegisterType<ASinHNode>("asinhnode",1,0,"ASinh");

     qmlRegisterType<PiNode>("pinode",1,0,"PI");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
