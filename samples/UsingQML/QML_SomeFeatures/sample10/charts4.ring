load "guilib.ring"

writeQMLfile()

new qApp {
	w = new qWidget() {
		setWindowTitle("Using QML - Display Chart") resize(650,650) move(100,100)
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
import QtCharts 2.0

ChartView {

    width: 600
    height: 600
    theme: ChartView.ChartThemeBrownSand
    antialiasing: true

    PieSeries {
        id: pieSeries
        PieSlice { label: "Volkswagen"; value: 13.5 }
        PieSlice { label: "Toyota"; value: 10.9 }
        PieSlice { label: "Ford"; value: 8.6 }
        PieSlice { label: "Skoda"; value: 8.2 }
        PieSlice { label: "Volvo"; value: 6.8 }
    }
}

`)
