class QDesktopWidget

	oAppObj = new QGUIApplication
	oScreenRect = oAppObj.primaryScreen().geometry() 

	func init
		return self

	func width 
		return oScreenRect.Width()
	
	func height
		return oScreenRect.Height()
