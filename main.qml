import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5
import blackBoard 1.0
import QtQuick.Controls.Material 2.3
import QtQuick.Dialogs 1.2
import noderesults 1.0
import cursor 1.0


Window {
    id:win
    visible: true
    width: 640
    height: 480
    title: qsTr("Operator")

    Cursor
    {
        id: curs
    }

    ToolBar {
        id: toolBar
        height: 49
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0

        ToolButton {
            id: toolButton
            x: 0
            y: 0
            text: qsTr("RUN")
            onClicked: runMenu.popup()
            Menu{
                id:runMenu
                title: "Transpile"
                MenuItem
                {
                    text:"Python"
                    onClicked:
                    {
                        var msg=calc.getResult(board)
                        if(msg.indexOf("ERR")>=0)
                        {
                            outputText.color="red"
                            msg=msg.replace("ERR","")
                        }
                        else
                            outputText.color="white"
                        outputText.text=msg
                    }
                }
            }
        }

        Button
        {
            x: 514
            y: -1
            width: 118
            height: 50
            text: "Result"
            anchors.right: parent.right
            anchors.rightMargin: 8
            onClicked:
            {
                var msg=calc.getResult(board)
                if(msg.indexOf("ERR")>=0)
                {
                    outputText.color="red"
                    msg=msg.replace("ERR","")
                }
                else
                    outputText.color="white"
                outputText.text=msg
            }
        }
    }



    Rectangle {
        id: consolePanel
        x: 0
        y: 353
        height: 127
        color: "#353533"
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0

        Rectangle {

            id: consoleHeaderPanel
            x: 0
            y: 0
            height: 35
            color: "#078493"
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 92
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: 0


            Label {
                id: label
                x: 8
                y: 8
                color: "#deffffff"
                text: qsTr("Console")
                font.pointSize: 12
                font.italic: false
                font.bold: true
            }
        }

        TextEdit {
            id: outputText
            y: 34
            height: 93
            color: "#fdfdfd"
            text: qsTr("Engine Initialized")
            font.italic: false
            font.bold: false
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: 0
            font.pixelSize: 18
        }
    }

    Rectangle {
        id: mainWorkingPanel
        color: "#eaea7e"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 123
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 46

        Board
        {
            id:board
            objectName: "board"
            anchors.fill: parent
            onRightClickedChanged: if(board.rightClicked)contextMenu.popup()
            Result
            {
                id:calc
            }


            Menu
            {
                id: contextMenu
                cascade: true
                Menu
                {
                    title: "Input"

                    MenuItem
                    {
                        text: "1D Var"
                        onClicked:
                        {
                            var newObject = Qt.createQmlObject('import var1d 1.0;
                                    Var1D {x:'+curs.getCursor(win.x,win.y).x+'
                                         y:'+curs.getCursor(win.x,win.y).y+' }', board, "board");
                        }
                    }

                }
                Menu
                {
                    title: "Math"

                    Menu
                    {
                        title: "Basic"

                        MenuItem
                        {
                            text: "Add"
                            onClicked:
                            {
                                var newObject = Qt.createQmlObject('import addnode 1.0;
                                    Add {x:'+curs.getCursor(win.x,win.y).x+'
                                         y:'+curs.getCursor(win.x,win.y).y+' }', board, "board");
                            }
                        }

                        MenuItem
                        {
                            text: "Subtract"
                            onClicked:
                            {
                                var newObject = Qt.createQmlObject('import subtractnode 1.0;
                                    Subtract {x:'+curs.getCursor(win.x,win.y).x+'
                                         y:'+curs.getCursor(win.x,win.y).y+' }', board, "board");
                            }
                        }

                        MenuItem
                        {
                            text: "Multiply"
                            onClicked:
                            {
                                var newObject = Qt.createQmlObject('import multiplynode 1.0;
                                    Multiply {x:'+curs.getCursor(win.x,win.y).x+'
                                         y:'+curs.getCursor(win.x,win.y).y+' }', board, "board");
                            }
                        }
                        MenuItem
                        {
                            text: "Divide"
                            onClicked:
                            {
                                var newObject = Qt.createQmlObject('import dividenode 1.0;
                                    Divide {x:'+curs.getCursor(win.x,win.y).x+'
                                         y:'+curs.getCursor(win.x,win.y).y+' }', board, "board");
                            }
                        }
                        MenuItem
                        {
                            text: "Modulo"
                            onClicked:
                            {
                                var newObject = Qt.createQmlObject('import modulonode 1.0;
                                    Modulo {x:'+curs.getCursor(win.x,win.y).x+'
                                         y:'+curs.getCursor(win.x,win.y).y+' }', board, "board");
                            }
                        }

                    }
                    Menu
                    {
                        title: "Trignometric"
                        MenuItem
                        {
                            text: "Sin"
                            onClicked:
                            {
                                var newObject = Qt.createQmlObject('import sinnode 1.0;
                                        Sin {x:'+curs.getCursor(win.x,win.y).x+'
                                             y:'+curs.getCursor(win.x,win.y).y+' }', board, "board");
                            }
                        }
                        MenuItem
                        {
                            text: "Cos"
                            onClicked:
                            {
                                var newObject = Qt.createQmlObject('import cosnode 1.0;
                                        Cos {x:'+curs.getCursor(win.x,win.y).x+'
                                             y:'+curs.getCursor(win.x,win.y).y+' }', board, "board");
                            }
                        }
                        MenuItem
                        {
                            text: "Tan"
                            onClicked:
                            {
                                var newObject = Qt.createQmlObject('import tannode 1.0;
                                        Tan {x:'+curs.getCursor(win.x,win.y).x+'
                                             y:'+curs.getCursor(win.x,win.y).y+' }', board, "board");
                            }
                        }
                        MenuItem
                        {
                            text: "ASin"
                            onClicked:
                            {
                                var newObject = Qt.createQmlObject('import asinnode 1.0;
                                        ASin {x:'+curs.getCursor(win.x,win.y).x+'
                                             y:'+curs.getCursor(win.x,win.y).y+' }', board, "board");
                            }
                        }
                        MenuItem
                        {
                            text: "ACos"
                            onClicked:
                            {
                                var newObject = Qt.createQmlObject('import acosnode 1.0;
                                        ACos {x:'+curs.getCursor(win.x,win.y).x+'
                                             y:'+curs.getCursor(win.x,win.y).y+' }', board, "board");
                            }
                        }
                        MenuItem
                        {
                            text: "ATan"
                            onClicked:
                            {
                                var newObject = Qt.createQmlObject('import atannode 1.0;
                                        ATan {x:'+curs.getCursor(win.x,win.y).x+'
                                             y:'+curs.getCursor(win.x,win.y).y+' }', board, "board");
                            }
                        }
                        MenuItem
                        {
                            text: "ATan2"
                            onClicked:
                            {
                                var newObject = Qt.createQmlObject('import atan2node 1.0;
                                        ATan2 {x:'+curs.getCursor(win.x,win.y).x+'
                                             y:'+curs.getCursor(win.x,win.y).y+' }', board, "board");
                            }
                        }
                        MenuItem
                        {
                            text: "Hypot"
                            onClicked:
                            {
                                var newObject = Qt.createQmlObject('import hypotnode 1.0;
                                        Hypot {x:'+curs.getCursor(win.x,win.y).x+'
                                             y:'+curs.getCursor(win.x,win.y).y+' }', board, "board");
                            }
                        }

                    }
                    Menu
                    {
                        title: "Power and Logrithmic"
                        MenuItem
                        {
                            text: "Log"
                            onClicked:
                            {
                                var newObject = Qt.createQmlObject('import lognode 1.0;
                                        Log {x:'+curs.getCursor(win.x,win.y).x+'
                                             y:'+curs.getCursor(win.x,win.y).y+' }', board, "board");
                            }
                        }
                        MenuItem
                        {
                            text: "Pow"
                            onClicked:
                            {
                                var newObject = Qt.createQmlObject('import pownode 1.0;
                                        Pow {x:'+curs.getCursor(win.x,win.y).x+'
                                             y:'+curs.getCursor(win.x,win.y).y+' }', board, "board");
                            }
                        }
                        MenuItem
                        {
                            text: "Exp"
                            onClicked:
                            {
                                var newObject = Qt.createQmlObject('import expnode 1.0;
                                        Exp {x:'+curs.getCursor(win.x,win.y).x+'
                                             y:'+curs.getCursor(win.x,win.y).y+' }', board, "board");
                            }
                        }
                        MenuItem
                        {
                            text: "Sqrt"
                            onClicked:
                            {
                                var newObject = Qt.createQmlObject('import sqrtnode 1.0;
                                        Sqrt {x:'+curs.getCursor(win.x,win.y).x+'
                                             y:'+curs.getCursor(win.x,win.y).y+' }', board, "board");
                            }
                        }
                    }
                    Menu
                    {
                        title: "Hyperbolic"
                        MenuItem
                        {
                            text: "Sinh"
                            onClicked:
                            {
                                var newObject = Qt.createQmlObject('import sinhnode 1.0;
                                        Sinh {x:'+curs.getCursor(win.x,win.y).x+'
                                             y:'+curs.getCursor(win.x,win.y).y+' }', board, "board");
                            }
                        }
                        MenuItem
                        {
                            text: "Cosh"
                            onClicked:
                            {
                                var newObject = Qt.createQmlObject('import coshnode 1.0;
                                        Cosh {x:'+curs.getCursor(win.x,win.y).x+'
                                             y:'+curs.getCursor(win.x,win.y).y+' }', board, "board");
                            }
                        }
                        MenuItem
                        {
                            text: "Tanh"
                            onClicked:
                            {
                                var newObject = Qt.createQmlObject('import tanhnode 1.0;
                                        Tanh {x:'+curs.getCursor(win.x,win.y).x+'
                                             y:'+curs.getCursor(win.x,win.y).y+' }', board, "board");
                            }
                        }
                        MenuItem
                        {
                            text: "ASinh"
                            onClicked:
                            {
                                var newObject = Qt.createQmlObject('import asinhnode 1.0;
                                        ASinh {x:'+curs.getCursor(win.x,win.y).x+'
                                             y:'+curs.getCursor(win.x,win.y).y+' }', board, "board");
                            }
                        }
                        MenuItem
                        {
                            text: "ACosh"
                            onClicked:
                            {
                                var newObject = Qt.createQmlObject('import acoshnode 1.0;
                                        ACosh {x:'+curs.getCursor(win.x,win.y).x+'
                                             y:'+curs.getCursor(win.x,win.y).y+' }', board, "board");
                            }
                        }
                        MenuItem
                        {
                            text: "ATanh"
                            onClicked:
                            {
                                var newObject = Qt.createQmlObject('import atanhnode 1.0;
                                        ATanh {x:'+curs.getCursor(win.x,win.y).x+'
                                             y:'+curs.getCursor(win.x,win.y).y+' }', board, "board");
                            }
                        }

                    }
                    Menu
                    {
                        title: "Constants"
                        MenuItem
                        {
                            text: "PI"
                            onClicked:
                            {
                                var newObject = Qt.createQmlObject('import pinode 1.0;
                                        PI {x:'+curs.getCursor(win.x,win.y).x+'
                                             y:'+curs.getCursor(win.x,win.y).y+' }', board, "board");
                            }
                        }
                        MenuItem
                        {
                            text: "E"
                            onClicked:
                            {
                                var newObject = Qt.createQmlObject('import econstnode 1.0;
                                        E {x:'+curs.getCursor(win.x,win.y).x+'
                                             y:'+curs.getCursor(win.x,win.y).y+' }', board, "board");
                            }
                        }
                    }
                    Menu
                    {
                        title: "Angular Conversion"
                        MenuItem
                        {
                            text: "Degrees"
                            onClicked:
                            {
                                var newObject = Qt.createQmlObject('import degreesnode 1.0;
                                        Degrees {x:'+curs.getCursor(win.x,win.y).x+'
                                             y:'+curs.getCursor(win.x,win.y).y+' }', board, "board");
                            }
                        }
                        MenuItem
                        {
                            text: "Radians"
                            onClicked:
                            {
                                var newObject = Qt.createQmlObject('import radiansnode 1.0;
                                        Radians {x:'+curs.getCursor(win.x,win.y).x+'
                                             y:'+curs.getCursor(win.x,win.y).y+' }', board, "board");
                            }
                        }
                    }
                    Menu
                    {
                        title: "Special"
                        MenuItem
                        {
                            text: "Erf"
                            onClicked:
                            {
                                var newObject = Qt.createQmlObject('import erfnode 1.0;
                                        Erf {x:'+curs.getCursor(win.x,win.y).x+'
                                             y:'+curs.getCursor(win.x,win.y).y+' }', board, "board");
                            }
                        }
                        MenuItem
                        {
                            text: "Erfc"
                            onClicked:
                            {
                                var newObject = Qt.createQmlObject('import erfcnode 1.0;
                                        Erfc {x:'+curs.getCursor(win.x,win.y).x+'
                                             y:'+curs.getCursor(win.x,win.y).y+' }', board, "board");
                            }
                        }
                        MenuItem
                        {
                            text: "Gamma"
                            onClicked:
                            {
                                var newObject = Qt.createQmlObject('import gammanode 1.0;
                                        Gamma {x:'+curs.getCursor(win.x,win.y).x+'
                                             y:'+curs.getCursor(win.x,win.y).y+' }', board, "board");
                            }
                        }
                        MenuItem
                        {
                            text: "LGamma"
                            onClicked:
                            {
                                var newObject = Qt.createQmlObject('import lgammanode 1.0;
                                        LGamma {x:'+curs.getCursor(win.x,win.y).x+'
                                             y:'+curs.getCursor(win.x,win.y).y+' }', board, "board");
                            }
                        }
                    }
                    Menu
                    {
                        title: "Number-Theoretic And Representational"
                        MenuItem
                        {
                            text: "Ceil"
                            onClicked:
                            {
                                var newObject = Qt.createQmlObject('import ceilnode 1.0;
                                        Ceil {x:'+curs.getCursor(win.x,win.y).x+'
                                             y:'+curs.getCursor(win.x,win.y).y+' }', board, "board");
                            }
                        }
                        MenuItem
                        {
                            text: "Floor"
                            onClicked:
                            {
                                var newObject = Qt.createQmlObject('import floornode 1.0;
                                        Floor {x:'+curs.getCursor(win.x,win.y).x+'
                                             y:'+curs.getCursor(win.x,win.y).y+' }', board, "board");
                            }
                        }
                        MenuItem
                        {
                            text: "Factorial"
                            onClicked:
                            {
                                var newObject = Qt.createQmlObject('import factorialnode 1.0;
                                        Factorial {x:'+curs.getCursor(win.x,win.y).x+'
                                             y:'+curs.getCursor(win.x,win.y).y+' }', board, "board");
                            }
                        }
                        MenuItem
                        {
                            text: "Frexp"
                            onClicked:
                            {
                                var newObject = Qt.createQmlObject('import frexpnode 1.0;
                                        Frexp {x:'+curs.getCursor(win.x,win.y).x+'
                                             y:'+curs.getCursor(win.x,win.y).y+' }', board, "board");
                            }
                        }
                    }
                }


                Menu
                {
                    title: "Output"

                    MenuItem
                    {
                        text:"Print"
                        onClicked:
                        {
                            var newObject = Qt.createQmlObject('import printnode 1.0;
                                    Print {x:'+curs.getCursor(win.x,win.y).x+'
                                         y:'+curs.getCursor(win.x,win.y).y+' }', board, "board");
                        }
                    }
                }

            }

        }
    }




}

