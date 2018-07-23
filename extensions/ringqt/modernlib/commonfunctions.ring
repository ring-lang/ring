cDialogIcon = ""

func setwinicon pWindow,cImage
	if cImage = NULL return ok		
	pWindow.setWindowIcon(new qicon(new qpixmap(cImage)))
		
func setbtnimage pBtn,cImage
	if cImage = NULL return ok		
	pBtn.setIcon(new qicon(new qpixmap(cImage)))

func SetDialogIcon cFile
	cDialogIcon = cFile
	
func MsgInfo cTitle,cMessage
        new qmessagebox(null)
        {
		setwindowtitle(cTitle)
		setwindowflags(Qt_CustomizeWindowHint | Qt_WindowTitleHint | Qt_WindowStaysOnTopHint) 
                setstandardbuttons(QMessageBox_Ok)
                settext(cMessage) 	
		if cDialogIcon != NULL
			setwinicon(self,cDialogIcon)
		ok
		exec()
        }

func confirmMsg cTitle,cMessage
        new qmessagebox(null)
        {
		setwindowtitle(cTitle)
		setwindowflags(Qt_CustomizeWindowHint | Qt_WindowTitleHint | Qt_WindowStaysOnTopHint) 
                setstandardbuttons(QMessageBox_Yes | QMessageBox_No)
                settext(cMessage) 
		if cDialogIcon != NULL
			setwinicon(self,cDialogIcon)
		ok
                result = exec()
        }
	if result = QMessageBox_Yes return 1 ok
	return 0
                       
func InputBox cTitle,cMessage
        oInput = new QInputDialog(null)
        {
		setwindowtitle(cTitle)
		setwindowflags(Qt_CustomizeWindowHint | Qt_WindowTitleHint | Qt_WindowStaysOnTopHint) 
		setgeometry(100,100,400,50)
		setlabeltext(cMessage)
		if cDialogIcon != NULL
			setwinicon(self,cDialogIcon)
		ok
		lcheck = exec()
        }
	if lCheck return oInput.textvalue() ok

func InputBoxInt cTitle,cMessage
        oInput = new QInputDialog(null)
        {
        	setwindowtitle(cTitle)
		setwindowflags(Qt_CustomizeWindowHint | Qt_WindowTitleHint | Qt_WindowStaysOnTopHint) 
                setgeometry(100,100,400,50)
                setlabeltext(cMessage)
		setInputMode(1)	# Accept Number (int)
		if cDialogIcon != NULL
			setwinicon(self,cDialogIcon)
		ok
		lcheck = exec()
        }
	if lCheck return oInput.intvalue() ok


func InputBoxNum cTitle,cMessage
        oInput = new QInputDialog(null)
        {
        	setwindowtitle(cTitle)
		setwindowflags(Qt_CustomizeWindowHint | Qt_WindowTitleHint | Qt_WindowStaysOnTopHint) 
                setgeometry(100,100,400,50)
                setlabeltext(cMessage)
		setInputMode(2)	# Accept Number (Double)
		if cDialogIcon != NULL
			setwinicon(self,cDialogIcon)
		ok
		lcheck = exec()
        }
	if lCheck return oInput.doublevalue() ok

func InputBoxPass cTitle,cMessage
        oInput = new QInputDialog(null)
        {
		setwindowtitle(cTitle)
		setwindowflags(Qt_CustomizeWindowHint | Qt_WindowTitleHint | Qt_WindowStaysOnTopHint) 
		setgeometry(100,100,400,50)
		setlabeltext(cMessage)
		setTextEchoMode(2)	# Password
		if cDialogIcon != NULL
			setwinicon(self,cDialogIcon)
		ok
		lcheck = exec()
        }
	if lCheck return oInput.textvalue() ok

func AppFile cFile
	cFile = substr(cFile,"\","/")
	if find(cfunctions(),"ismobileqt")
		if ismobileqt()
			cFile = ":/"+substr(cFile,"\","/")
		ok
	ok
	return cFile

func ismobile
	if find(cfunctions(),"ismobileqt")
		if ismobileqt()
			return True
		ok
	ok
	return False
