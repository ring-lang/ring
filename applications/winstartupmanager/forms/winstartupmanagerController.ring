# Form/Window Controller - Source Code File

load "winstartupmanagerView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		open_window(:winstartupmanagerController)
		exec()
	}
}

class winstartupmanagerController from windowsControllerParent

	oView = new winstartupmanagerView
	setWinIcon(oView.win,"imgs/icon.png")

Func LoadWinAction
	oView.TableWidget1 {
		setSelectionMode(QAbstractItemView_SingleSelection)
		setcurrentcell(1,1)
		setEditTriggers(QAbstractItemView_NoEditTriggers)
	}


Func AddProgAction
	if not SubWinOpened
		Open_window( :addeditentryController )
		SubWinObj = Last_Window() {
			SetParentObject(WinObj)
		
			PrepareWin("Add Program", "", "", "", HKCU, True)

			oView.win.Show()
		}
		SubWinOpened = 1
	ok
	oView.TableWidget1.setfocus(0)

Func retAddProg retSubWinObj
	retSubWinObj {
		lproPath = '"' + ProPath + '"'
		newItem = [len(ProgramItems) +1, ProName, lproPath, 1, AllUsers, False]
		# Add to ProgramItems
		Add(ProgramItems, newItem)
		# Add to Registry
		EnableProgram(len(ProgramItems))
		# Add to table 
		This.AddItemsToTable([newItem])
	}

Func EditProgAction
	oView {
		curID = Number(TableWidget1.item(TableWidget1.currentrow(), 4).text())
	/*	stat = 0
		cCode = 'stat = CB@ID.Checkstate()'
		cCode = substr(cCode, "@ID", String(curID))
		eval(cCode)
		if not stat
			new qMessageBox(oView.win) {
					warning(self, "Warning", "Cannot edit deactivated program", QMessageBox_Ok, QMessageBox_NoButton)
					}
			Return
		ok	*/
	}

	lappName = ProgramItems[Find(ProgramItems, curID, 1)][2]
	lappPath = ProgramItems[Find(ProgramItems, curID, 1)][3]
	if len(lappPath) and lappPath[1] = '"'
		lappPath = right(lappPath, len(lappPath) -1)
		lappPath = left(lappPath, substr(lappPath, '"') -1) + right(lappPath, len(lappPath) - substr(lappPath, '"') -1)
	ok
	lpath = trim(left(lappPath, substr(Lower(lappPath), ".exe") +3))
	largs = trim(right(lappPath, len(lappPath) - substr(Lower(lappPath), ".exe") -3))
	if not SubWinOpened
		Open_window( :addeditentryController )
		SubWinObj = Last_Window() {
			SetParentObject(WinObj)
			
			PrepareWin("Edit Program", lappName, lpath, largs, ProgramItems[Find(Programitems, curID,1)][5], ProgramItems[Find(Programitems, curID,1)][4])
			curPID = curID
			oView.win.Show()
		}
		SubWinOpened = 1
	ok
	oView.TableWidget1.setfocus(0)

Func retEditProg retSubWinObj, pID
	rwID = 0
	rwCount = oView.TableWidget1.rowcount()
	if rwCount
		for i = 1 to rwCount
			if Number(oView.TableWidget1.item(i, 4).text()) = pID
				rwID = i
				exit
			ok
		next
	ok
	retSubWinObj {
		This.oView.TableWidget1.setItem(rwID, 1, New TableWidgetItem(ProName))
		lproPath = '"' + ProPath + '"'
		This.oView.TableWidget1.setItem(rwID, 2, New TableWidgetItem(trim(lproPath + " " + ProArgs)))
		# Update ProgramItems and Registry
		EditProgram(pID, ProName, trim(lproPath + " " + ProArgs), AllUsers)
		if AllUsers = HKLM 
			This.oView.TableWidget1.setItem(rwID, 3, New TableWidgetItem("Yes"))
		else
			This.oView.TableWidget1.setItem(rwID, 3, New TableWidgetItem("No"))
		ok
		This.oView.TableWidget1.item(rwID,3).setTextAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
		This.RowClickAction()
	}

