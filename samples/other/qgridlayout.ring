load "guilib.ring"
load "stdlibcore.ring"

QSizePolicy_GrowFlag 		= 1

/*
QSizePolicy_ExpandFlag 		= 2
QSizePolicy_ShrinkFlag 		= 4
QSizePolicy_IgnoreFlag 		= 8
QSizePolicy_Fixed		= 0
QSizePolicy_Minimum		= QSizePolicy_GrowFlag
QSizePolicy_Maximum		= QSizePolicy_ShrinkFlag
QSizePolicy_Preferred		= QSizePolicy_GrowFlag | QSizePolicy_ShrinkFlag
QSizePolicy_Expanding		= QSizePolicy_GrowFlag | QSizePolicy_ShrinkFlag | QSizePolicy_ExpandFlag
QSizePolicy_MinimumExpanding 	= QSizePolicy_GrowFlag | QSizePolicy_ExpandFlag
QSizePolicy_Ignored		= QSizePolicy_ShrinkFlag | QSizePolicy_GrowFlag | QSizePolicy_IgnoreFlag
*/

new QApp {

	w = new QWidget() {

		setWindowTitle("Using QGridLayout & setSizePolicy")

		g = new QGridLayout() 

		aButtons = newlist(5,5)
		for t = 1 to 5
			for t2=1 to 5
				aButtons[t][t2] = new QPushButton(w) {
					setText(""+t+":"+t2)	
					setSizePolicy(QSizePolicy_GrowFlag,QSizePolicy_GrowFlag)
				}
				g.AddWidget(aButtons[t][t2],t-1,t2-1,0)
			next
		next

		setLayout(g)

		show()
	}

	exec()
}
