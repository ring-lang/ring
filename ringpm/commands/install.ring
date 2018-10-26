/*
	Title :	The Ring Package Manager 
	Date  : 2018.10.18
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

load "stdlibcore.ring"
load "installcommand.ring"

if isMainSourceFile()
	TestProcessVersion()
ok

func TestProcessVersion
	? 1.9 > 1.10			# 1 (True)
	? ProcessVersion("1.9")		# "1.9" --> "001009"   -->  1009
	? ProcessVersion("1.10")	# "1.10" ---> "001010" -->  1010
	? ProcessVersion("1.9") > ProcessVersion("1.10")	# 0 (False)

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
