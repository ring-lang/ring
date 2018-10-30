/*
	Title :	The Ring Package Manager 
	Date  : 2018.10.18
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

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

func GetPackageFile cPackageName,cBranchName
	oInstall = new InstallCommand 
	if cBranchName != NULL
		oInstall.cBranchName = cBranchName
	ok
	return oInstall.GetPackageFile(cPackageName)

func GetPackage cPackageName,cBranchName,lUpdate
	oInstall = new InstallCommand 
	oInstall.cBranchName = cBranchName
	oInstall.lUpdate = lUpdate
	return oInstall.GetPackage(cPackageName)
