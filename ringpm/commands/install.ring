/*
	Title :	The Ring Package Manager 
	Date  : 2018.10.18
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

# Load Global Libraries 
	load "stdlibcore.ring"

# Load Application Files
	load "installcommand.ring"

func AddTimeStamp cURL
	return cURL + "?ts="+EpochTime(date(),time())

func DownloadFile cURL
	if isWindows()
		cURL = substr(cURL,"/","\")
	ok
	if lLocalPackages 
		if ! fexists(cURL)
			? C_ERROR_PACKAGENOTFOUND
			lInstallError 	= True
			return 
		ok
		return Read(cURL)
	ok
	return Download(AddTimeStamp(cURL))

func GetPackageFile cPackageName
	oInstall = new InstallCommand 
	return oInstall.GetPackageFile(cPackageName)

func GetPackage cPackageName
	oInstall = new InstallCommand 
	return oInstall.GetPackage(cPackageName)
