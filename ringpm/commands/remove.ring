/*
	Title :	The Ring Package Manager 
	Date  : 2018.10.18
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/


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

