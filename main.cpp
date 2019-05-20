#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include<blackboard.h>
#include<nodecore.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<BlackBoard>("blackBoard",1,0,"Board");
    qmlRegisterType<NodeCore>("nodecore",1,0,"Node");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
