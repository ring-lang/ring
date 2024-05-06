/*
**
** LecturesTracker Application
**
*/

# Load Ring Libraries 
load "guilib.ring"
load "stdlibcore.ring"

# Load Project Files 
load "webapi.ring"
load "globals.ring"
load "getdata.ring"
load "history.ring"
load "map.ring"

# Import classes in the GUI package 
import System.GUI 

oApp = new QApp {

	styleFusion()

	w = new QWidget() {

		setWindowTitle(C_TITLE) 
		resize(730,800) 
		setStyleSheet("font-size:18pt;")
		if ! isMobile()
			setWinIcon(self,"web.png")
		ok

		lblTitle = new QLabel(w) {
			setText(C_TITLE)
			setAlignment(Qt_AlignHCenter)
			setMaximumHeight(50)
		}

		TableHistory = new tableWidget(w) {
			setStyleSheet("font-size:12pt;")
			setColumnCount(5)
			setHorizontalHeaderItem(1, new QTableWidgetItem(C_DATECOL))
			setHorizontalHeaderItem(2, new QTableWidgetItem(C_TIMECOL))
			setHorizontalHeaderItem(3, new QTableWidgetItem(C_ATTENDANCEPERCENTAGECOL))
			setHorizontalHeaderItem(4, new QTableWidgetItem(C_INSCOL))
			setHorizontalHeaderItem(5, new QTableWidgetItem(C_SUBJECTCOL))
			setColumnwidth(1,140)
			setColumnwidth(2,130)
			setColumnwidth(3,120)
			setColumnwidth(4,130)
			setColumnwidth(5,130)
			setSelectionBehavior(QAbstractItemView_SelectRows)
			setSelectionMode(QAbstractItemView_SingleSelection)
			setAlternatingRowColors(True)
			setEditTriggers(False)	
			setItemSelectionChangedEvent("selectRecordInHistory()")	
			setItemDoubleClickedEvent("openMap()")
		}

		btnClearHistory = new QPushButton(w) {
			setText(C_CLEARHISTORY)
			setClickEvent("clearHistory()")
		}

		lblAttendancePercentage = new QLabel(w) {
			setText(C_ATTENDANCEPERCENTAGE)
			setAlignment(Qt_AlignHCenter)
			setMaximumHeight(50)
		}
		prgAttendancePercentage = new QProgressBar(w) {
			setvalue(0)
		}
		lblIns = new QLabel(w) {
			setText(C_INS)
			setAlignment(Qt_AlignHCenter)
			setMaximumHeight(50)
		}
		lblSubject = new QLabel(w) {
			setText(C_SUBJECT)
			setAlignment(Qt_AlignHCenter)
			setMaximumHeight(50)
		}

		btnGetData = new QPushButton(w) {
			setText(C_GETDATA)
			setClickEvent("getDataFromTheInternet()")
		}
		btnOpenMap = new QPushButton(w) {
			setText(C_OPENMAP)
			setClickEvent("openMap()")
			setEnabled(False)
		}

		oLayout = new qVBoxlayout() {
			addWidget(lblTitle)
			addWidget(tableHistory)
			addWidget(btnClearHistory)
			addWidget(lblAttendancePercentage)
			addWidget(prgAttendancePercentage)
			addWidget(lblIns)
			addWidget(lblSubject)
			addWidget(btnGetData)
			addWidget(btnOpenMap)
		}
		setlayout(oLayout)

		readHistoryFile()
		displayHistoryData()

		show()
	}
	exec()
}

