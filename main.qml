import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import blackBoard 1.0
import QtQuick.Controls.Material 2.3
Window {
    id:win
    visible: true
    width: 640
    height: 480
    title: qsTr("Operator")

    Board
    {
        id:board
        backgroundColor:"green"
        squareDimension: 25
        squareNumber: 5
        offsetX: 146
        offsetY: 125
        height: win.height
        width: win.width
    }
}

