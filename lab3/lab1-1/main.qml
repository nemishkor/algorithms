import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    id: window
    visible: true
    width: 1300
    height: 260

    Column{

        anchors.fill: parent

        Rectangle{
            id: btnSort
            height: 30
            width: parent.width
            color: "grey"
            Text{
                anchors.centerIn: parent
                text: "Inserting sort!"
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {

                    // SORTING
                    for(var i = 1; i < 100; i++){
                        var next = true
                        var value = dataModelInsert.get(i).value
                        for(var j = 0; j < i && next; j++){
                            if(value < dataModelInsert.get(j).value){
                                dataModelInsert.move(i, j, 1)
                                next = false
                            }
                        }
                    }

                }
            }
        }

        ListModel {
            id: dataModelInsert

            Component.onCompleted: {
                for(var i = 0; i < 100; i++){
                    var value = Math.floor(Math.random() * 100)
                    dataModelInsert.append({value: value})
                }
            }
        }

        ListView {
            id: view
            orientation: ListView.Horizontal
            anchors.margins: 10
            height: 100
            width: parent.width
            spacing: 1
            model: dataModelInsert
            add: Transition {
                NumberAnimation { properties: "x,y"; from: 100; duration: 1000 }
            }
            displaced : Transition {
                NumberAnimation { properties: "x,y"; duration: 100; easing.type: Easing.OutBounce }
            }
            delegate: Rectangle {
                width: 12
                height: view.height

                Rectangle{
                    width: 12
                    height: model.value
                    anchors.bottom: parent.bottom
                    color: "skyblue"
                }

                Text {
                    anchors.centerIn: parent
                    renderType: Text.NativeRendering
                    text: model.value
                    font.pixelSize: 9
                }
            }

        }

        // --------------------------------


        ListModel {
            id: dataModelSelect

            Component.onCompleted: {
                for(var i = 0; i < 100; i++){
                    var value = Math.floor(Math.random() * 100)
                    dataModelSelect.append({value: value})
                }
            }
        }

        Rectangle{
            id: btnSort2
            height: 30
            width: parent.width
            color: "grey"
            Text{
                anchors.centerIn: parent
                text: "Inserting sort!"
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {

                    // SORTING
                    for(var i = 0; i < 100; i++){
                        var smallest = i
                        for(var j = i + 1; j < 100; j++)
                            if(dataModelSelect.get(smallest).value < dataModelSelect.get(j).value)
                                smallest = j
                        console.log("i=" + i)
                        console.log("smallest=" + smallest)
                        var value = dataModelSelect.get(smallest).value
                        dataModelSelect.remove(smallest)
                        dataModelSelect.insert(0, {value: value})
                    }

                }
            }
        }

        ListView {
            id: viewSelect
            orientation: ListView.Horizontal
            anchors.margins: 10
            height: 100
            width: parent.width
            spacing: 1
            model: dataModelSelect
            add: Transition {
                NumberAnimation { properties: "x,y"; from: 100; duration: 1000 }
            }
            displaced : Transition {
                NumberAnimation { properties: "x,y"; duration: 100; easing.type: Easing.OutBounce }
            }
            delegate: Rectangle {
                width: 12
                height: view.height

                Rectangle{
                    width: 12
                    height: model.value
                    anchors.bottom: parent.bottom
                    color: "skyblue"
                }

                Text {
                    anchors.centerIn: parent
                    renderType: Text.NativeRendering
                    text: model.value
                    font.pixelSize: 9
                }
            }

        }

    }
}
