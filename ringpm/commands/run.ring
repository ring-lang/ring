/*
	Title :	The Ring Package Manager 
	Date  : 2018.11.02
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

func RunPackage cPackageName
	# Get Package File 
		cLocalPackageFile  = GetLocalPackageFile(cPackageName)
		if cLocalPackageFile = NULL return ok
		eval(cLocalPackageFile)
	# Run The Package 
		cRun = aPackageInfo[:run]
		if cRun != NULL
			cDir = CurrentDir()
			chdir(cMainPackagesFolder+"/"+cPackageName)
			system(cRun)
			chdir(cDir)
		else 
			? C_NOTE_NOCOMMANDTORUNTHEPACKAGE
		ok
