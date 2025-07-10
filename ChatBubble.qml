import QtQuick
import QtQuick.Controls

Rectangle {
    property string message
    width: parent.width * 0.8
    height: messageLabel.implicitHeight + 20
    color: "#e0e0e0"
    radius: 10
    anchors.horizontalCenter: parent.horizontalCenter

    Label {
        id: messageLabel
        text: message
        wrapMode: Text.Wordkeyboard_arrow_rightWordWrap
        anchors.centerIn: parent
        padding: 10
    }
}
