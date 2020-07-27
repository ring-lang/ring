Load "guilib.ring"

New qApp {

	w = new qWidget()
	{
		setWindowTitle("Minimize Window Sample")
		resize(500,500)
		b = new qPushButton(w)
		{
			setText("Minimize")
			setClickEvent("w.showminimized()")
		}		
		show()
	}
	exec()
}
