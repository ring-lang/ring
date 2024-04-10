#==================================#
# Customers Application
# Chokri <printhiver@gmail.com>
#==================================#

load "mysqlitelib.ring"
load "digital_clock.ring"

nRowIndex = 0
nNumber	  = 3
lEditMode = false
lAdd      = false

func playSound cPath
 	new qmediaplayer(){
                setmedia(new qurl(substr(currentDir(),"\","/")+"/"+cPath))
                setvolume(50) play()
        }

func confirm cTitle,cMsg,cColor

	playSound("sound/warning-beep-1.wav")

	new qmessagebox(frmClients){
		settext(cTitle)
		setInformativeText(cMsg)
		setstandardbuttons(QMessageBox_Yes | QMessageBox_No | QMessageBox_Close)
		setstylesheet("background-color:white;color:"+cColor)
		result = exec()
                frmClients {
                        if result = QMessageBox_Yes
				playSound("sound/alert-2.wav")
                                return 1
                        but result = QMessageBox_No
                                return 0
                        but result = QMessageBox_Close
                                 return 0
                        ok
                }
        }
	
func msgBox cTitle,cMsg,cColor

	new qMessageBox(frmClients) {
		setWindowTitle(cTitle)
		setText(cMsg)
		setstylesheet("background-color:white;color:"+cColor)
		show()
	}
	
func set_image lbl_img,database_img

	if database_img != "" and 
	fexists(substr(currentDir(),"\","/")+"/"+database_img)
		oImg = new qpixmap(database_img)
		lbl_img.setpixmap(oImg) 
		
		return 1
	ok
	return 0

func enableBtn oButton
	
	oButton{

		if not isEnabled()  setEnabled(1) ok

		if text() = aLANGUAGE[:BTN_DEL_TEXT]
			setstylesheet(cssDelBtn)
		else setstylesheet(cssButton)
		ok

		setCursor(btnCursor)

		}
	
func disableBtn oButton

	oButton{

		if isEnabled()  setEnabled(0) ok
		setStylesheet("background-color:#aeaeae")
	}

# Check the current index (enabled/disabled controls)
func checkRowIndex oTable

	if not checkAutoSearch.isChecked()

		nRowIndex = oTable.currentRow()
		nMax = (oTable.rowCount()-1)
	
		if nRowIndex = 0
			enableBtn(btnNext)
			disableBtn(btnFirst)
			disableBtn(btnPrev)
			enableBtn(btnLast)
			
		but nRowIndex >0 and nRowIndex < nNumber
			enableBtn(btnNext)
			enableBtn(btnFirst)
			enableBtn(btnPrev)
			enableBtn(btnLast)
	
		but nRowIndex >0 and nRowIndex = nNumber and
		nRowIndex < (nMax-nNumber)
			enableBtn(btnNext)
			enableBtn(btnFirst)
			enableBtn(btnPrev)
			enableBtn(btnLast)
	
		but nRowIndex >0 and nRowIndex = nNumber and
		nRowIndex > (nMax-nNumber)
			enableBtn(btnNext)
			enableBtn(btnFirst)
			enableBtn(btnPrev)
			enableBtn(btnLast)
	
		but nRowIndex >0 and nRowIndex > nNumber and
		nRowIndex < (nMax-nNumber) and nRowIndex < nMax
			enableBtn(btnNext)
			enableBtn(btnFirst)
			enableBtn(btnPrev)
			enableBtn(btnLast)
			
		but nRowIndex >0 and nRowIndex > nNumber and
		nRowIndex = (nMax-nNumber) and nRowIndex < nMax
			enableBtn(btnNext)
			enableBtn(btnFirst)
			enableBtn(btnPrev)
			enableBtn(btnLast)
			
		but nRowIndex >0 and nRowIndex > nNumber and
		nRowIndex > (nMax-nNumber) and nRowIndex < nMax
			enableBtn(btnNext)
			enableBtn(btnFirst)
			enableBtn(btnPrev)
			enableBtn(btnLast)
		else 
			if nRowIndex = nMax
				disableBtn(btnNext)
				enableBtn(btnFirst)
				enableBtn(btnPrev)
				disableBtn(btnLast)
			ok
		ok
	ok

func getCount

	nCL = getClCount()
	cChar = ""

	if nCl > 1 cChar = "s" ok
	if T_LANGUAGE = "ar" cChar = "" ok

	msg = aLANGUAGE[:TOTAL]+" ("+nCl+")"+
		aLANGUAGE[:CUSTOMER]+cChar
	lblCount{
		if isHidden() show() ok
		setText(msg)}

func getTableCount oTable

	nCL = oTable.rowcount()
	cChar = ""

	if nCl > 1 cChar = "s" ok
	if T_LANGUAGE = "ar" cChar = "" ok

	msg = aLANGUAGE[:TOTAL]+" ("+nCl+")"+
		aLANGUAGE[:CUSTOMER]+cChar
	lblCount{
		if isHidden() show() ok
		setText(msg)}

func enableBtns aBtns
	for x in aBtns
		enableBtn(x)
	next

func disableBtns aBtns
	for x in aBtns
		disableBtn(x)
	next

func disabled_txtedit

	leditRef{
		setstylesheet("color:rgba(0, 0, 255, 0.4);background-color:rgba(0, 0, 255, 0.3)")
		setenabled(0)}
	leditNom{
		setstylesheet("color:rgba(0, 0, 255, 0.4);background-color:rgba(0, 0, 255, 0.3)")
		setenabled(0)}
	leditEmail{
		setstylesheet("color:rgba(0, 0, 255, 0.4);background-color:rgba(0, 0, 255, 0.3)")
		setenabled(0)}
	txtAddress{
		setstylesheet("color:rgba(0, 0, 255, 0.4);background-color:rgba(0, 0, 255, 0.3)")
		setenabled(0)}
	btnSearch{
		if not isEnabled()  setenabled(1) ok
		setstylesheet(cssButton)
		setCursor(btnCursor)}

func enable_txtedit

	leditNom{
		oFont = new qfont("",0,0,0)
		oFont.fromstring(labelFont)
		setfont(oFont)
		oFont.delete()
		setStylesheet("color:#2b5392")
		if not isEnabled()  setenabled(1) ok }
	leditEmail{
		oFont = new qfont("",0,0,0)
		oFont.fromstring(labelFont)
		setfont(oFont)
		oFont.delete()
		setStylesheet("color:#2b5392")
		if not isEnabled()  setenabled(1) ok }
	txtAddress{
		oFont = new qfont("",0,0,0)
		oFont.fromstring(labelFont)
		setfont(oFont)
		oFont.delete()
		setStylesheet("color:#2b5392")
		if not isEnabled()  setenabled(1) ok }
	btnSearch{
		if isEnabled()  setenabled(0) ok
		setstylesheet(cssButton)
		setStylesheet("background-color:#aeaeae")
		setCursor(btnCursor)}

func disableFrom aBtns,aBtnsList

	for x=1 to len(aBtns)
		for x in aBtnsList
			x{

			if isEnabled()  setenabled(0) ok 
			setstylesheet(cssButton)
			setStylesheet("background-color:#aeaeae")
			setCursor(btnCursor)

			}
		next
		exit
	next

func enableFrom aBtns,aBtnsList
	
	for x=1 to len(aBtns)
		for x in aBtnsList
			x{

			if not isEnabled()  setEnabled(1) ok
			setstylesheet(cssButton)
			setCursor(btnCursor)

			} 
		next
		exit
	next
	
# Fill the inputs from the table, and check the current index
func get_data oTable

	oTable{
		nRowIndex = currentRow()
		cRef	  = item(nRowIndex, 0).text()
		cNom      = item(nRowIndex, 1).text()
		cEmail    = item(nRowIndex, 2).text()
		cAddress  = item(nRowIndex, 3).text()
		cImage    = item(nRowIndex, 4).text()
	}

	leditRef.setText(cRef)
	leditNom.setText(cNom) 
	leditEmail.setText(cEmail)
	txtAddress.setText(cAddress)

	if not isnull(cImage) and 
	fexists(substr(currentDir(),"\","/")+"/"+ cImage)
		set_image(lblImg, cImage)
		btnEditImage.setText(aLANGUAGE[:BTN_EDIT_TEXT])
	else 
		lblImg.clear()
		btnEditImage.setText(aLANGUAGE[:BTN_ADD_IMAGE_TEXT])
	ok

	disabled_txtedit()
	disableBtn(btnSave) disableBtn(btnCancel)
	enableBtn(btnDel)
	enableFrom(aActions,[btnAdd, btnEdit])
	btnSave.setText(aLANGUAGE[:BTN_SAVE_TEXT])
	lblCount.show()
	checkRowIndex(oTable)
	
# Will be called from the file main.ring. And it uses other functions
func fill_data oTable

	nRowIndex = 0

	oTable.clear()
	sqlite_fill_table(oTable,"SELECT * FROM clients ORDER BY clid ASC")
	
	get_data(oTable) getCount()
	enableBtns(aControls)

	btnSave{ 
		setText(aLANGUAGE[:BTN_SAVE_TEXT])
		disableBtn(self)}
	disableBtn(btnCancel)
	enableBtn(btnDel)
	enableBtn(btnSearch)
	txtSearch{
		setStylesheet("background-color:none;color:black")
		setText("")}
	disabled_txtedit()
	checkRowIndex(oTable)

	lblCount.show()
	
func show_input_box cText

	inBox = new qInputdialog(frmClients){
		setwindowtitle(aLANGUAGE[:SEARCH])
		setlabeltext(cText)
		settextvalue("CL_")
		playSound("sound/warning-beep-1.wav")
	}
	if inBox.exec() return inBox.textValue()
	else return null
	ok

func clearDatas

	leditRef.setText("")
	leditNom.setText("")
	leditEmail.setText("")
	txtAddress.setText("")
	lblImg.clear()
	txtSearch{
		setText("")
		setStylesheet("background-color:none;color:black")}
	btnEditImage.setText(aLANGUAGE[:BTN_ADD_IMAGE_TEXT])
	
func checkInput

	if leditNom.text() = ""
		msgBox(aLANGUAGE[:WARNING],aLANGUAGE[:NAME_IS_REQUIRED],"red")
		playSound("sound/warning-beep-1.wav")

		leditNom.setFocus(1)

		return 0

	but leditEmail.text() = ""
		msgBox(aLANGUAGE[:WARNING],aLANGUAGE[:EMAIL_IS_REQUIRED],"red")
		playSound("sound/warning-beep-1.wav")

		leditEmail.setFocus(1)

		return 0

	but txtAddress.toplainText() = ""
		msgBox(aLANGUAGE[:WARNING],aLANGUAGE[:ADDRESS_IS_REQUIRED],"red")
		playSound("sound/warning-beep-1.wav")

		txtAddress.setFocus(1)

		return 0

	else return 1
	ok

func newClient
	
	lEditMode = false
	lAdd      = true

	clearDatas()

	leditRef{
		setText("CL_"+sqlite_gener_id())
		setreadonly(1)}

	enable_txtedit()
	disableBtns(aControls)
	disableBtns(aActions)
	enableFrom(aActions,[btnSave, btnCancel, btnExit])
	
	btnSearch{
		setEnabled(0) 
		setStylesheet("background-color:#aeaeae")}

	leditNom.setfocus(1)
	lblCount.hide()

func cancel_action oTable

	lEditMode = false
	lAdd      = false

	get_data(oTable)

	lblCount.show()

func saveClient oTable

	cImage = oTable.item(nRowIndex, 4).text()
	
	if lEditMode=1
		if checkInput()
			cRef     = trim(leditRef.text())
			cNom     = trim(leditNom.text())
			cEmail   = trim(leditEmail.text())
			cAdresse = trim(txtAddress.toplaintext())

			cUpdate  = "UPDATE clients 
				 SET nom   ='"+cNom+"' ,
				 email     ='"+cEmail+"',
				 adresse   ='"+cAdresse+"',
				 avatar    =  '"+cImage+"' 
				 WHERE ref ='"+cRef+"'
			"

			if confirm(aLANGUAGE[:CONFIRMATION],aLANGUAGE[:SURE_TO_MODIFI_CUST]+cNom,"red")
				cName   = leditNom.text()
				nCrRow	= oTable.currentRow()
				sqlite_run(cUpdate)
				fill_data(oTable)
				oTable.setCurrentCell(nCrRow, 0)
				msgBox(aLANGUAGE[:INFOS],aLANGUAGE[:CUST]+cName+aLANGUAGE[:WAS_MODIFIED],"green")

				return 1

			else return 0
			ok
		ok
	else 
		if lAdd=1
			if checkInput()
				nId      = sqlite_gener_id()
				cRef     = trim(leditRef.text())
				cNom     = trim(leditNom.text())
				cEmail   = trim(leditEmail.text())
				cAdresse = trim(txtAddress.toplaintext())
		
				if confirm(aLANGUAGE[:CONFIRMATION],aLANGUAGE[:SURE_TO_ADD_CUST]+cNom+"?","red")
				
					cStmt = "
						INSERT INTO clients (ref,nom,email,adresse,avatar,clid) 
							VALUES ('"+cRef+"','"+cNom+"','"+cEmail+"','"+cAdresse+"','"+cImage+"','"+nId+"')
					"
					sqlite_run(cStmt)
					clearDatas()
					fill_data(oTable)
					oTable.setCurrentCell(oTable.rowCount()-1, 0)
					msgBox(aLANGUAGE[:INFOS],aLANGUAGE[:RECORD_ADDED],"green")

					return 1

				else return 0
				ok
			ok
		ok
	ok

func editCl

	lEditMode = true
	lAdd      = false

	enable_txtedit()
	disableBtns(aControls)
	enableBtns(aActions)
	disableFrom(aActions, [btnAdd, btnEdit, btnDel])

	btnSave.setText(aLANGUAGE[:CONFIRM])

func delClient oTable

	cRef  = trim(leditRef.text())

	if cRef != ""
		if confirm(aLANGUAGE[:CONFIRMATION],aLANGUAGE[:SURE_TO_DELETE_CUST]+cRef,"red")
			sqlite_run("DELETE FROM clients WHERE ref='"+cRef+"'")
			remove("images/avatars/" + cRef + ".jpg")
			fill_data(oTable)
			msgBox(aLANGUAGE[:INFOS],aLANGUAGE[:DELETE_DONE],"green")
		ok
	else
		msgBox(aLANGUAGE[:WARNING],aLANGUAGE[:REF_NOT_FOUND],"red")
		playSound("sound/warning-beep-1.wav") 
	ok

func editImage oTable

	nIndex 	    = oTable.currentRow()
	cRef        = trim(leditRef.text())
	cBtnText    = btnEditImage.text()

	if cRef = ""
		msgBox(aLANGUAGE[:WARNING],aLANGUAGE[:REF_IS_REQUIRED],"red")
		playSound("sound/warning-beep-1.wav") 
		return 
	ok
	
	if dirExists("images/avatars") = 0 
		System('mkdir' + " " + "images\avatars") ok

	new qfiledialog(frmClients){
		chosen_avatar = getopenfilename(frmClients,aLANGUAGE[:OPEN_FILE],"",aLANGUAGE[:IMAGE_FILE]+"(*.jpg;*.png);;"+aLANGUAGE[:ALL_FILE]+"(*.*)")
	}
	if chosen_avatar != ""
		if confirm(aLANGUAGE[:WARNING],aLANGUAGE[:WANT_ADD_AVATAR],"red")
	
			new_avatar = currentDir()+'/images/avatars/'+cRef+'.jpg'
	
			if isWindows()
				new_avatar = substr(new_avatar, "/", "\")
				chosen_avatar = substr(chosen_avatar, "/", "\")
			ok

			if fexists(new_avatar) remove(new_avatar) ok
	
			system('copy ' + chosen_avatar + " " + new_avatar)
					
			new_avatar = "images/avatars/"+cRef+".jpg"
					
			cUpdate    = "
				UPDATE clients 
				SET avatar=  '"+new_avatar+"' 
				WHERE ref ='"+cRef+"'
			"
	
			sqlite_execute(oSQLite, cUpdate)
			fill_data(oTable)
			set_image(lblImg, new_avatar)
			oTable.setCurrentCell(nIndex, 0)
			msgBox(aLANGUAGE[:INFOS],aLANGUAGE[:AVATAR_HAS_BEEN_MODIFIED],"green")

			return 1

		else return 0

		ok

	else return 0

	ok

func getNext oTable
	nRowIndex += 1
	oTable.setCurrentCell(nRowIndex, 0)
	
func getPrev oTable
	nRowIndex -= 1
	oTable.setCurrentCell(nRowIndex, 0)
	
func getLast oTable
	oTable.setCurrentCell((oTable.rowCount())-1, 0)

func getFirst oTable
	oTable.setCurrentCell(0, 0)
