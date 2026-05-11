load "guilib.ring"

writeQMLfile()

new qApp {
	w = new qWidget() {
		setWindowTitle("Using QML - Display Chart") resize(1000,600) move(100,100)
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

    width: 900
    height: 600
    theme: ChartView.ChartThemeBrownSand
    antialiasing: true

 PieSeries {
        id: pieOuter
        size: 0.96
        holeSize: 0.7
        PieSlice { id: slice; label: "Alpha"; value: 19511; color: "#99CA53" }
        PieSlice { label: "Epsilon"; value: 11105; color: "#209FDF" }
        PieSlice { label: "Psi"; value: 9352; color: "#F6A625" }
    }

    PieSeries {
        size: 0.7
        id: pieInner
        holeSize: 0.25

        PieSlice { label: "Materials"; value: 10334; color: "#B9DB8A" }
        PieSlice { label: "Employee"; value: 3066; color: "#DCEDC4" }
        PieSlice { label: "Logistics"; value: 6111; color: "#F3F9EB" }

        PieSlice { label: "Materials"; value: 7371; color: "#63BCE9" }
        PieSlice { label: "Employee"; value: 2443; color: "#A6D9F2" }
        PieSlice { label: "Logistics"; value: 1291; color: "#E9F5FC" }

        PieSlice { label: "Materials"; value: 4022; color: "#F9C36C" }
        PieSlice { label: "Employee"; value: 3998; color: "#FCE1B6" }
        PieSlice { label: "Logistics"; value: 1332; color: "#FEF5E7" }
    }

}

`)
