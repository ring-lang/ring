# Form/Window Controller - Source Code File

load "addeditentryView.ring"

import System.GUI

if IsMainSourceFile() {
	new App {
		StyleFusion()
		open_window(:addeditentryController)
		exec()
	}
}

class addeditentryController from windowsControllerParent

	oView = new addeditentryView
	Self.ProName = ""
	Self.ProPath = ""
	Self.ProArgs = ""
	Self.AllUsers = 0
	Self.curPID = 0

Func PrepareWin wintitle, name, path, args, ausers, ProActiv
	ProName = name
	ProPath = path
	ProArgs = args
	AllUsers = ausers
	oView {
		setWinIcon(win,"imgs/icon.png")
		win.SetWindowTitle(wintitle)
		NameLE.SetText(This.ProName)
		PathLE.SetText(This.ProPath)
		ArgsLE.SetText(This.ProArgs)
		if ausers = 3 # HKLM
			UsersCB.SetcheckState(2)
		else
			UsersCB.SetcheckState(0)
		ok
		if ProActiv 
			UsersCB.SetEnabled(1)
		else
			UsersCB.SetEnabled(0)
		ok
	}

Func OkAction
	if oView.NameLE.Text() = "" or substr(oView.NameLE.Text(), "\")
		new qMessageBox(oView.win) {
				qmb = Warning(self, "Invalid program name", "This program's entry cannot be added\edited because the name is empty or contains \ character" + nl + "Do you want to discard changes?", QMessageBox_Yes , QMessageBox_No)
				}
		if qmb = qMessageBox_Yes
			oView.win.Close()
			SubWinObj = NULL
			SubWinOpened = 0
			return
		else
			return
		ok		
	ok
	for itm in ProgramItems
		if itm[1] = curPID loop ok # avoid checking the already edited item
		if lower(oView.NameLE.Text()) = lower(itm[2])
			if oView.UsersCB.checkState()
				usr = 3
			else
				usr = 2
			ok
			if usr = itm[5]
				new qMessageBox(oView.win) {
					qmb = Warning(self, "Similar program", "This program's entry cannot be added\edited because there's similar program entry already present" + nl + "Do you want to discard changes?", QMessageBox_Yes , QMessageBox_No)
					}
				if qmb = qMessageBox_Yes
					oView.win.Close()
					SubWinObj = NULL
					SubWinOpened = 0
					return
				else
					return
				ok	
			ok
		ok
	next
	lapath = oView.PathLE.Text()
	if rwaIsWow64Process() = 1
		rWow64EnableWow64FsRedirection(False)
		lapath = substr(lapath, "%ProgramFiles%", "%ProgramW6432%")
		lapath = substr(lapath, "%CommonProgramFiles%", "%CommonProgramW6432%")
	ok
	if not fExists(trim(rwaEnvirVarString(lapath))) 
		new qMessageBox(oView.win) {
				qmb = Warning(self, "Not Complete", "This program's entry cannot be added\edited because the path is incorrect" + nl + "Do you want to discard changes?", QMessageBox_Yes , QMessageBox_No)
				}
		if qmb = qMessageBox_Yes
			oView.win.Close()
			SubWinObj = NULL
			SubWinOpened = 0
			return
		else
			return
		ok		
	ok
	if rwaIsWow64Process() = 1
		rWow64EnableWow64FsRedirection(True)
	ok
	ProName = oView.NameLE.Text()
	ProPath = oView.PathLE.Text()
	ProArgs = oView.ArgsLE.Text()
	if oView.UsersCB.checkState()
		AllUsers = 3 # HKLM
	else
		AllUsers = 2 # HKCU
	ok
	oView.win.Close()
	SubWinObj = NULL
	SubWinOpened = 0
	# if Wow64
	CallParentAddEdit(lapath)

Func CallParentAddEdit lppath
	if rwaIsWow64Process() = 1
		rWow64EnableWow64FsRedirection(False)
		lppath = substr(lppath, "%ProgramFiles%", "%ProgramW6432%")
		lppath = substr(lppath, "%CommonProgramFiles%", "%CommonProgramW6432%")
	ok
	if fExists(trim(rwaEnvirVarString(lppath))) 
		if left(oView.win.Windowtitle(), 4) = "Edit"
			WinObj.retEditProg(Self, curPID)
		else
			WinObj.retAddProg(Self)
		ok
	ok
	if rwaIsWow64Process() = 1
		rWow64EnableWow64FsRedirection(True)
	ok

Func CancelAction
	ProPath = ""	# used if in the check if this window canceled
	oView.win.Close()
	SubWinObj = NULL
	SubWinOpened = 0
	
Func PathLEChangedAction
	ProPath = oView.PathLE.Text()

Func BrowseAction
	laPath = This.oView.PathLE.Text()
	new qFileDialog(NULL) {
		if rwaIsWow64Process() = 1
			rWow64EnableWow64FsRedirection(False)
			lapath = substr(lapath, "%ProgramFiles%", "%ProgramW6432%")
			lapath = substr(lapath, "%CommonProgramFiles%", "%CommonProgramW6432%")
		ok
		if fExists(rwaEnvirVarString(lapath))
			cName = getopenfilename(NULL, "Select Program File",JustFilePath(rwaEnvirVarString(lapath)),"executable files(*.exe)")
		else
			cName = getopenfilename(NULL, "Select Program File","c:\","executable files(*.exe)")
		ok
		if rwaIsWow64Process() = 1
			rWow64EnableWow64FsRedirection(True)
		ok
		cName = substr(cName, "/", "\")
		if fExists(cName)
			This.oView.PathLE.SetText(cName)
		ok
	}

