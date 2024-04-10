#==================================#
# Customers Application
# Chokri <printhiver@gmail.com>
#==================================#

load "guilib.ring"
load "stdlibcore.ring"

load "translation/en.ring"
load "mylib.ring"
load "css.ring"

import System.GUI

oApp = new QApp {

	styleFusion()

	db_name = "zaghtechnologies"

	date = TimeList()[6] + "-" + TimeList()[10] + "-" + TimeList()[19]
	time = TimeList()[7] + ":" + TimeList()[11] + ":" + TimeList()[13]
	
	frmClients = new MainWindow()

	lblDate = new qLabel(frmClients) {
		setText(aLANGUAGE[:LBL_DATE_TEXT]+" "+date)
		if T_LANGUAGE = "ar"
			setgeometry(520,-15,200,50)
		else
			setgeometry(10,-15,200,50)
		ok
		oFont = new qfont("",0,0,0)
		oFont.fromstring("Arial,12,-1,5,60,0,0,0,0,0,Gras")
		setfont(oFont)
		oFont.delete()
		setStylesheet("color:#2b5392")
	}

	new qTimer(frmClients) {
		setInterVal(10)
		setTimeOutEvent("pMove()")
		start()
	}

	lblRef = new qLabel(frmClients) {
		setText(aLANGUAGE[:LBL_REF_TEXT])
		if T_LANGUAGE = "ar"
			setGeometry(300,20,70,27)
		else
			setGeometry(5,20,70,25)
		ok
		oFont = new qfont("",0,0,0)
		oFont.fromstring(labelFont)
		setfont(oFont)
		oFont.delete()
		setStylesheet("color:#2b5392")
	}

	leditRef = new qLineEdit(frmClients) {
		if T_LANGUAGE = "ar"
			setGeometry(130,20,177,25)
		else
			setGeometry(80,20,177,27)
		ok
		oFont = new qfont("",0,0,0)
		oFont.fromstring("Arial,7,-1,5,75,0,0,0,0,0,Gras")
		setfont(oFont)
		oFont.delete()
		setstylesheet("color:rgba(0, 0, 255, 0.4);background-color:rgba(0, 0, 255, 0.3)")
		setText("")
	}

	lblNom = new qLabel(frmClients) {
		setText(aLANGUAGE[:LBL_NAME_TEXT])
		if T_LANGUAGE = "ar"
			setGeometry(300,50,70,27)
		else
			setGeometry(5,50,70,25)
		ok
		oFont = new qfont("",0,0,0)
		oFont.fromstring(labelFont)
		setfont(oFont)
		oFont.delete()
		setStylesheet("color:#2b5392")
	}

	leditNom = new qLineEdit(frmClients) {
		if T_LANGUAGE = "ar"
			setGeometry(130,50,177,25)
		else
        		setGeometry(80,50,177,27)
		ok
		oFont = new qfont("",0,0,0)
		oFont.fromstring("Arial,7,-1,5,80,0,0,0,0,0,Gras")
		setfont(oFont)
		oFont.delete()
		setstylesheet("color:#fff;background-color:rgba(0, 0, 255, 0.6)")
		setText("")
	}

	lblEmail = new qLabel(frmClients) {
		setText(aLANGUAGE[:LBL_EMAIL_TEXT])
		if T_LANGUAGE = "ar"
			setGeometry(300,80,70,27)
		else
        		setGeometry(5,80,70,25)
		ok
		oFont = new qfont("",0,0,0)
		oFont.fromstring(labelFont)
		setfont(oFont)
		oFont.delete()
		setStylesheet("color:#2b5392")
	}

	leditEmail = new qLineEdit(frmClients) {
		if T_LANGUAGE = "ar"
			setGeometry(130,80,177,25)
			setstylesheet("text-align:right")
		else
        		setGeometry(80,80,177,27)
		ok
		oFont = new qfont("",0,0,0)
		oFont.fromstring("Arial,7,-1,5,80,0,0,0,0,0,Gras")
		setfont(oFont)
		oFont.delete()
		setstylesheet("color:#fff;background-color:rgba(0, 0, 255, 0.6)")
		setText("")
	}
	
	lblAddress = new qlabel(frmClients) {
		setText(aLANGUAGE[:LBL_ADDRESS_TEXT])
		if T_LANGUAGE = "ar"
			setGeometry(300,110,70,27)
		else
			setGeometry(5,110,90,25)
		ok
		oFont = new qfont("",0,0,0)
		oFont.fromstring(labelFont)
		setfont(oFont)
		oFont.delete()
		setStylesheet("color:#2b5392")
	}

	txtAddress = new qTextEdit(frmClients) {
		if T_LANGUAGE = "ar"
			setGeometry(130,110,177,55)
		else
			setGeometry(80,110,177,55)
		ok
		oFont = new qfont("",0,0,0)
		oFont.fromstring("Arial,7,-1,5,80,0,0,0,0,0,Gras")
		setfont(oFont)
		oFont.delete()
		setstylesheet("color:#fff;background-color:rgba(0, 0, 255, 0.6)")
		setText("")
	}

	lblImg = new qlabel(frmClients) {
		if T_LANGUAGE = "ar"
			setGeoMetry(5,20,120,120)
		else
			setGeoMetry(260,20,120,120)
		ok
		if not hasscaledcontents()
			setscaledcontents(1) ok
		setstylesheet("
			background-color:;
			border:1px solid #2b5392;
			border-radius:5px
		")
	}

	btnEditImage = new PushButton(frmClients) {
		if T_LANGUAGE = "ar"
			setGeometry(5,143,120,20)
		else
			setGeometry(260,143,120,20)
		ok
		setStyleSheet(cssButton)
		setCursor(btnCursor)
		setClickEvent("editImage(tblClients)")
	}

	# showing clock

	dc = new DegitClock(frmClients)
	frameLClock = dc.getMediumClock()
	dc.setColorClock("#0C6530",false,false)
	frameLClock.move(610,20)

	# end showing clock

	lblLogoImg = new qlabel(frmClients) {
		setGeoMetry(400,70,300,90)
		if not hasscaledcontents()
			setscaledcontents(1) ok
		setPixMap(New qPixMap("images/logos/zaghtech-removebg.png"))
	}

	# controlsTool
	btnFirst = new qpushbutton(frmClients) {
		settext(aLANGUAGE[:FIRSTCUST])
		setclickevent("getFirst(tblClients)") 
	}
	btnPrev = new qpushbutton(frmClients) {
		settext(aLANGUAGE[:PREVIEWCUST])
		setclickevent("getPrev(tblClients)")
	}
	btnNext = new qpushbutton(frmClients) {
		settext(aLANGUAGE[:NEXTCUST])
		setclickevent("getNext(tblClients)")
	}
	btnLast = new qpushbutton(frmClients) {
		settext(aLANGUAGE[:LASTCUST])
		setclickevent("getLast(tblClients)")
	}

	# actionsTool
	btnAdd = new qpushbutton(frmClients) {
		settext(aLANGUAGE[:BTN_ADD_NEW_TEXT])
		setclickevent("newClient()")
	}
	btnEdit = new qpushbutton(frmClients) {
		settext(aLANGUAGE[:BTN_EDIT_TEXT])
		setclickevent("editCl()")
	}
	btnSave = new qpushbutton(frmClients){
		setText(aLANGUAGE[:BTN_SAVE_TEXT])
		setClickEvent("saveClient(tblClients)")
	}
	btnCancel = new qpushbutton(frmClients) {
		settext(aLANGUAGE[:BTN_CANCEL_TEXT])
		setclickevent("cancel_action(tblClients)")
	}
	btnDel = new qpushbutton(frmClients) {
		settext(aLANGUAGE[:BTN_DEL_TEXT])
		setClickEvent("delClient(tblClients)")
	}
	btnExit = new qpushbutton(frmClients) { 
		settext(aLANGUAGE[:BTN_EXIT_TEXT])
		settooltip(aLANGUAGE[:BTN_EXIT_TOOLTIP])
        	setclickevent("oApp.quit()") 
	}

	aControls = [btnFirst, btnPrev, btnNext, btnlast]
	aActions  = [btnAdd, btnEdit, btnSave, btnCancel, btnDel, btnExit]

	controlsTool = new qtoolbar(frmClients) {
		for x in aControls
			x {
				oFont = new qfont("",0,0,0)
				oFont.fromstring("Arial,9,-1,5,80,0,0,0,0,0,Gras")
				setfont(oFont)
				oFont.delete()
				setstylesheet(cssButton)
				setCursor(btnCursor)
			}
			addwidget(x) addseparator()
		next 
		setmovable(0)
		if T_LANGUAGE = "ar"
			setGeometry(-250,180,610,30)
		else
			setGeometry(20,180,610,30)
		ok
		setFloatable(0)
	}

	actionsTool = new qtoolbar(frmClients) {
		for x in aActions
			x {		
				oFont = new qfont("",0,0,0)
				oFont.fromstring("Arial,9,-1,5,80,0,0,0,0,0,Gras")
				setfont(oFont)
				oFont.delete()
				setstylesheet(cssButton)
				setCursor(btnCursor)
			}
			addwidget(x) addseparator()
		next
		setmovable(0)
		if T_LANGUAGE = "ar"
			setGeometry(-65,210,600,30)
		else
			setGeometry(20,210,600,30)
		ok
		setFloatable(0)
	}

	ringLink = new label(frmClients) {
		setGeometry(630,190,220,21)
		setstylesheet("background-color:;")
		oFont = new qfont("",0,0,0)
		oFont.fromstring("Arial,8,-1,5,50,0,0,0,0,0,Normal")
		setfont(oFont)
		oFont.delete()
		setOpenExternallinks(true)
		setText('<a href="http://www.ring-lang.net">'+aLANGUAGE[:RING_LANGUAGE_WEBSITE]+'</a>')
	}

	lblCount = new qlabel(frmClients){
		setGeometry(630,210,135,25)
		oFont = new qfont("",0,0,0)
		oFont.fromstring(labelFont)
		setfont(oFont)
		oFont.delete()
		setStylesheet("border:1px solid #490383;background-color:#490383;color:white")
		setText("")
	}

	txtSearch = new qlineedit(frmClients){
		setGeometry(20,245,250,25)
		oFont = new qfont("",0,0,0)
		oFont.fromstring("Arial,8,-1,5,75,0,0,0,0,0,Gras")
		setfont(oFont)
		oFont.delete()
		setText("")
		setTextChangedEvent("searchCl2(tblClients)")
	}

	checkAutoSearch = new qcheckbox(frmClients) {
		if T_LANGUAGE = "ar"
			setGeometry(275,245,75,24)
		else setGeometry(275,245,115,24)
		ok
		oFont = new qfont("",0,0,0)
		oFont.fromstring(labelFont)
		setfont(oFont)
		oFont.delete()
		setText(aLANGUAGE[:AUTO_SEARCH])
		setstylesheet("color:#2b5392;background-color:;")
		settoggledEvent("pAutoSearchToggledEvent()")
		setChecked(True)
	}

	comboBox1 = new QComboBox(frmClients) {
		if T_LANGUAGE = "ar"
			setGeometry(335,245,70,20)
		else
			setGeometry(390,242,115,30)
		ok
		aComboCols = ["Ref","Nom","Email","Adresse"]
		aComboText = [aLANGUAGE[:FILTER],
				substr(aLANGUAGE[:LBL_REF_TEXT],":",""),
				substr(aLANGUAGE[:LBL_NAME_TEXT],":",""),
				substr(aLANGUAGE[:LBL_EMAIL_TEXT],":",""),
				substr(aLANGUAGE[:LBL_ADDRESS_TEXT],":","")
				]
		for x in aComboText additem(x, 0) next
		setCurrentIndex(2)
		setStylesheet("color:#2b5392")
		setcurrentIndexChangedEvent("pCbxIndexCanged()")
	}

	btnSearch = new qpushbutton(frmClients) {
		setText(aLANGUAGE[:BTN_SEARCH_TEXT])
		if T_LANGUAGE = "ar"
			setGeometry(500,242,70,30)
		else
			setGeometry(530,242,70,30)
		ok
		oFont = new qfont("",0,0,0)
		oFont.fromstring("Arial,9,-1,5,80,0,0,0,0,0,Gras")
		setfont(oFont)
		oFont.delete()
		setstylesheet(cssButton)
		setCursor(btnCursor)
		setClickEvent("searchCl(tblClients)")
	}

	btnFillAll = new qpushbutton(frmClients) {
		setText(aLANGUAGE[:BTN_FILL_TEXT])
		setGeometry(630,242,115,30)
		oFont = new qfont("",0,0,0)
		oFont.fromstring("Arial,9,-1,5,80,0,0,0,0,0,Gras")
		setfont(oFont)
		oFont.delete()
		setstylesheet(cssButton)
		setCursor(btnCursor)
		setClickEvent("fill_data(tblClients)")
	}

	tblClients = new qTableWidget(frmClients) {
		setGeometry(10,285,750,300)
		setStyleSheet(cssTable)
		setShowGrid(1)
		oFont = new Font("Tahoma",9,100,0)
		horizontalheader().setFont(oFont)
		oFont.delete()
		horizontalheader().setStylesheet(cssHHeader)
		horizontalheader().setSelectionMode(QAbstractItemView_NoSelection)
		verticalHeader().hide()
		setselectionbehavior(QAbstractItemView_SelectRows)
		setSelectionMode(QAbstractItemView_SingleSelection)
		setEditTriggers(QAbstractItemView_NoEditTriggers)
		setAlternatingRowColors(1)
		setitemSelectionChangedEvent("get_data(tblClients)")
	}

	Statusbar = new statusbar(frmClients) { 
		setStylesheet("background-color:#fff;color:#490383")
		oFont = new qfont("",0,0,0)
		oFont.fromstring("Arial,7,-1,5,55,0,0,0,0,0,Normal")
		setfont(oFont)
		oFont.delete()
	
		ShowMessage(aLANGUAGE[:RING_VERSION] + version() , 0)
		frmClients.setStatusBar(Statusbar)
	}

	frmClients {
		oFilter = new qAllEvents(frmClients) { 
			setCloseEvent("pFormClosed()") 
		}
		frmClients.installeventfilter(oFilter)
		resize(770, 610)
		setWindowTitle(aLANGUAGE[:TITLE])
		setWinIcon(frmClients, "images/logos/zaghtechnologies.png")
		oFont = new qfont("",0,0,0)
		oFont.fromstring("Tahoma,8,-1,5,75,0,0,0,0,0,Gras")
		setfont(oFont)
		oFont.delete()	
		setstylesheet("background-color:white")
		setlayoutdirection(T_LAYOUTDIRECTION)
	
		sqlite_connect_now()
		fill_data(tblClients)
		Show()
	}
	
	Exec()
	Shutdown()

}


func pAutoSearchToggledEvent

	checkAutoSearch {
		if ischecked()
			disableBtns(aControls)
			setstylesheet("color:#490383")
		else 
			fill_data(tblClients)
			checkRowIndex(tblClients)
			setstylesheet("color:#2b5392")
			txtSearch {
				setStylesheet("background-color:none;color:black")
				setText("")
			}
		ok
	}

func pCbxIndexCanged

	cFilter = comboBox1.currentText()
	if cFilter = aLANGUAGE[:FILTER]
		txtSearch {
			setStylesheet("background-color:none;color:black")
			setText("")
		}
		comboBox1.setstylesheet("color:#2b5392")
	else 
		comboBox1.setstylesheet("color:#490383")
	ok

func pMove

	lblDate {
		if T_LANGUAGE = "ar"
			move( x()-1, y() )
			if x() < -lblDate.width()
				move( frmClients.width(), y() ) ok
		else
			move( x()+1, y() )
			if x() > frmClients.width() 
				move( -lblDate.width(), y() ) ok
		ok
	}

func pFormClosed

	sqlite_close_now()

func pQuitter

	sqlite_close_now()
	oApp.quit()
