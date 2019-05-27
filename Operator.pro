QT += quick
CONFIG += c++11
QT+=widgets

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    NodeSystem/blackboard.cpp \
    NodeSystem/nodecore.cpp \
    NodeSystem/port.cpp \
    NodeSystem/nodevaluefinder.cpp \
    NodeSystem/resultparser.cpp \
    NodeSystem/cursor.cpp \
    NodeSystem/Derived/printnode.cpp \
    NodeSystem/Derived/addnode.cpp \
    NodeSystem/Derived/var1d.cpp \
    NodeSystem/Derived/subtract.cpp \
    NodeSystem/Derived/multiplynode.cpp \
    NodeSystem/Derived/dividenode.cpp \
    NodeSystem/Derived/modulonode.cpp \
    NodeSystem/Derived/math/sinnode.cpp \
    NodeSystem/Derived/math/cosnode.cpp \
    NodeSystem/Derived/math/tannode.cpp \
    NodeSystem/Derived/math/asinnode.cpp \
    NodeSystem/Derived/math/acosnode.cpp \
    NodeSystem/Derived/math/atannode.cpp \
    NodeSystem/Derived/math/atan2node.cpp \
    NodeSystem/Derived/math/hypotnode.cpp \
    NodeSystem/Derived/math/lognode.cpp \
    NodeSystem/Derived/math/pownode.cpp \
    NodeSystem/Derived/math/expnode.cpp \
    NodeSystem/Derived/math/sqrtnode.cpp \
    NodeSystem/Derived/math/asinhnode.cpp \
    NodeSystem/Derived/math/acoshnode.cpp \
    NodeSystem/Derived/math/atanhnode.cpp \
    NodeSystem/Derived/math/coshnode.cpp \
    NodeSystem/Derived/math/sinhnode.cpp \
    NodeSystem/Derived/math/tanhnode.cpp \
    NodeSystem/Derived/math/pinode.cpp \
    NodeSystem/Derived/math/econstnode.cpp \
    NodeSystem/Derived/math/degreesnode.cpp \
    NodeSystem/Derived/math/radiansnode.cpp \
    NodeSystem/Derived/math/erfnode.cpp \
    NodeSystem/Derived/math/erfcnode.cpp \
    NodeSystem/Derived/math/gammanode.cpp \
    NodeSystem/Derived/math/lgammanode.cpp \
    NodeSystem/Derived/math/ceilnode.cpp \
    NodeSystem/Derived/math/fabsnode.cpp \
    NodeSystem/Derived/math/factorialnode.cpp \
    NodeSystem/Derived/math/floornode.cpp \
    NodeSystem/Derived/math/frexpnode.cpp





RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


HEADERS += \
    NodeSystem/blackboard.h \
    NodeSystem/nodecore.h \
    NodeSystem/port.h \
    NodeSystem/labelcore.h \
    NodeSystem/checkboxcore.h \
    NodeSystem/numberboxcore.h \
    NodeSystem/textboxcore.h \
    NodeSystem/nodevaluefinder.h \
    NodeSystem/resultparser.h \
    NodeSystem/cursor.h \
    NodeSystem/Derived/printnode.h \
    NodeSystem/Derived/math/addnode.h \
    NodeSystem/Derived/var1d.h \
    NodeSystem/Derived/subtract.h \
    NodeSystem/Derived/multiplynode.h \
    NodeSystem/Derived/dividenode.h \
    NodeSystem/Derived/modulonode.h \
    NodeSystem/Derived/math/sinnode.h \
    NodeSystem/Derived/math/cosnode.h \
    NodeSystem/Derived/math/tannode.h \
    NodeSystem/Derived/math/asinnode.h \
    NodeSystem/Derived/math/acosnode.h \
    NodeSystem/Derived/math/atannode.h \
    NodeSystem/Derived/math/atan2node.h \
    NodeSystem/Derived/math/hypotnode.h \
    NodeSystem/Derived/math/lognode.h \
    NodeSystem/Derived/math/pownode.h \
    NodeSystem/Derived/math/expnode.h \
    NodeSystem/Derived/math/sqrtnode.h \
    NodeSystem/Derived/math/asinhnode.h \
    NodeSystem/Derived/math/acoshnode.h \
    NodeSystem/Derived/math/atanhnode.h \
    NodeSystem/Derived/math/coshnode.h \
    NodeSystem/Derived/math/sinhnode.h \
    NodeSystem/Derived/math/tanhnode.h \
    NodeSystem/Derived/math/pinode.h \
    NodeSystem/Derived/math/econstnode.h \
    NodeSystem/Derived/math/degreesnode.h \
    NodeSystem/Derived/math/radiansnode.h \
    NodeSystem/Derived/math/erfnode.h \
    NodeSystem/Derived/math/erfcnode.h \
    NodeSystem/Derived/math/gammanode.h \
    NodeSystem/Derived/math/lgammanode.h \
    NodeSystem/Derived/math/ceilnode.h \
    NodeSystem/Derived/math/fabsnode.h \
    NodeSystem/Derived/math/factorialnode.h \
    NodeSystem/Derived/math/floornode.h \
    NodeSystem/Derived/math/frexpnode.h \
    NodeSystem/comboboxcore.h
