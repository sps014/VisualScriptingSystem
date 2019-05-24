import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import blackBoard 1.0
import QtQuick.Controls.Material 2.3
import QtQuick.Dialogs 1.2
import printnode 1.0
import addnode 1.0
import subtractnode 1.0
import multiplynode 1.0
import noderesults 1.0
import var1d 1.0
import cursor 1.0
import dividenode 1.0

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

    Rectangle {
        id: rectangle
        color: "#000000"
        anchors.fill: parent
        Board
        {
            id:board
            objectName: "board"
            anchors.fill: parent
            onRightClickedChanged: if(board.rightClicked)contextMenu.popup()

            Button
            {
                x:320
                y:20
                width: 100
                height: 50
                text: "Result Get"
                onClicked:
                {
                    msg.text=calc.getResult(board)
                    msg.visible=true
                }
            }
            Result
            {
                id:calc
            }


            MessageDialog
            {
                title: "Output="
                id:msg
                icon: StandardIcon.Information
                standardButtons: StandardButton.Yes
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

