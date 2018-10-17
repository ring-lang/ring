/*
	Title :	The Ring Package Manager 
	Date  : 2018.10.17
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

# Load Libraries 
	load "stdlibcore.ring"
	load "libcurl.ring"
	load "internetlib.ring"

# Where we will store our pacakge 
	cPackagesLocations = "https://raw.githubusercontent.com/MahmoudFayed"
# The parameters of our command 	
	aCommand	   = []
# Errors 
	C_ERROR_NOPACKAGENAME			= "Error(1) : No package name!"
	C_ERROR_NOPACKAGEINFO 			= "Error(2) : No package info!"
	C_ERROR_WEDONTHAVETHISPACKAGE		= "Error(3) : We don't have this package"
	C_ERROR_PACKAGEINFOISNOTCORRECT 	= "Error(4) : Package info is not correct"
	C_ERROR_CANTDOWNLOADTHEPACKAGEFILE 	= "Error(5) : Can't download the package file"

# Folders
	cMainPackagesFolder 	= "/packages"
	cPackageURL		= ""

func Main 
	GetParameters()
	Title()
	Instructions()	
	ExecuteInstructions()
	
func Title
	# Don't display instruction if we have commands
		if len(aCommand) >= 1 return ok
	Line()
	? "Ring Package Manager (RingPM)" 
	? "2018, Mahmoud Fayed <msfclipper@yahoo.com>"
	Line()

func Line
	? copy("=",70)

func Instructions
	# Don't display instruction if we have commands
		if len(aCommand) >= 1 return ok
	? "Usage   : ringpm  <command>"
	? "Command : install <packagename>"
	? "Command : remove  <packagename>"
	? "Command : list"
	
func GetParameters
	aPara = sysargv
	if len(aPara) > 2
		for x = 3 to len(aPara)
			aCommand + aPara[x]
		next
	ok

func ExecuteInstructions
	# Check if we don't have commands
		if len(aCommand) < 1 return ok
	# The command is not case-sensitive
		cCommand = lower(trim(aCommand[1]))
	# Execute Commands
		switch cCommand 
			on "install"
				if len(aCommand) < 2 
					? C_ERROR_NOPACKAGENAME
					return 
				ok 
				cPackageName = aCommand[2]
				InstallPackage(cPackageName)
			on "list"
				PrintInstalledPackages()
			on "remove"
				cPackageName = aCommand[2]
				RemovePackage(cPackageName)
		off
	
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
		return 
	done 
	if ! islocal(:aPackageInfo)
		? C_ERROR_NOPACKAGEINFO
		return 
	ok
	DisplayPackageInformation(aPackageInfo)
	DownloadPackageFiles(aPackageInfo,cPackageInfo)

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

func PrintInstalledPackages
	# Get Files
		aFiles 			= ListAllFiles("packages","ring")
	# Get Package Info Files
		aPackagesInfoFiles 	= []
		for cFile in aFiles
			if JustFileName(cFile) = "package.ring"
				aPackagesInfoFiles + cFile 
			ok
		next
	# Print Packages 
		for cFile in aPackagesInfoFiles 
			eval(read(cFile))
			? "Package : " + aPackageInfo[:name]
		next 

func RemovePackage cPackageName
	cCurrentDir = CurrentDir()
	# Check if we have the package 
		cPackageFolder = "packages/"+cPackageName
		cPath = cPackageFolder+"/package.ring"
		if ! fexists(cPath)
			? C_ERROR_WEDONTHAVETHISPACKAGE
			return
		ok
	# Delete the package 
		? "Deleting Package : " + cPackageName
		chdir("packages")
		OSDeleteFolder(cPackageName)
	? "Operation done!"
	chdir(cCurrentDir)
