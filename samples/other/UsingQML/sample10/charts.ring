load "guilib.ring"

writeQMLfile()

new qApp {
	w = new qWidget() {
		setWindowTitle("Using QML - Display Chart") resize(600,400) move(100,100)
		oQuick = new qQuickWidget(w) {
			engine().AddImportPath(exefolder()+"qml")
			setSource(new qURL("hello.qml") )
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
    width: 400
    height: 300
    theme: ChartView.ChartThemeBrownSand
    antialiasing: true

    PieSeries {
        id: pieSeries
        PieSlice { label: "eaten"; value: 94.9 }
        PieSlice { label: "not yet eaten"; value: 5.1 }
    }
}

`)
