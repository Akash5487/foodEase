import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: "FoodEase"

    TabBar {
        id: tabBar
        width: parent.width
        TabButton { text: "Menu" }
        TabButton { text: "Chat" }
    }

    StackLayout {
        anchors.top: tabBar.bottom
        anchors.bottom: parent.bottom
        width: parent.width
        currentIndex: tabBar.currentIndex

        MenuPage {}
        ChatPage {}
    }
}