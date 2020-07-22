/*
	Title :	The Ring Package Manager 
	Date  : 2018.11.02
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

func RunPackage cPackageName
	# Get Package File 
		cLocalPackageFile  = GetLocalPackageFile(cPackageName)
		aCheck = CheckPackageFile(cLocalPackageFile)
		if ! aCheck[1] return ok
		aPackageInfo = aCheck[2]
	# Run The Package 
		lRun = False 
		lRun += RunPackageCommand(aPackageInfo[:run],cPackageName)
		if isWindows() and aPackageInfo[:WindowsRun] != NULL 
			lRun += RunPackageCommand(aPackageInfo[:WindowsRun],cPackageName)
		but isLinux()
			if aPackageInfo[:LinuxRun] != NULL 
				lRun += RunPackageCommand(aPackageInfo[:LinuxRun],cPackageName)
			ok
			if fexists(exefolder()+"/ubuntu.txt") and aPackageInfo[:UbuntuRun] != NULL 
				lRun += RunPackageCommand(aPackageInfo[:UbuntuRun],cPackageName)
			but fexists(exefolder()+"/fedora.txt") and aPackageInfo[:FedoraRun] != NULL 
				lRun += RunPackageCommand(aPackageInfo[:FedoraRun],cPackageName)
			ok
		but isMacosx() and aPackageInfo[:MacOSRun] != NULL 
			lRun += RunPackageCommand(aPackageInfo[:MacOSRun],cPackageName)
		ok		
		if lRun = False 
			? C_NOTE_NOCOMMANDTORUNTHEPACKAGE
		ok
	
func RunPackageCommand cRun,cPackageName
		if cRun != NULL
			cDir = CurrentDir()
			chdir(cMainPackagesFolder+"/"+cPackageName)
			system(cRun)
			chdir(cDir)
			return True
		ok
		return False

func RunCurrentPackage
	# Run package in the current folder 
		cLocalPackageFile = read("package.ring")
		if cLocalPackageFile = NULL return ok
		aCheck = CheckPackageFile(cLocalPackageFile)
		if ! aCheck[1] return ok
		aPackageInfo = aCheck[2]
	# Run The Package 
		cRun = aPackageInfo[:run]
		# We don't change the current folder because we already in the package folder
		if cRun != NULL
			system(cRun)
		else 
			? C_NOTE_NOCOMMANDTORUNTHEPACKAGE
		ok
