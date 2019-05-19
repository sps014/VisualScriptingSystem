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
        squareDimension: 25
        squareNumber: 5
        offsetX: 146
        offsetY: 125
        height: win.height
        width: win.width

    }

    Slider {
        id: slider
        x: 176
        y: 387
        to: 1.5
        from: 0.5
        value: 1

        onValueChanged: board.zoom(slider.value)
    }

    Slider {
        id: slider1
        x: 415
        y: 393
        from: 25
        to: 100
        value: 25
        onValueChanged: board.squareDimension=slider1.value
    }
}

