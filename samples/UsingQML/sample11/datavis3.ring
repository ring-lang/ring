load "guilib.ring"

writeQMLfile()

new qApp {
	w = new qWidget() {
		setWindowTitle("Using QML - Data Visualization") 
		resize(800,600) move(100,100)
		oQuick = new qQuickWidget(w) {
			engine().AddImportPath(exefolder()+"qml")
			setSource(AppURL("hello.qml") )
		}
		oLayout = new qVBoxlayout() {
			AddWidget(oQuick)
		}
		setlayout(oLayout)
		show()
	}
	exec()
}

func WriteQMLfile

write("hello.qml",`

import QtQuick 2.0
import QtDataVisualization 1.2

Item {
    width: 800
    height: 600

    Bars3D {
        width: parent.width
        height: parent.height
        Bar3DSeries {
            itemLabelFormat: "@colLabel, @rowLabel: @valueLabel"
            ItemModelBarDataProxy {
                itemModel: dataModel
                // Mapping model roles to bar series rows, columns, and values.
                rowRole: "year"
                columnRole: "city"
                valueRole: "expenses"
            }
        }
    }

    ListModel {
        id: dataModel
        ListElement{ year: "2012"; city: "Oulu";     expenses: "4200"; }
        ListElement{ year: "2012"; city: "Rauma";    expenses: "2100"; }
        ListElement{ year: "2012"; city: "Helsinki"; expenses: "7040"; }
        ListElement{ year: "2012"; city: "Tampere";  expenses: "4330"; }
        ListElement{ year: "2013"; city: "Oulu";     expenses: "3960"; }
        ListElement{ year: "2013"; city: "Rauma";    expenses: "1990"; }
        ListElement{ year: "2013"; city: "Helsinki"; expenses: "7230"; }
        ListElement{ year: "2013"; city: "Tampere";  expenses: "4650"; }
    }
}

`)
