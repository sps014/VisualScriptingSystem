#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include<blackboard.h>
#include<nodecore.h>
#include<printnode.h>
#include<addnode.h>
#include<var1d.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<BlackBoard>("blackBoard",1,0,"Board");
    qmlRegisterType<NodeCore>("nodecore",1,0,"Node");
    qmlRegisterType<PrintNode>("printnode",1,0,"Print");
    qmlRegisterType<AddNode>("addnode",1,0,"Add");
    qmlRegisterType<Var1D>("var1d",1,0,"Var1D");


    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
