import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import blackBoard 1.0
import QtQuick.Controls.Material 2.3
import nodecore 1.0
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
            anchors.fill: parent
            Node
            {
                id:node2
                width: 200
                objectName: "node2"
                height: 300
                panelColor: "magenta"
                panelGradColor: "yellow"
                x:300
                y:200
            }
            Node
            {
                id:node
                width: 200
                height: 300
                x:300
                y:100
            }
            Node
            {
                objectName: "node3"

                width: 200
                height: 300
            }


        }
    }
}

