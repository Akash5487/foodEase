import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Page {
    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 10

        ListView {
            Layout.fillWidth: true
            Layout.fillHeight: true
            model: orderManager.getMenu()
            delegate: Button {
                width: parent.width
                text: modelData
                onClicked: orderManager.placeOrder(modelData)
            }
        }

        Label {
            text: orderManager.orderPlaced
            Layout.fillWidth: true
            wrapMode: Text.WordWrap
        }

        Connections {
            target: orderManager
            function onOrderPlaced(order) {
                console.log("Order placed: " + order)
            }
        }
    }
}