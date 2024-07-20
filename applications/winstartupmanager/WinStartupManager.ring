/*
App Name	: Win Startup Manager
Description	: This application let you control Windows startup programs entries by Adding, Editing, or Deleting them
Author 	: Majdi Sobain <Majdi.Sobain@Gmail.com>

			(c) 2017
*/


Load "guilib.ring"
Load "stdlibcore.ring"

# Load Libraries
Load "WinCReg.ring"
Load "WINAPI.ring"

# Load windows
Load "forms\winstartupmanagerController.ring"
Load "forms\addeditentryController.ring"

import System.GUI

If rwaIsRunAsAdmin() = False
	rwaElevate(exefolder() + "ringw.exe", filename())	
	Bye
Ok

# Public variables
ID = 1
WinObj = NULL
SubWinObj = NULL
SubWinOpened = 0
ProgramItems = NULL


Func Main

	ProgramItems = RetrieveAppEntries() 
	# ProgramItems = [ [ID, ProgramName, ProgramPath, Activation, HKEY, Wow64tree] ]

	new App {
		StyleFusion()
		openWindow(:winstartupmanagerController)
		WinObj = Last_Window() {

		SortProItems(2)
		AddItemsToTable(ProgramItems)

		LoadWinAction()
		}
		exec()
	}

