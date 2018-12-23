new qmessagebox(parent().oView.win)
see "done" + nl

func parent
	obj = new myview
	return obj

class myview
	oView = new myview2

class myview2
	win = 10

class qmessagebox
	func init test
		see "welcome" + nl
		see test + nl
