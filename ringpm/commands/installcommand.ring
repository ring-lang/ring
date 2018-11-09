/*
	Title :	The Ring Package Manager 
	Date  : 2018.10.26
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

class InstallCommand

	cPackageURL = ""
	cBranchName = "master"
	lUpdate	= False

	func InstallPackage cPackageName
		if lUpdate = False
			Style("Installing ",:YellowBlack) 
		else 
			Style("Updating ",:YellowBlack) 
		ok
		see cPackageName 
		if cBranchName != "master"
			see " (" + cBranchName + ")"
		ok
		see nl
		GetPackage(cPackageName)

	func GetPackage cPackageName
		cPackageInfo = GetPackageFile(cPackageName)
		if cPackageInfo = "" return ok
		try
			eval( cPackageInfo )
		catch
			? C_ERROR_PACKAGEINFOISNOTCORRECT
			? cPackageInfo
			lInstallError 	= True
			return 
		done 
		# If we have the package ---> Return (Don't install it)
			if lUpdate = False
				if fexists("packages/"+GetPackageFolderName(aPackageInfo)+
						"/package.ring")
					? " - " + C_NOTE_PACKAGEALREADYEXISTS
					# Check Update 
						if CheckPackageUpdate(cPackageName) = True 
							UpdatePackage(cPackageName)
						ok
					return 
				ok
			ok
		if ! islocal(:aPackageInfo)
			? C_ERROR_NOPACKAGEINFO
			lInstallError 	= True
			return 
		ok
		DisplayPackageInformation(aPackageInfo)
		# Check that we have the required Ring version
			if ! CheckRingVersion(aPackageInfo) 
				? C_ERROR_BADRINGVERSION			
				? "Current  Ring Version : " + version()
				? "Required Ring Version : " + aPackageInfo[:ringversion]
				lInstallError 	= True
	 			return 
			ok
		DownloadRelatedPackages(aPackageInfo,cPackageInfo)
		if ! lInstallError 
			DownloadPackageFiles(aPackageInfo,cPackageInfo)
		else 
			? "Install Operation (Not Completed)"
			return 
		ok
		WriteLockFile(aPackageInfo,self)

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
	
	func DownloadRelatedPackages aPackageInfo,cPackageInfo
		cFolder = GetPackageFolderName(aPackageInfo) 
		for aRelatedPackage in aPackageInfo[:libs]
			oInstall = new InstallCommand
			cRelatedPackageName = aRelatedPackage[:name]
			# Support installing from different branches 
				if aRelatedPackage[:branch] != NULL 
					oInstall.cBranchName = aRelatedPackage[:branch]
					cRelatedPackageName += aRelatedPackage[:branch]
				ok
			oInstall.lUpdate = lUpdate
			oInstall.InstallPackage(aRelatedPackage[:name])
			oAllPackagesInfo.AddRelatedPackage(
				cRelatedPackageName,
				cFolder
			)
		next

	func DownloadPackageFiles aPackageInfo,cPackageInfo
		cCurrentDir = CurrentDir()
		# Create the package folder
			chdir("packages")
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
			if lDisplayOperationDone
				? "Operation done!"
			ok
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
		if cBranchName = "master"
			return aPackageInfo[:folder] + GetMajorVersion(aPackageInfo)
		ok
		return aPackageInfo[:folder] + cBranchName 

	func UpdateFolderName aPackageInfo
		aPackageInfo[:remotefolder] = aPackageInfo[:folder]
		aPackageInfo[:folder] = GetPackageFolderName(aPackageInfo)
		aPackageInfo[:branch] = cBranchName
		new List2Code {
			cPackageInfo = "aPackageInfo = " + List2Code(aPackageInfo)
		}
		return cPackageInfo

	func GetMajorVersion aPackageInfo
		# Before version 1.0.0 ---> We return the package version 
		# From version 1.0.0 < 2.0.0 ---> We return empty string 
		# From 2.0.0 ---> We return the major version (v2, v3, etc)
		cVersion = aPackageInfo[:version]
		nPos = substr(cVersion,".")
		if nPos 
			cVersion = left(cVersion,nPos-1)
		ok
		nMajor = 0 + cVersion 
		if nMajor = 0
			return "v"+aPackageInfo[:version]
		but nMajor = 1 
			return 
		else 
			return "v"+nMajor
		ok