Func RetrieveAppEntries
	ProgramItems = [/* [ID, ProgramName, ProgramPath, Activation, HKEY, Wow64tree] */]
	New RCRegistry { 
		Try
			OpenKey([HKEY_CURRENT_USER, "Software\Microsoft\Windows\CurrentVersion\Run", CREG_READONLY])
			rItems = GetEntries()
			If len(rItems)
				For i = 1 to len(rItems)
					If rItems[i] = "" Loop /*Ignore Default entry*/ Ok
					Add(ProgramItems, [ID, rItems[i], Self[rItems[i]].GetValue(), 1, HKCU, False])
					ID++
				Next
			Ok
		Catch see ccatcherror Done
		Try
			OpenKey([HKEY_Local_Machine, "Software\Microsoft\Windows\CurrentVersion\Run", CREG_READONLY])
			rItems = GetEntries()
			If len(rItems)
				For i = 1 to len(rItems)
					If rItems[i] = "" Loop /*Ignore Default entry*/ Ok
					Add(ProgramItems, [ID, rItems[i], Self[rItems[i]].GetValue(), 1, HKLM, False])
					ID++
				Next
			Ok
		Catch see ccatcherror Done
		Try
			if rwaIsWow64Process() = 1
				OpenKey([HKEY_Local_Machine, "Software\Microsoft\Windows\CurrentVersion\Run", CREG_READONLY, True])
				rItems = GetEntries()
				If len(rItems)
					For i = 1 to len(rItems)
						If rItems[i] = "" Loop /*Ignore Default entry*/ Ok
						Add(ProgramItems, [ID, rItems[i], Self[rItems[i]].GetValue(), 1, HKLM, True])
						ID++
					Next
				Ok
			Ok
		Catch Done
		Try
			OpenKey([HKEY_Current_User, "Software\WinStartupManager\Disabled\" + HKCU + "\" + False])
			rItems = GetEntries()
			If len(rItems)
				For i = 1 to len(rItems)
					If rItems[i] = "" Loop /*Ignore Default entry*/ Ok
					Add(ProgramItems, [ID, rItems[i], Self[rItems[i]].GetValue(), 0, HKCU, False])
					ID++
				Next
			Ok
		Catch see ccatcherror Done
		Try
			OpenKey([HKEY_Current_User, "Software\WinStartupManager\Disabled\" + HKLM + "\" + False])
			rItems = GetEntries()
			If len(rItems)
				For i = 1 to len(rItems)
					If rItems[i] = "" Loop /*Ignore Default entry*/ Ok
					Add(ProgramItems, [ID, rItems[i], Self[rItems[i]].GetValue(), 0, HKLM, False])
					ID++
				Next
			Ok
		Catch see ccatcherror Done
		Try
			OpenKey([HKEY_Current_User, "Software\WinStartupManager\Disabled\" + HKLM + "\" + True])
			rItems = GetEntries()
			If len(rItems)
				For i = 1 to len(rItems)
					If rItems[i] = "" Loop /*Ignore Default entry*/ Ok
					Add(ProgramItems, [ID, rItems[i], Self[rItems[i]].GetValue(), 0, HKLM, True])
					ID++
				Next
			Ok
		Catch see ccatcherror Done
		CloseKey()
	}
	for pi in ProgramItems
		if len(pi[3]) and trim(pi[3])[1] != '"'
			pi[3] = '"' + left(pi[3], substr(Lower(pi[3]), ".exe") + 3) + '"' + right(pi[3], len(pi[3]) - substr(Lower(pi[3]), ".exe") -3)
		ok
	next
	Return ProgramItems

Func DisableProgram ID
	ItemInd = Find(ProgramItems, ID, 1)
	New RCRegistry {
		Try
			# Delete program entry from "Run" key
			OpenKey([ProgramItems[ItemInd][5], "Software\Microsoft\Windows\CurrentVersion\Run", CREG_CREATE, ProgramItems[ItemInd][6]])
			Self[ProgramItems[ItemInd][2]].Delete()
			# Create program entry in "Disabled" key
			OpenKey([HKEY_Current_User, "Software\WinStartupManager\Disabled\" + String(ProgramItems[ItemInd][5]) + "\" + String(ProgramItems[ItemInd][6])])
			Self[ProgramItems[ItemInd][2]].SetValue(ProgramItems[ItemInd][3])
			# Change activation status
			ProgramItems[ItemInd][4] = 0
		Catch
			#MsgBox
			new qMessageBox(WinObj.oView.win) {
				Warning(self, "Error", cCatchError, QMessageBox_Ok, QMessageBox_NoButton)
				}
			CloseKey()
			Return False
		Done
		CloseKey()
	}
	Return True

Func EnableProgram ID
	ItemInd = Find(ProgramItems, ID, 1)
	New RCRegistry {
		Try
			# Delete program entry from "Disabled" key
			OpenKey([HKEY_Current_User, "Software\WinStartupManager\Disabled\" + String(ProgramItems[ItemInd][5]) + "\" + String(ProgramItems[ItemInd][6])])
			Self[ProgramItems[ItemInd][2]].Delete()
			# Create program entry in "Run" key
			OpenKey([ProgramItems[ItemInd][5], "Software\Microsoft\Windows\CurrentVersion\Run", CREG_CREATE, ProgramItems[ItemInd][6]])
			Self[ProgramItems[ItemInd][2]].SetValue(ProgramItems[ItemInd][3])
			# Change activation status
			ProgramItems[ItemInd][4] = 1
		Catch
			#MsgBox
			new qMessageBox(WinObj.oView.win) {
				Warning(self, "Error", cCatchError, QMessageBox_Ok, QMessageBox_NoButton)
				}
			CloseKey()
			Return False
		Done
		CloseKey()
	}
	Return True

Func EditProgram ID, aname, apath, ausers
	ItemInd = Find(ProgramItems, ID, 1)
	if ProgramItems[ItemInd][5] = ausers 
		# Update item in ProgramItems AND Registry
		New RCRegistry {
			Try
				# Edit program entry in "Run" key or "Disabled" key
				if ProgramItems[ItemInd][4]
					OpenKey([ProgramItems[ItemInd][5], "Software\Microsoft\Windows\CurrentVersion\Run", CREG_READONLY, ProgramItems[ItemInd][6]])
				else
					OpenKey([HKEY_Current_User, "Software\WinStartupManager\Disabled\" + String(ProgramItems[ItemInd][5]) + "\" + String(ProgramItems[ItemInd][6])])
				ok
				if ProgramItems[ItemInd][2] != aname
					Self[ProgramItems[ItemInd][2]].Delete()
				ok
				# Update item in ProgramItems
				ProgramItems[ItemInd][2] = aname
				ProgramItems[ItemInd][3] = apath
				# Update item in Registry
				Self[ProgramItems[ItemInd][2]].SetValue(ProgramItems[ItemInd][3])
			Catch
				#MsgBox
				new qMessageBox(WinObj.oView.win) {
					Warning(self, "Error", cCatchError, QMessageBox_Ok, QMessageBox_NoButton)
					}
					CloseKey()
				Return False
			Done
			CloseKey()
		}
	else		# if the place of entry save changed		Note: if program deactivate place will not change
		# Delete previous entry
		New RCRegistry {
			Try
				# Edit program entry in "Run" key
				OpenKey([ProgramItems[ItemInd][5], "Software\Microsoft\Windows\CurrentVersion\Run", CREG_READONLY, ProgramItems[ItemInd][6]])
				Self[ProgramItems[ItemInd][2]].Delete()
			Catch
				#MsgBox
				new qMessageBox(WinObj.oView.win) {
					Warning(self, "Error", cCatchError, QMessageBox_Ok, QMessageBox_NoButton)
					}
					CloseKey()
				Return False
			Done
			CloseKey()
		}

		if ProgramItems[ItemInd][5] = HKCU
			New RCRegistry {
				OpenKey([HKEY_Current_User, "Software\WinStartupManager\UserConversion"])
				if Self[ProgramItems[ItemInd][2]].Exists()
					if Self[ProgramItems[ItemInd][2]].GetValue() = 1
						Self[ProgramItems[ItemInd][2]].Delete()
						ProgramItems[ItemInd][6] = 1
					ok
				ok
			}
		else
			if ProgramItems[ItemInd][6]
				New RCRegistry {
					OpenKey([HKEY_Current_User, "Software\WinStartupManager\UserConversion"])
					Self[ProgramItems[ItemInd][2]].SetValue(1)
				}
			ok
		ok

		# Update item in ProgramItems
		ProgramItems[ItemInd][2] = aname
		ProgramItems[ItemInd][3] = apath
		ProgramItems[ItemInd][5] = ausers 
		# Create new entry
		New RCRegistry {
			Try
				# Edit program entry in "Run" key
				OpenKey([ProgramItems[ItemInd][5], "Software\Microsoft\Windows\CurrentVersion\Run", CREG_CREATE, ProgramItems[ItemInd][6]])
				Self[ProgramItems[ItemInd][2]].SetValue(ProgramItems[ItemInd][3])
			Catch
				#MsgBox
				new qMessageBox(WinObj.oView.win) {
					Warning(self, "Error", cCatchError, QMessageBox_Ok, QMessageBox_NoButton)
					}
					CloseKey()
				Return False
			Done
			CloseKey()
		}
	ok
	Return True
	
Func ExportEntries
	outPut = "Windows Registry Editor Version 5.00" + NL + NL
	for i = 1 to len(ProgramItems)
		if not ProgramItems[i][4] # disabled
				outPut = outPut + "[HKEY_CURRENT_USER\Software\WinStartupManager\Disabled\" + String(ProgramItems[i][5]) + "\" + String(ProgramItems[i][6]) + "]" + NL
				outPut = outPut + '"' + PrepareToExport(ProgramItems[i][2]) + '"="' + PrepareToExport(ProgramItems[i][3]) + '"' + NL + NL
		else
			if ProgramItems[i][5] = HKCU
				outPut = outPut + "[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Run]" + NL
				outPut = outPut + '"' + PrepareToExport(ProgramItems[i][2]) + '"="' + PrepareToExport(ProgramItems[i][3]) + '"' + NL + NL
			else
				if ProgramItems[i][6]
					outPut = outPut + "[HKEY_LOCAL_MACHINE\Software\WOW6432Node\Microsoft\Windows\CurrentVersion\Run]" + NL
					outPut = outPut + '"' + PrepareToExport(ProgramItems[i][2]) + '"="' + PrepareToExport(ProgramItems[i][3]) + '"' + NL + NL
				else
					outPut = outPut + "[HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Run]" + NL
					outPut = outPut + '"' + PrepareToExport(ProgramItems[i][2]) + '"="' + PrepareToExport(ProgramItems[i][3]) + '"' + NL + NL
				ok
			ok
		ok
	next
	cName = ""
	new qFileDialog(NULL) {
		cName = getsavefilename(NULL, "Save to file","c:\","Registry files(*.reg)")
	}
	if cName = ""
		return
	ok
	Write(cName, outPut)
	new qMessageBox(WinObj.oView.win) {
				information(self, "Completed Successfully", "Export process completed successfully", QMessageBox_Ok, QMessageBox_NoButton)
	}

Func PrepareToExport str
	str = substr(substr(str, "\", "\\"), '"', '\"')
	Return str

Func ImportEntries
	itemsList = []
	iID = ID
	new qFileDialog(NULL) {
		cName = ""
		cName = getopenfilename(NULL, "Open file","c:\","Registry files(*.reg)")
	}
	if cName = ""
		return 0
	ok
	inPutLst = Read(cName)
	if not substr(inPutLst, "\Run]") AND not substr(inPutLst, "WinStartupManager")
		new qMessageBox(WinObj.oView.win) {
					Warning(self, "Invalid Backup", "You have selected an invalid backup.", QMessageBox_OK, QMessageBox_NoButton)
			}
		return 0
	ok
	inPutLst = str2list(inPutLst)
	for i = 1 to len(inPutLst)
		if len(inPutLst[i]) = 0
			loop
		ok
		if inPutLst[i][1] = "["
			iName = substr(inPutLst[i+1], 2, substr(inPutLst[i+1], "=") -3)
			iName = substr(iName, '\"', '"')
			iPath = substr(inPutLst[i+1], substr(inPutLst[i+1], "=") +2, len(inPutLst[i+1]) - substr(inPutLst[i+1], "=") -2)
			iPath = substr(substr(iPath, '\"', '"'), '\\', "\")
			if substr(inPutLst[i], "WinStartupManager")
				activ = 0
				if substr(inPutLst[i], "2")
					hKey = 2
				else
					hKey = 3
				ok
				if substr(inPutLst[i], "1")
					Redi = 1
				else
					Redi = 0
				ok
			else
				activ = 1
				if substr(inPutLst[i], 2, substr(inPutLst[i], "\") -2) = "HKEY_CURRENT_USER"
					hKey = 2
				else
					hKey = 3
				ok
				if substr(inPutLst[i], "WOW6432Node")
					Redi = 1
				else
					Redi = 0
				ok
			ok

			add(itemsList, [iID, iName, iPath, activ, hKey, Redi])
			iID = iID + 1
			i = i + 2
		ok
	next
	ID = iID
	Return itemsList

Func SaveItmToReg itID 
	ind = find(ProgramItems, itID, 1)
	if ProgramItems[ind][4] # active 
		EnableProgram(itID)
	else
		DisableProgram(itID)
	ok

Func DeleteProgram pID
	if pID = 0 
		return
	ok
	itemInd = Find(ProgramItems, pID, 1)
	New RCRegistry {
		if ProgramItems[itemInd][4]
			OpenKey([ProgramItems[itemInd][5], "Software\Microsoft\Windows\CurrentVersion\Run", CREG_CREATE, ProgramItems[itemInd][6]])
		else
			OpenKey([HKEY_Current_User, "Software\WinStartupManager\Disabled\" + String(ProgramItems[ItemInd][5]) + "\" + String(ProgramItems[ItemInd][6])])
		ok
		Self[ProgramItems[itemInd][2]].Delete()
		CloseKey()
	}
	ProgramItems[itemInd] = [0, "", "", 0, 0, 0] # reset but not deleted to reserve list length

Func SysCmd cmd 
	System(cmd + " > syscmd.dat")
	cStr = read("syscmd.dat")
	System("del syscmd.dat")
	return cStr
