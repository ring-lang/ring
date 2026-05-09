import QtQuick 2.5

Rectangle {
    width: 400
    height: 400
    color: "lightsteelblue"
    ScaleAnimator on scale {
        from: 0.5;
        to: 1;
        duration: 1000
    }
}
