Import system.web

func testregister
	new page {
		boxstart()
			text( "Register")
		 	newline()
		boxend()
		divstart([:style = stylegradient(6) + stylesize("100%","95%") ])
		link([ :url = website, :title = "back" , :style = stylecolor("white")])
		newline()
		divstart([ :style= styledivcenter("500","160") + stylegradient(52) ])
		formpost(website)
			hidden("page",21)
			tablestart([ :Style =  stylemarginleft("2%") + stylemargintop("2%") + stylewidth("90%") ])
				rowstart([])
					cellstart([:style = stylewidth("20%") + styleheight(30)])
						text("User Name")
					cellend()
					cellstart([ :style = stylewidth("80%")  ])
						textbox([:name = "username", :style = stylewidth("100%")])
					cellend()
				rowend()
				rowstart([])
					cellstart([ :Style = styleheight(30)])
						text("Password")
					cellend()
					cellstart([])
						textbox([:name = "password" , :type = "password"])
					cellend()
				rowend()
				rowstart([])
					cellstart([ :style = styleheight(30)])
						text("Email")
					cellend()
					cellstart([])
						textbox([:name = "email" , :style = stylewidth("100%")])
					cellend()
				rowend()
				rowstart([])
					cellstart([ :style = styleheight(30)])
					cellend()
					cellstart([ :style = styleheight(30)])
						submit([:value = "Register"  ])
					cellend()
				rowend()
			tableend()
		formend()
		divend()
		divend()
	}

func testregisternew
	oUser = new UsersModel
	oUser.Connect()
	if oUser.findwith("username",aPageVars["username"])
		new page {
			text("The user name is already registered")
		}
		return
	ok
	if oUser.findwith("email",aPageVars["email"])
		new page {
			text("This email is already registered")
		}
		return
	ok

	aPageVars["salt"] = str2hex(RandBytes(32))
	aPageVars["pwhash"] = sha256(aPagevars["password"]+aPageVars["salt"])
	aPageVars["sessionid"] = str2hex(randbytes(32))
	oUser.Insert()
	new page {
		cookie("sessionid",aPageVars["sessionid"])
		text("New User Created!")
		newline()
		text("User Name : " + aPageVars["username"])
		newline()
	}
	oUser.Disconnect()

func testlogin
	new page {
		boxstart()
			text( "Login")
		 	newline()
		boxend()
		divstart([:style = stylegradient(6) + stylesize("100%","95%") ])
		link([ :url = website, :title = "back" , :style = stylecolor("white")])
		newline()
		divstart([ :style= styledivcenter("500","130") + stylegradient(52) ])
		formpost(website)
			hidden("page",22)
			tablestart([ :Style =  stylemarginleft("2%") + stylemargintop("2%") + stylewidth("90%") ])
				rowstart([])
					cellstart([:style = stylewidth("20%") + styleheight(30)])
						text("User Name")
					cellend()
					cellstart([ :style = stylewidth("80%") ])
						textbox([:name = "username", :style = stylewidth("100%")])
					cellend()
				rowend()
				rowstart([])
					cellstart([ :style = styleheight(30)])
						text("Password")
					cellend()
					cellstart([])
						textbox([:name = "password" , :type = "password"])
					cellend()
				rowend()
				rowstart([])
					cellstart([ :style = styleheight(30) ])
					cellend()
					cellstart([])
						submit([:value = "Login"  ])
					cellend()
				rowend()
			tableend()
		formend()
		divend()
		divend()
	}

func testlogincheck
	oUser = new UsersModel
	oUser.Connect()
	lResult = oUser.FindWith("username",aPageVars["username"])
	new page {
		if lResult
			if sha256(aPagevars["password"]+oUser.Salt) = oUser.pwhash
				text ("Correct Password!")
				aPageVars["sessionid"] = str2hex(randbytes(32))
				oUser.UpdateColumn("sessionid",aPageVars["sessionid"])
				cookie("sessionid",aPageVars["sessionid"])
			else
				text ("Bad password!")
			ok
		else
			text("Bad User Name!")
		ok
	}
	oUser.Disconnect()

Func checkuser
	oUser = new UsersModel
	oUser.Connect()
	lResult = oUser.FindWith("sessionid",aPageVars["sessionid"])
	new page {
		if lResult
			text("User Name : " + oUser.username )
		else
			text("Please Login First!")
		ok
	}
	oUser.Disconnect()

Class UsersModel from ModelBase
	cSearchColumn = "username"

Class UsersController From ControllerBase
	cMainURL = website + "?page=24&"
	aColumnsNames = ["id","username","email"]

	func UpdateRecord
		oModel.id = aPageVars[cRecID]
		oModel.updatecolumn("username", aPageVars[:username] )
		oModel.updatecolumn("email", aPageVars[:email] )
		oView.UpdateView(self)

Class UsersLanguageEnglish
	cTitle = "Users Table"
	cBack = "back"
	aColumnsTitles = ["ID","User Name","Email"]
	cOptions = "Options"
	cSearch = "Search"
	comboitems = ["Select Option...","Edit","Delete"]
	cAddRecord = "Add Record"
	cEditRecord = "Edit Record"
	cRecordDeleted = "Record Deleted!"
	aMovePages = ["First","Prev","Next","Last"]
	cPage = "Page"
	cOf = "of"
	cRecordsCount = "Records Count"
	cSave = "Save"
	temp = new page
	cTextAlign = temp.StyleTextRight()
	cNoRecords = "No records!"

Class UsersView from ViewBase

	oLanguage = new UsersLanguageEnglish

	func HiddenVars oPage
		oPage.hidden("page",24)

	func AddFuncScript oPage,oController
		return 	oPage.scriptfunc("myadd",oPage.scriptredirection(website+"?page=19"))

	Func FormViewContent oController,oTranslation,oPage
		return [
			[oTranslation.aColumnsTitles[2],"textbox","username",oController.oModel.UserName,oPage.stylewidth("100%")],
			[oTranslation.aColumnsTitles[3],"textbox","email",oController.oModel.Email,oPage.stylewidth("50%")]
		       ]
