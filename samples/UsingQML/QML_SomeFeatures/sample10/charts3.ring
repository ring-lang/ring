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

    ValueAxis {
        id: valueAxis
        min: 2000
        max: 2011
        tickCount: 12
        labelFormat: "%.0f"
    }

    AreaSeries {
        name: "Russian"
        axisX: valueAxis
        upperSeries: LineSeries {
            XYPoint { x: 2000; y: 1 }
            XYPoint { x: 2001; y: 1 }
            XYPoint { x: 2002; y: 1 }
            XYPoint { x: 2003; y: 1 }
            XYPoint { x: 2004; y: 1 }
            XYPoint { x: 2005; y: 0 }
            XYPoint { x: 2006; y: 1 }
            XYPoint { x: 2007; y: 1 }
            XYPoint { x: 2008; y: 4 }
            XYPoint { x: 2009; y: 3 }
            XYPoint { x: 2010; y: 2 }
            XYPoint { x: 2011; y: 1 }
        }
    }
}

`)
