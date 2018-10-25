/*
	Title :	The Ring Package Manager 
	Date  : 2018.10.18
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

load "stdlibcore.ring"

if isMainSourceFile()
	? 1.9 > 1.10			# 1 (True)
	? ProcessVersion("1.9")		# "1.9" --> "001009"   -->  1009
	? ProcessVersion("1.10")	# "1.10" ---> "001010" -->  1010
	? ProcessVersion("1.9") > ProcessVersion("1.10")	# 0 (False)
ok

func AddTimeStamp cURL
	return cURL + "?ts="+EpochTime(date(),time())

func DownloadFile cURL
	if isWindows()
		cURL = substr(cURL,"/","\")
	ok
	if lLocalPackages 
		if ! fexists(cURL)
			? C_ERROR_PACKAGENOTFOUND
			return 
		ok
		return Read(cURL)
	ok
	return Download(AddTimeStamp(cURL))

func GetPackageFile cPackageName
	if lLocalPackages 
		cPackageURL  	= cPackagesLocations + "/" + cPackageName + "/"
		cDir = CurrentDir()
			chdir(cPackageURL)
			SystemSilent("git checkout master")
		chdir(cDir)
	else 
		cPackageURL  	= cPackagesLocations + "/" + cPackageName + "/master/"
	ok
	cPackageFileURL = cPackageURL + "package.ring"
	cPackageInfo 	= DownloadFile(cPackageFileURL)
	# We are using local packages, and the package doesn't exist
		if cPackageInfo = "" lInstallError = True return ok
	if substr(cPackageInfo,"404") 
		? C_ERROR_CANTDOWNLOADTHEPACKAGEFILE
		? "File URL : " + cPackageFileURL
		cPackageInfo = ""
		lInstallError 	= True
	ok
	return cPackageInfo

func InstallPackage cPackageName
	# If we have the package ---> Return (Don't install it)
		if fexists("packages/"+cPackageName+"/package.ring")
			? C_ERROR_PACKAGEALREADYEXISTS
			? "Package Name : " + cPackageName 
			lInstallError 	= True
			return 
		ok
	? "Installing package   : " + cPackageName
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
	ok

func DisplayPackageInformation aPackageInfo
	? "Package Name         : " + aPackageInfo[:name]
	? "Package Description  : " + aPackageInfo[:Description]
	? "Package Developer    : " + aPackageInfo[:developer]
	? "Package License      : " + aPackageInfo[:license]

func DownloadPackageFiles aPackageInfo,cPackageInfo
	cCurrentDir = CurrentDir()
	# Create the package folder
		chdir("packages")
		OSCreateOpenFolder(aPackageInfo[:folder])
	# Write the Package File 	
		write("package.ring",cPackageInfo)
	# Download package files 
		for cFileName in aPackageInfo[:Files]
			? "Download File : " + cFileName 
			cFileURL 	= cPackageURL + cFileName
			cFileContent 	= DownloadFile(cFileURL)
			cDir  = CurrentDir()
			CreateSubFolders(cFileName)
			chdir(cDir)
			write(cFileName,cFileContent)
		next
	? "Operation done!"
	chdir(cCurrentDir)

func DownloadRelatedPackages aPackageInfo,cPackageInfo
	for aRelatedPackage in aPackageInfo[:libs]
		InstallPackage(aRelatedPackage[:name])
		oAllPackagesInfo.AddRelatedPackage(
			aRelatedPackage[:name],
			aPackageInfo[:folder]
		)
	next

