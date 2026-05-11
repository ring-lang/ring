/*
	We can create objects from the RingCode class then pass it to QML	
	QML can execute the click event to call Ring Code from QML

*/

aRingCodeObjects = []

func cleanRingCode 
	for oObj in aRingCodeObjects 
		oObj.close()
	next
	aRingCodeObjects = []

class RingCode from QPushButton

	func init oParent,cName,cCode
		cClass = classname(oParent)
		switch cClass 
		on :QQuickwidget
			super.init(oParent)
		on :QQuickView
			super.init(NULL)
			aRingCodeObjects + ref(self)
		other 
			raise("Unexpected parent type for RingCode")
		off
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

class RingQMLApp from QApp

	func braceEnd

		cleanRingCode()