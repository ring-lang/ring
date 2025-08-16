# Application : RingPM GUI
# Author      : Ring Community
# Date        : 2025.08.16
# Description : GUI interface for Ring Package Manager

load "ringpmguiView.ring"

if isMainSourceFile() { 
	new qApp
	{
		StyleFusion()
		open_window(:ringpmguiController)
		exec()
	}
}

class ringpmguiController from WindowsControllerParent

	oView = new ringpmguiView

  oView.tblPackages.setSelectionMode(QAbstractItemView_SingleSelection)

	SysSet("CUILIB_COLORS", "0") 

	aInstalledPackages = []

	oCurrentProcess = NULL

	mylist = new qStringList()
	
	cPackagesPath = "../ringpm/packages"

	# Load installed packages
	loadInstalledPackages()
	
	func completer
		mycompleter = new qCompleter3(mylist,oView.win)
		mycompleter.setCaseSensitivity(Qt_CaseInsensitive)
		oView.txtPackageName.setCompleter(mycompleter)

	# Search if package exist
	func Search
		oView {
			cStrSearch =  txtPackageName.Text()
			if len(cStrSearch) > 3
				for index = 1 to len(this.aInstalledPackages)
					if 	this.aInstalledPackages[index][:folder] = cStrSearch 
						tblPackages.setcurrentcell( index , 1)
					ok
				next
			ok
		}
	
	# Install a package
	func installPackage
		cPackageName = trim(oView.txtPackageName.text())
		cUserName = trim(oView.txtUserName.text())

		if cPackageName = ""
			showMessage("Please enter a package name to install.")
			return
		ok

		executeRingPMCommand("refresh")

		if cPackageName != ""
			executeRingPMCommand("install " + cPackageName)
		ok

		if cPackageName != "" and cUserName != ""
			executeRingPMCommand("install " + cPackageName + " from " + cUserName)
		ok

	# Run selected package
	func runPackage
		cPackageName = getSelectedPackageName()
		if cPackageName = ""
			showMessage("Please select a package to run.")
			return
		ok
		
		executeRingPMCommand("run " + cPackageName)
	
	# Update selected package
	func updatePackage
		cPackageName = getSelectedPackageName()
		if cPackageName = ""
			showMessage("Please select a package to update.")
			return
		ok
		
		executeRingPMCommand("update " + cPackageName)
	
	# Remove selected package
	func removePackage
		cPackageName = getSelectedPackageName()
		if cPackageName = ""
			showMessage("Please select a package to remove.")
			return
		ok
		
		# Confirm removal
		nResult = msgBox("Are you sure you want to remove package '" + cPackageName + "'?", 
						"Confirm Removal", 1)  # Yes/No buttons
		if nResult = 1  # Yes button
			executeRingPMCommand("remove " + cPackageName)
		ok

	# Get the name of the currently selected package
	func getSelectedPackageName
		oView {
			nCurrentRow = tblPackages.currentRow()-1
			if nCurrentRow >= 0 and nCurrentRow < len(this.aInstalledPackages)
				return this.aInstalledPackages[nCurrentRow+1][:folder]
			ok
		}
		return ""
	
	# Handle package selection in table
	func packageSelected
		# Enable/disable action buttons based on selection
		bHasSelection = (getSelectedPackageName() != "")
		oView {
			btnRun.setEnabled(bHasSelection)
			btnUpdate.setEnabled(bHasSelection)
			btnRemove.setEnabled(bHasSelection)
		}

	# Execute RingPM command using QProcess
	func executeRingPMCommand cCommand
		oView {
			txtOutput.append("Executing: ringpm " + cCommand + nl)
			txtOutput.append("----------------------------------------" + nl)
		}
		
		aPara = split(cCommand," ")
		oCommandList = new qStringlist() {
			for cPara in aPara
				append(cPara)
			next
		}

		# Create and configure QProcess
		oCurrentProcess= new qprocess(NULL) {
			setprogram( "ringpm")
			setarguments(oCommandList)
			setReadyReadStandardOutputEvent(Method(:processOutput))
			setReadyReadStandardErrorEvent(Method(:processError))
			start_3( QIODevice_ReadWrite )
		}
	
	# Handle process output
	func processOutput
		if oCurrentProcess != NULL
			cOutput = oCurrentProcess.readAllStandardOutput().data()
			oView.txtOutput.append(cOutput )

		ok
		
		oCursor = oView.txtOutput.textcursor()
		nPos = max(len(oView.txtOutput.toplaintext()),0)
		oCursor.setPosition(nPos,QTextCursor_KeepAnchor)
		oCursor.setPosition(nPos,QTextCursor_MoveAnchor)
		oView.txtOutput.setTextCursor(oCursor)
		
		# Refresh package list after any command that might change packages
		loadInstalledPackages()
		
		

	# Handle process errors
	func processError
		if oCurrentProcess != NULL
			cError = oCurrentProcess.readAllStandardError().data()
			oView.txtOutput.append("Error: " + cError)
		ok

	# Load installed packages from packages directory
	func loadInstalledPackages
		aInstalledPackages = []
		mylist.clear()
		try
			# Get all package.ring files in packages directory
			aFiles = []
			if direxists(cPackagesPath)
				aFiles = listAllFiles(cPackagesPath, "ring")
			ok

			# Process each package.ring file
			for cFile in aFiles
				if right(cFile, 12) = "package.ring"
					aPackageInfo = getPackageInfo(cFile)
					if len(aPackageInfo) > 0
						aInstalledPackages + aPackageInfo
					ok
				ok
			next
			
			# Update the table
			updatePackageTable()
			completer()
		catch
			showMessage("Error loading package information.")
		done

		

	# Get package information from package.ring file
	func getPackageInfo cPackageFile
		aPackageInfo = []
		
		try
			cContent = read(cPackageFile)
			eval(cContent)

			# Extract package information (assuming aPackageInfo is defined in the file)
			if islocal(:aPackageInfo) and len(aPackageInfo) > 0
				return aPackageInfo
			ok
			
		catch
			# Ignore files that can't be processed
		done

		return []

	# Update the package table with installed packages
	func updatePackageTable
		oView {
			# Clear existing rows
			tblPackages.setRowCount(0)
			
			# Add packages to table
			for i = 1 to len(this.aInstalledPackages)
				aPackage = this.aInstalledPackages[i]
				this.mylist.Append(aPackage[:folder])

				# Add row
				tblPackages.setRowCount(i)

				# Set package name
				tblPackages.setItem(i, 1, new QTableWidgetItem(aPackage[:folder]))
				
				# Set package description
				tblPackages.setItem(i, 2, new QTableWidgetItem(aPackage[:description]))

				# Set package version
				tblPackages.setItem(i, 3, new QTableWidgetItem(aPackage[:version]))

			next

			# Disable action buttons if no packages
			bHasPackages = (len(this.aInstalledPackages) > 0)
			btnRun.setEnabled(false)
			btnUpdate.setEnabled(false)
			btnRemove.setEnabled(false)
		}

	# Show message to user
	func showMessage cMessage
		msgBox(cMessage, "RingPM GUI", 0)

	# Close application
	func closeApplication
		oCurrentProcess = NULL
		SysSet("CUILIB_COLORS", "1") 
		oView.win.close()

	func msgBox cMessageBoxText, cMessageBoxTitle, nLevel
		oMessageBox = new qmessagebox(oView.win) 
        oMessageBox.setwindowtitle(cMessageBoxTitle)
        oMessageBox.settext(cMessageBoxText )
        if nLevel = 0 oMessageBox.show() ok
        if nLevel = 1
            oMessageBox.setstandardbuttons(QMessageBox_Yes | QMessageBox_No)
            result = oMessageBox.exec()  
			if result = QMessageBox_Yes
					return "1"
			but result = QMessageBox_No
					return "0"	
			ok
		ok
