import QtQuick 2.0

Rectangle {
    width: 300; height: 300; color: "purple"
    RotationAnimation on rotation {
        loops: Animation.Infinite
        from: 0
        to: 360
    }
}
