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
                width: 150
                objectName: "node2"
                height: 150
                x:300
                y:300
                panelColor: "brown"
                panelGradColor: "yellow"
                title: "print"
            }
            Node
            {
                id:node
                title: "vector2"
                panelGradColor: "purple"
                width: 200
                height: 200


            }


        }
    }
}

