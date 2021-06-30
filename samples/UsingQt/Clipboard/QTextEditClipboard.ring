load "guilib.ring"

oApp = new QApp {
	w = new QWidget() {
		setWindowTitle("Copy Text to Clipboard (Try Ctrl+V) ")
		resize(400,100)
		l = new MyClipboard(w) {
			setText("I Love Ring Programming!")
		}
		t = new QLineEdit(w)
		show()
	}
	exec()
}

class MyClipboard from QTextedit 

	func init oParent 
		super.init(oParent)
		hide()
		return self 

	func setText cText 
		super.setText(cText)
		selectall() 
		copy()
