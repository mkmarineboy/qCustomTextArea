import QtQuick 2.13
import QtQuick.Controls 2.12
import QtQuick.Window 2.13
import MKQuick.Controls 1.0
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle{
        id: justARect
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        height: 120
        color: "yellow"

        MTextArea {
            textFormat: TextEdit.RichText
            objectName: "chatArea_bubble_messageText"
            id: messageText
            anchors.fill: parent
            text: "et, consectetur adipiscing elit. Ut convallis ullamcorper nulla a commodo. Aliquam eu efficitur neque. Morbi mauris sem, euismod vel mollis sed, gravida at ipsum. Morbi eu tincidunt nunc. Sed ipsum turpis, sodales id sollicitudin sit amet, egestas eu nisl. Nullam bibendum auctor libero, et pharetra erat euismod id. Suspendisse pot"
            width: parent.width
            font.pixelSize: 16
            font.weight: Font.Normal
            color: "gray"
            readOnly: true
            wrapMode: TextEdit.WrapAtWordBoundaryOrAnywhere
            enableCursorShape: true
            selectByMouse: true
            onLastLineWidthChanged: console.log("new last line width: ",lastLineWidth)
            Component.onCompleted: {
                setLastLineWidth()
            }
        }
    }



}
