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

    SplineSeries {
        name: "SplineSeries"
        XYPoint { x: 0; y: 0.0 }
        XYPoint { x: 1.1; y: 3.2 }
        XYPoint { x: 1.9; y: 2.4 }
        XYPoint { x: 2.1; y: 2.1 }
        XYPoint { x: 2.9; y: 2.6 }
        XYPoint { x: 3.4; y: 2.3 }
        XYPoint { x: 4.1; y: 3.1 }
    }
}

`)
