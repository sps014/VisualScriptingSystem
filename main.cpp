#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include"NodeSystem/blackboard.h"
#include"NodeSystem/nodevaluefinder.h"
#include"NodeSystem/cursor.h"


#include"NodeSystem/Derived/math/printnode.h"
#include"NodeSystem/Derived/math/addnode.h"

#include"NodeSystem/Derived/math/var1d.h"
#include"NodeSystem/Derived/math/subtract.h"
#include"NodeSystem/Derived/math/multiplynode.h"
#include"NodeSystem/Derived/math/dividenode.h"

#include"NodeSystem/Derived/math/modulonode.h"

#include"NodeSystem/Derived/math/sinnode.h"
#include"NodeSystem/Derived/math/cosnode.h"
#include"NodeSystem/Derived/math/tannode.h"
#include"NodeSystem/Derived/math/atannode.h"
#include"NodeSystem/Derived/math/asinnode.h"
#include"NodeSystem/Derived/math/acosnode.h"

#include"NodeSystem/Derived/math/hypotnode.h"
#include"NodeSystem/Derived/math/atan2node.h"
#include"NodeSystem/Derived/math/hypotnode.h"

#include"NodeSystem/Derived/math/pownode.h"
#include"NodeSystem/Derived/math/lognode.h"
#include"NodeSystem/Derived/math/sqrtnode.h"
#include"NodeSystem/Derived/math/expnode.h"

#include"NodeSystem/Derived/math/sinhnode.h"
#include"NodeSystem/Derived/math/coshnode.h"
#include"NodeSystem/Derived/math/tanhnode.h"
#include"NodeSystem/Derived/math/atanhnode.h"
#include"NodeSystem/Derived/math/acoshnode.h"
#include"NodeSystem/Derived/math/asinhnode.h"

#include"NodeSystem/Derived/math/pinode.h"
#include"NodeSystem/Derived/math/econstnode.h"

#include"NodeSystem/Derived/math/degreesnode.h"
#include"NodeSystem/Derived/math/radiansnode.h"


#include"NodeSystem/Derived/math/lgammanode.h"
#include"NodeSystem/Derived/math/gammanode.h"
#include"NodeSystem/Derived/math/erfcnode.h"
#include"NodeSystem/Derived/math/erfnode.h"


#include"NodeSystem/Derived/math/ceilnode.h"
#include"NodeSystem/Derived/math/floornode.h"
#include"NodeSystem/Derived/math/factorialnode.h"
#include"NodeSystem/Derived/math/frexpnode.h"



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
     qmlRegisterType<EconstNode>("econstnode",1,0,"E");

     qmlRegisterType<DegreesNode>("degreesnode",1,0,"Degrees");
     qmlRegisterType<RadiansNode>("radiansnode",1,0,"Radians");

     qmlRegisterType<ErfNode>("erfnode",1,0,"Erf");
     qmlRegisterType<ErfcNode>("erfcnode",1,0,"Ergc");
     qmlRegisterType<GammaNode>("gammanode",1,0,"Gamma");
     qmlRegisterType<ErfcNode>("lgammanode",1,0,"LGamma");

     qmlRegisterType<FrexpNode>("frexpnode",1,0,"Frexp");
     qmlRegisterType<FloorNode>("floornode",1,0,"Floor");
     qmlRegisterType<CeilNode>("ceilnode",1,0,"Ciel");
     qmlRegisterType<FactorialNode>("factorialnode",1,0,"Factorial");


    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
