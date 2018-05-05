import QtQuick 2.0

Rectangle {
    id: idRoot
    width: 100
    height: width/2
    radius: width
//    color: "#3062be"
    property alias text: idText.text

    gradient: idGradient1

    signal clicked()


    Gradient {
        id: idGradient1
        GradientStop { position: 0.0; color: "#3492c8" }
        GradientStop { position: 1.0; color: "#1f63b6" }
    }

    Gradient {
        id: idGradient2
        GradientStop { position: 0.0; color: "#1f63b6" }
        GradientStop { position: 1.0; color: "#3492c8" }
    }

    Text {
        id: idText
        text: qsTr("text")
        font.family: idFontThin.name
        font.pixelSize: 16
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        wrapMode: Text.WordWrap
        anchors.fill: parent
        anchors.margins: 10
        color: "white"
    }

    MouseArea {
        anchors.fill: parent
        onPressed: {
            idRoot.gradient = idGradient2
            idRoot.scale = 0.98
        }

        onReleased: {
            idRoot.gradient = idGradient1
            idRoot.scale = 1
        }

        onClicked: idRoot.clicked()
    }

}
