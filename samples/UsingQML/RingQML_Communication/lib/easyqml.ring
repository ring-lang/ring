/*
	We can create objects from this class then pass it to QML	
	QML can execute the click event to call Ring Code from QML

*/
class RingCode from QPushButton

	func init oParent,cName,cCode
		super.init(oParent)
		cCode = trim(cCode)
		if substr(cCode,"_ring_anonymous_func_") and right(cCode,1) != ")"
			cCode += "()"
		ok
		setClickEvent(cCode)
		oContext = oParent.rootContext()
		oContext.setContextPropertyUsingObject(cName,self)
		setFocusPolicy(0)	// Qt_NoFocus
		hide()
		return self