Func AddItemsToTable ItemsList
	oView{
		For i = 1 to Len(ItemsList)
			if ItemsList[i][1] = 0
				loop # to ignore deleted items
			ok
			Ind = TableWidget1.RowCount() + 1
			TableWidget1.InsertRow(Ind)
			TableWidget1.setItem(Ind, 1, New TableWidgetItem(ItemsList[i][2]))
			TableWidget1.setItem(Ind, 2, New TableWidgetItem(ItemsList[i][3]))
			if ItemsList[i][5] = HKLM
				TableWidget1.setItem(Ind, 3, New TableWidgetItem("Yes"))
			else
				TableWidget1.setItem(Ind, 3, New TableWidgetItem("No"))
			ok
			TableWidget1.item(Ind,3).setTextAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
			TableWidget1.setItem(Ind, 4, New TableWidgetItem(String(ItemsList[i][1])))
			TableWidget1.item(Ind,4).setTextAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
			TableWidget1.setcellWidget(Ind, 4, This.newCheckBox(ItemsList[i][1], ItemsList[i][4]))
		Next
		TableWidget1.setcurrentcell(TableWidget1.RowCount(),2)
	}

Func newCheckBox nID, status 
	roWidget = NULL
	oView {
		sCode = '	AddAttribute(Self, "CB#nID") 
				CB#nID = new checkbox(win) { 
				move(0,0) 
				resize(15,24) 
				setstylesheet("color:black;background-color:;") 
				oFont = new qfont("",0,0,0) 
				setfont(oFont) 
				setText("") 
				setCheckState(#status) 
				setstateChangedEvent(Method("CheckBoxClicked(#nID)")) 
				} 
				oWidget#nID = new QWidget() 
				oLayout#nID = new QHBoxLayout() 
				oLayout#nID.addWidget(CB#nID) 
				oLayout#nID.setAlignment_2(Qt_AlignHCenter | Qt_AlignVCenter) 
				oLayout#nID.setContentsMargins(0,0,0,0) 
				oWidget#nID.setLayout(oLayout#nID) 

				roWidget = oWidget#nID 
				'
		sCode = SubStr(sCode, "#nID", String(nID))
		If status
			status = 2		# 1 is semi check
		Ok
		sCode = SubStr(sCode, "#status", String(status))
		eval(sCode)

	}

	Return roWidget

Func CheckBoxClicked nID
	status = NULL
	sCode = "status = oView.CB" + nID + ".checkState()"
	eval(sCode)
	If status
		If not EnableProgram(nID)
			DisableProgram(nID)
			sCode = "oView.CB" + nID + ".setCheckState(False)"
			eval(sCode)
		Ok
	else
		If not DisableProgram(nID)
			EnableProgram(nID)
			sCode = "oView.CB" + nID + ".setCheckState(True)"
			eval(sCode)
		Ok
	Ok
	oView.TableWidget1.setfocus(0)

Func DoubleClickAction
	See nl + "Row No. (" + oView.Tablewidget1.currentRow() + ") was double Clicked" + nl

Func DeleteAction
	new qMessageBox(oView.win) {
				res = Warning(self, "Delete program", "Do you want to delete this program's entry?", QMessageBox_Yes, QMessageBox_No)
	}
	if res = QMessageBox_Yes
		oView.TableWidget1 {
			DeleteProgram(Number(item(currentrow(), 4).text()))
			removeRow(currentRow())
		}
		new qMessageBox(oView.win) {
				information(self, "Delete program", "This program's entry deleted successfully", QMessageBox_OK, QMessageBox_NoButton)
		}
	ok
	oView.TableWidget1.setfocus(0)

Func CloseAction
	oView.win.Close()

Func RowClickAction # used with row index changing
	if oView.TableWidget1.RowCount() > 1
		itmInd = Find(ProgramItems, Number(oView.TableWidget1.item(oView.TableWidget1.CurrentRow(), 4).text()), 1)
		Switch ProgramItems[itmInd][5]
			on HKEY_CURRENT_USER
				path = "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Run\" + ProgramItems[itmInd][2]
			on HKEY_LOCAL_MACHINE
				if ProgramItems[itmInd][6]
					path = "HKEY_LOCAL_MACHINE\Software\WOW6432Node\Microsoft\Windows\CurrentVersion\Run\" + ProgramItems[itmInd][2]
				else
					path = "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Run\" + ProgramItems[itmInd][2]
				ok
		Off
		oView.RegPathLE.SetText(path)
	ok

