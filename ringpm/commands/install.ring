/*
	Title :	The Ring Package Manager 
	Date  : 2018.10.18
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

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
	DownloadPackageFiles(aPackageInfo,cPackageInfo)
	DownloadRelatedPackages(aPackageInfo,cPackageInfo)

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
			cFileContent 	= Download(cFileURL)
			write(cFileName,cFileContent)
		next
	? "Operation done!"
	chdir(cCurrentDir)

func DownloadRelatedPackages aPackageInfo,cPackageInfo
	for aRelatedPackage in aPackageInfo[:libs]
		InstallPackage(aRelatedPackage[:name])
	next
