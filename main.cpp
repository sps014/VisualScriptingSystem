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


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<BlackBoard>("blackBoard",1,0,"Board");
    qmlRegisterType<NodeValueFinder>("noderesults",1,0,"Result");
    qmlRegisterType<PrintNode>("printnode",1,0,"Print");
    qmlRegisterType<AddNode>("addnode",1,0,"Add");
    qmlRegisterType<Var1D>("var1d",1,0,"Var1D");
    qmlRegisterType<Subtract>("subtractnode",1,0,"Subtract");
    qmlRegisterType<Multiply>("multiplynode",1,0,"Multiply");
    qmlRegisterType<Divide>("dividenode",1,0,"Divide");
    qmlRegisterType<Cursor>("cursor",1,0,"Cursor");


    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
