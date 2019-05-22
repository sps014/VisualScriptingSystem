import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import blackBoard 1.0
import QtQuick.Controls.Material 2.3
import printnode 1.0
import addnode 1.0
import noderesults 1.0
import var1d 1.0
Window {
    id:win
    visible: true
    width: 640
    height: 480
    title: qsTr("Operator")


    Rectangle {
        id: rectangle
        color: "#000000"
        anchors.fill: parent
        Board
        {
            id:board
            objectName: "board"
            anchors.fill: parent

            Var1D
            {
                x:20
                y:20
            }
            Var1D
            {
                x:20
                y:200
            }

            Add
            {
                x:200
                y:200
            }

            Print
            {
                x:400
                y:300
            }
            Button
            {
                x:320
                y:20
                width: 100
                height: 50
                text: "Result Get"
                onClicked: calc.getResult(board)
            }
            Result
            {
                id:calc
            }

        }
    }
}

