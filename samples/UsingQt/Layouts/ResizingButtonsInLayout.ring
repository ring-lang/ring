load "stdlib.ring"
load "guilib.ring"

C_ROWCOUNT = 6
C_COLCOUNT = 4
C_SPACING = 5
aButtons = list(C_ROWCOUNT,C_COLCOUNT)
LayoutButtonRow = list(C_ROWCOUNT)

app = new qApp {
	StyleFusion()
	win = new qWidget() {
		setWindowTitle('Resizing buttons in Layout')
		move(490,100) resize(600,600)
		setstylesheet('background-color:white')
		LayoutButtonMain = new QVBoxLayout()
		LayoutButtonMain.setSpacing(C_SPACING)
		LayoutButtonMain.setContentsmargins(0,0,0,0)
		for Row = 1 to C_ROWCOUNT
			LayoutButtonRow[Row] = new QHBoxLayout() {
				setSpacing(C_SPACING)
				setContentsmargins(0,0,0,0)
			}
			for Col = 1 to C_COLCOUNT
				aButtons[Row][Col] = new QPushButton(win) {
					setstylesheet('background-color:Yellow')
					setSizePolicy(1,1)
				}
				LayoutButtonRow[Row].AddWidget(aButtons[Row][Col])
			next
			LayoutButtonMain.AddLayout(LayoutButtonRow[Row])
		next
		setLayout(LayoutButtonMain)
		show()
	}
	exec()
}
