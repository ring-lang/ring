load "guilib.ring"
load "stdlibcore.ring"

C_ROWS = 5
C_COLS = 7

new QApp {

	StyleFusion()

	w = new QWidget() {

		setStyleSheet("background-color:yellow;")
		setWindowTitle("Using QGridLayout & setSizePolicy")

		g = new QGridLayout() 

		aButtons = list(C_ROWS,C_COLS)
		for t = 1 to C_ROWS
			for t2=1 to C_COLS
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
