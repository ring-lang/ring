/*
	Title :	The Ring Package Manager 
	Date  : 2018.10.26
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

class InstallCommand

	cPackageURL = ""
	cBranchName = "master"

	func InstallPackage cPackageName
		Style("Installing ",:YellowBlack) see cPackageName
		# If we have the package ---> Return (Don't install it)
			if fexists("packages/"+cPackageName+"/package.ring")
				? " - " + C_NOTE_PACKAGEALREADYEXISTS
				return 
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
		WriteLockFile(aPackageInfo)

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
		for aRelatedPackage in aPackageInfo[:libs]
			oInstall = new InstallCommand
			oInstall.InstallPackage(aRelatedPackage[:name])
			oAllPackagesInfo.AddRelatedPackage(
				aRelatedPackage[:name],
				aPackageInfo[:folder]
			)
		next

	func DownloadPackageFiles aPackageInfo,cPackageInfo
		cCurrentDir = CurrentDir()
		# Create the package folder
			chdir("packages")
			OSCreateOpenFolder(aPackageInfo[:folder])
		# Write the Package File 	
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
