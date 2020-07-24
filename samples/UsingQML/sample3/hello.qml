import QtQuick 2.1
import QtQuick.Controls 1.4
import QtQuick.Layouts  1.0
import QtQuick.Controls.Styles 1.0

Rectangle {
	id: rectangle
	color: "White"
	width: 600
	height: 600
	ColumnLayout {
        anchors.fill: parent
        spacing: 6
		Button {
			text: "One"
            		Layout.fillWidth: true
			style: ButtonStyle {
			        background: Rectangle {
					color: "Yellow"
			        }
			}
		}
	 	Button {
			text: "Two"
            		Layout.fillWidth: true
			style: ButtonStyle {
			        background: Rectangle {
					color: "Green"
			        }
			}
		}
		Button {
			text: "Three"
            		Layout.fillWidth: true
			style: ButtonStyle {
			        background: Rectangle {
					color: "Blue"
			        }
			}
		}
		Button {
			text: "Four"
            		Layout.fillWidth: true
			style: ButtonStyle {
			        background: Rectangle {
					color: "White"
			        }
			}
		}
	}
}
