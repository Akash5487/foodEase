import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Page {
    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 10

        ListView {
            id: chatView
            Layout.fillWidth: true
            Layout.fillHeight: true
            model: ListModel { id: chatModel }
            delegate: ChatBubble { message: model.message }
        }

        RowLayout {
            TextField {
                id: messageField
                Layout.fillWidth: true
                placeholderText: "Type a message..."
                onAccepted: {
                    kafkaProducer.sendMessage(messageField.text)
                    messageField.text = ""
                }
            }
            Button {
                text: "Send"
                onClicked: {
                    kafkaProducer.sendMessage(messageField.text)
                    messageField.text = ""
                }
            }
        }

        Connections {
            target: kafkaConsumer
            function onMessageReceived(message) {
                chatModel.append({ message: message })
                chatView.positionViewAtEnd()
            }
        }

        Component.onCompleted: kafkaConsumer.start()
    }
}