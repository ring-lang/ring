load "guilib.ring"

new qApp {
	win = new qWidget() {
		resize(600,600)
		SetWindowTitle("Change Focus")
		text1 = new qLineEdit(win)
		text2 = new qLineEdit(win)
		text3 = new qLineEdit(win)
		text4 = new qLineEdit(win)
		layout1 = new qVBoxLayout() {
			AddWidget(text1)
			AddWidget(text2)
			AddWidget(text3)
			AddWidget(text4)

		}
		setLayout(Layout1)
		aList = [text1,text2,text3,text4]
		oFilter = new qallevents(win)
		oFilter.setKeyPressEvent("pWork()")
		installeventfilter(oFilter)
		show()
	}
	exec()
}

func pWork
	nCode =  oFilter.getkeycode()
	if nCode = 16777220 
		for x=1 to len(aList) 
			if aList[x].HasFocus() 
				t = x+1
				if t > len(aList) t=1 ok
				aList[t].SetFocus(0)
				exit
			ok
		next
	ok