Func SortLstAction
	for i = oView.TableWidget1.rowCount() to 1 step -1
		oView.TableWidget1.removeRow(i)
	next
	Switch oView.SortCmB.currentIndex()
		on 1
			SortProItems(2) # 2 is program name in ProgramItems list
		on 2
			SortProItems(3) # 3 is program path in ProgramItems list
		on 3
			SortProItems(5) # 5 is program user specific in ProgramItems list
	Off
	AddItemsToTable(ProgramItems)
	oView.TableWidget1.setcurrentcell(1,2)
	oView.TableWidget1.setfocus(0)

Func ShortcutsAction
	if rwaIsWow64Process() = 1
		rWow64EnableWow64FsRedirection(False)
	ok

	if substr(SysCmd("ver"), "5.")
		# Win XP
		efpath = rwaEnvirVarString("%SystemDrive%") + "\Documents and Settings\" + rwaEnvirVarString("%UserName%") + "\Start Menu\Programs\StartUp"
		if DirExists(efpath)
		rShellExecute(NULL, "Open", efpath, NULL, NULL, SW_SHOWNORMAL)
		ok
	else
		# Win Vista, 7, 8 and 10
		efpath = rwaEnvirVarString("%SystemDrive%") + "\Users\" + rwaEnvirVarString("%UserName%") + "\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup"
		if DirExists(efpath)
			rShellExecute(NULL, "Open", efpath, NULL, NULL, SW_SHOWNORMAL)
		ok
		efpath = rwaEnvirVarString("%SystemDrive%") + "\ProgramData\Microsoft\Windows\Start Menu\Programs\StartUp"
		if DirExists(efpath)
			rShellExecute(NULL, "Open", efpath, NULL, NULL, SW_SHOWNORMAL)
		ok
	ok

	if rwaIsWow64Process() = 1
		rWow64EnableWow64FsRedirection(True)
	ok

	oView.TableWidget1.setfocus(0)

Func ExportAction
	ExportEntries()
	oView.TableWidget1.setfocus(0)

Func ImportAction
	if len(ProgramItems)
		new qMessageBox(oView.win) {
				res = Warning(self, "Import backup", "You are about to import a backup." + nl + "Do you want to delete previously present entries?", QMessageBox_Yes, QMessageBox_No)
		}
		if res = QMessageBox_Yes
			# empty table
			EmptyTable()
			# delete current entries from registry
			for itm in ProgramItems
				DeleteProgram(itm[1])
			next
			# empty ProgramItems list
			ProgramItems = []
			ID = 1
		ok
	ok
	# Retrieve entries
	retList = ImportEntries()
	if isList(retList) and len(retList)
		for pi in retList	/*To equalize retrieved paths with ProgramsList paths*/
			if len(pi[3]) and trim(pi[3])[1] != '"'
				pi[3] = '"' + left(pi[3], substr(Lower(pi[3]), ".exe") + 3) + '"' + right(pi[3], len(pi[3]) - substr(Lower(pi[3]), ".exe") -3)
			ok
		next
	ok
	if not isList(retList)
		oView.TableWidget1.setfocus(0)
		return
	ok
	for itm in retList
		for c = 1 to len(programItems)
			if ProgramItems[c][2] = itm[2] and ProgramItems[c][3] = itm[3] and ProgramItems[c][5] = itm[5] and ProgramItems[c][6] = itm[6]
				if itm[1] = 0 loop ok
				itm = [0, "", "", 0, 0, 0]
			ok
		next
	next
	for itm  in retList
		if itm[1] = 0 loop ok
		add(ProgramItems, itm)
		# save item to registry
		SaveItmToReg(itm[1])
	next

	# empty table and add them to the table
	EmptyTable()
	SortProItems(2)
	AddItemsToTable(ProgramItems)

	oView.TableWidget1.setfocus(0)

Func AboutAction
	msg = 'App Name : Win Startup Manager
Author : Majdi Sobain <Majdi.Sobain@Gmail.com>

Developed by Ring Programming Language using:
     1- RingQt extension
     2- Ring_WinCReg extension 
         <By: Majdi Sobain - At: http://ring-wincreg.sf.net/>
     3- Ring_WINAPI extension 
         <By: Majdi Sobain - At: http://Github.com/MajdiSobain/ring-winapi>
'
	new qMessageBox(oView.win) {
				Information(self, "About", msg, QMessageBox_OK , QMessageBox_NoButton)
				}


Func SortProItems col 
	ProgramItems = Sort(ProgramItems, col)

Func EmptyTable
	oView.TableWidget1 {
		if RowCount()
			for i = RowCount() to 1 step -1
				RemoveRow(i)
			next
		ok
	}
