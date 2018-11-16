/*
	Title :	The Ring Package Manager 
	Date  : 2018.10.26
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

class InstallCommand

	cPackageURL 	= ""
	cBranchName 	= "master"
	cPackageVersion = ""
	lUpdate	    	= False

	# Where we have our pacakge 
		lLocalPackages	   = True 
		cPackagesLocations = exefolder()+"../ringpm/local"
	
	func InstallFrom cUserName 
		lLocalPackages	   = False
		cPackagesLocations = "https://raw.githubusercontent.com/" + cUserName

	func InstallPackage cPackageName
		if lUpdate = False
			Style("Installing ",:YellowBlack) 
		else 
			Style("Updating ",:YellowBlack) 
		ok
		see Width(cPackageName + " (" + cBranchName + ")" , 10)
		GetPackage(cPackageName)

	func GetPackage cPackageName
		cPackageInfo = GetPackageFile(cPackageName)
		aCheck = CheckPackageFile(cPackageInfo)
		if ! aCheck[1] lInstallError = True return ok
		aPackageInfo = aCheck[2]
		DisplayPackageInformation(aPackageInfo)
		# Check that we have the required Ring version
			if ! CheckRingVersion(aPackageInfo) 
				? C_ERROR_BADRINGVERSION			
				? "Current  Ring Version : " + version()
				? "Required Ring Version : " + aPackageInfo[:ringversion]
				lInstallError 	= True
	 			return 
			ok
		# Check Package Version 
			if cPackageVersion != NULL 
				if not IsCompatible(cPackageVersion,aPackageInfo[:version])
					? nl + C_NOTE_PACKAGEVERSIONISNOTCOMPATIBLE
					? "Package  Version : " + aPackageInfo[:version]
					? "Required Version : " + cPackageVersion
					if cBranchName = "master"
						? "Searching for a compatible version"
						if isList(aPackageInfo[:versions])
							for aVersion in aPackageInfo[:versions]
								if IsCompatible(cPackageVersion,aVersion[:Version])
									if aVersion[:Branch] != "master"
										cBranchName 	= aVersion[:Branch]
										? "Found .. version : " + aVersion[:Version] +
										   " .. Using Branch : " + aVersion[:Branch]
										InstallPackage(cPackageName)
							 			return 
									ok
								ok
							next 
						ok
						? "Not Found! Contact the package creator for support!"
					ok
					lInstallError 	= True
		 			return 
				ok
			ok
		cPackageFolderName = GetPackageFolderName(aPackageInfo)
		see " ---> " + cPackageFolderName + nl
		# If we have the package ---> Return (Don't install it)
			if lUpdate = False
				if fexists(cMainPackagesFolder+"/"+cPackageFolderName+"/package.ring")
					? " - " + C_NOTE_PACKAGEALREADYEXISTS
					# Check Update 
						if CheckPackageUpdate(cPackageName) = True 
							UpdatePackage(cPackageName)
						ok
					return 
				ok
			ok
		DownloadRelatedPackages(aPackageInfo,True)
		if ! lInstallError 
			DownloadPackageFiles(aPackageInfo,cPackageInfo)
		else 
			? "Install Operation (Not Completed)"
			return 
		ok
		WriteLockFile(aPackageInfo,self)
		# Create file for loading the package in ring/bin folder 
			cCompletePackageName = cPackageName+GetMajorVersionText(aPackageInfo[:version])
			write(exefolder()+cCompletePackageName+".ring",
				'load "/../ringpm/packages/'+cCompletePackageName+'/lib.ring"')

	func GetPackageFile cPackageName
		if lLocalPackages 
			cPackageURL  	= cPackagesLocations + "/" + cPackageName + "/"
			cDir = CurrentDir()
				chdir(cPackageURL)
				SystemSilent("git checkout " + cBranchName)
			chdir(cDir)
		else 
			cPackageURL  	= cPackagesLocations + "/" + cPackageName +
						 "/"+cBranchName+"/"
		ok
		cPackageFileURL = cPackageURL + "package.ring"
		cPackageInfo 	= DownloadFile(cPackageFileURL)
		# We are using local packages, and the package doesn't exist
			if cPackageInfo = "" return ok
		if substr(cPackageInfo,"404") 
			see nl
			? C_ERROR_CANTDOWNLOADTHEPACKAGEFILE
			? "File URL : " + cPackageFileURL
			cPackageInfo = ""
			lInstallError 	= True
		ok
		return cPackageInfo
	
	func DisplayPackageInformation aPackageInfo
		if lDisplayPackageInfo = False return ok
		? "Package Name         : " + aPackageInfo[:name]
		? "Package Description  : " + aPackageInfo[:Description]
		? "Package Developer    : " + aPackageInfo[:developer]
		? "Package License      : " + aPackageInfo[:license]
	
	func DownloadRelatedPackages aPackageInfo,lAllPackages
		cFolder = GetPackageFolderName(aPackageInfo) 
		for x = 1 to len(aPackageInfo[:libs])
			aRelatedPackage = aPackageInfo[:libs][x]
			if aRelatedPackage[:name] = NULL loop ok
			oInstall = new InstallCommand
			cRelatedPackageName = aRelatedPackage[:name]
			# Support installing from different branches 
				if aRelatedPackage[:branch] != NULL 
					oInstall.cBranchName 	 = aRelatedPackage[:branch]
					cRelatedPackageName += aRelatedPackage[:branch]
				ok
			oInstall.cPackageVersion = aRelatedPackage[:version]
			oInstall.lUpdate = lUpdate
			oInstall.InstallPackage(aRelatedPackage[:name])
			if lAllPackages
				oAllPackagesInfo.AddRelatedPackage(
					cRelatedPackageName+GetMajorVersionText(aRelatedPackage[:version]),
					cFolder
				)
			ok
		next

	func DownloadPackageFiles aPackageInfo,cPackageInfo
		cCurrentDir = CurrentDir()
		# Create the package folder
			chdir(cMainPackagesFolder)
			OSCreateOpenFolder(GetPackageFolderName(aPackageInfo))
		# Write the Package File
			cPackageInfo = UpdateFolderName(aPackageInfo) 	
			write("package.ring",cPackageInfo)
		# Download package files 
		lWriteError = False
			for cFileName in aPackageInfo[:Files]
				if lDisplayPackageFiles
					? "Download File : " + cFileName 
				ok
				cFileURL 	= cPackageURL + cFileName
				cFileContent 	= DownloadFile(cFileURL)
				cDir  = CurrentDir()
				CreateSubFolders(cFileName)
				chdir(cDir)
				Try
					write(cFileName,cFileContent)
				Catch
					? C_ERROR_CANTWRITETHEFILE 
					? "File Name : " + cFileName 
					lWriteError = True
				Done 
			next
		if ! lWriteError
			DisplayOperationDone()
		ok
		chdir(cCurrentDir)

	func SetBranchFromCommandLine
		nPos = find(aCommand,"branch")
		if ! nPos return ok
		if len(aCommand) > nPos 	# We have branch name 
			cBranchName = aCommand[nPos+1]	
		else 
			? C_ERROR_BRANCHNAMEISMISSING
		ok

	func GetPackageFolderName aPackageInfo
		return aPackageInfo[:folder] + GetMajorVersionText(aPackageInfo[:Version])

	func UpdateFolderName aPackageInfo
		aPackageInfo[:remotefolder] = aPackageInfo[:folder]
		aPackageInfo[:folder] = GetPackageFolderName(aPackageInfo)
		aPackageInfo[:branch] = cBranchName
		new List2Code {
			cPackageInfo = "aPackageInfo = " + List2Code(aPackageInfo)
		}
		return cPackageInfo

	func InstallPackageFromCurrentFolder
		? "Get Package Information"
		cPackageInfo = read("package.ring")
		aCheck = CheckPackageFile(cPackageInfo)
		if ! aCheck[1] lInstallError = True return ok
		aPackageInfo = aCheck[2]
		? "Install Dependencies"
		DownloadRelatedPackages(aPackageInfo,False)
		DisplayOperationDone()

	func DownloadFile cURL
		if lLocalPackages 
			if isWindows()
				cURL = substr(cURL,"/","\")
			ok
			if ! fexists(cURL)
				see nl
				? C_ERROR_PACKAGENOTFOUND
				lInstallError 	= True
				return 
			ok
			return Read(cURL)
		ok
		return Download(AddTimeStamp(cURL))

	func AddTimeStamp cURL
		return cURL + "?ts="+EpochTime(date(),time())
