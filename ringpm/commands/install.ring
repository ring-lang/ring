/*
	Title :	The Ring Package Manager 
	Date  : 2018.10.18
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

load "stdlibcore.ring"

if isMainSourceFile()
	? ProcessVersion("1.9")
	? ProcessVersion("1.10")
ok


func InstallPackage cPackageName
	? "Installing package   : " + cPackageName
	cPackageURL  	= cPackagesLocations + "/" + cPackageName + "/master/"
	cPackageFileURL = cPackageURL + "package.ring"
	cPackageInfo 	= Download(cPackageFileURL)
	cPackageInfo = Substr(cPackageInfo,nl,WindowsNl())
	if substr(cPackageInfo,"404")
		? C_ERROR_CANTDOWNLOADTHEPACKAGEFILE
		? "File URL : " + cPackageFileURL
		return 
	ok
	try
		eval( cPackageInfo )
	catch
		? C_ERROR_PACKAGEINFOISNOTCORRECT
		? cPackageInfo
		return 
	done 
	if ! islocal(:aPackageInfo)
		? C_ERROR_NOPACKAGEINFO
		return 
	ok
	DisplayPackageInformation(aPackageInfo)
	# Check that we have the required Ring version
		cPackageVersion = aPackageInfo[:version]
		if ! CheckRingVersion(aPackageInfo) 
			? C_ERROR_BADRINGVERSION			
			? "Current  Ring Version : " + version()
			? "Required Ring Version : " + aPackageInfo[:ringversion]
 			return 
		ok
	DownloadPackageFiles(aPackageInfo,cPackageInfo)
	DownloadRelatedPackages(aPackageInfo,cPackageInfo)

func DisplayPackageInformation aPackageInfo
	? "Package Name         : " + aPackageInfo[:name]
	? "Package Description  : " + aPackageInfo[:Description]
	? "Package Developer    : " + aPackageInfo[:developer]
	? "Package License      : " + aPackageInfo[:license]

func CheckRingVersion aPackageInfo
	# 1.8 < 1.9 
	# 1.9 < 1.10
	if ProcessVersion(version()) >= ProcessVersion(aPackageInfo[:ringversion])
		 return True ok 
	return False 

func ProcessVersion cVersion
	// 	1.9		---->  001009
	//	1.10		---->  001010
	aVersion = Split(cVersion,".")		# List of Numbers 
	# 1.9 ---> [ "001" , "009"]
		for cNumber in aVersion
			nSize = len(cNumber)
			if nSize < 3 
				cNumber = Copy("0",3-nSize) + cNumber 
			ok
		next 
	cVersion = List2Str(aVersion)	# [ "001" , "009"] ---> 001 + nl + 009
	cVersion = substr(cVersion,nl,"")
	return 0+cVersion		# 001009 ---> 1009 

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
			cFileContent 	= Download(cFileURL)
			write(cFileName,cFileContent)
		next
	? "Operation done!"
	chdir(cCurrentDir)

func DownloadRelatedPackages aPackageInfo,cPackageInfo
	for aRelatedPackage in aPackageInfo[:libs]
		InstallPackage(aRelatedPackage[:name])
	next
