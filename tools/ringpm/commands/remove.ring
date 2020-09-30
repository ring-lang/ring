/*
	Title :	The Ring Package Manager 
	Date  : 2018.10.18
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

func RemovePackage cPackageName
	cCurrentDir = CurrentDir()
	# Check if we have the package 
		cPackageFolder = cMainPackagesFolder+"/"+cPackageName
		cPath = cPackageFolder+"/package.ring"
		if ! fexists(cPath)
			? C_ERROR_WEDONTHAVETHISPACKAGE
			return
		ok
	Style("Deleting ",:YellowBlack) ? cPackageName
	# Check if we can remove the package (No related packages)
		aRelated = oAllPackagesInfo.CheckRelatedPackages(cPackageName)
		if len(aRelated) != 0
			? C_NOTE_AVOIDDELETINGAPACKAGE + "("+cPackageName + ") It's used by the Package (" +
						 aRelated[1] + ")"
			return 
		ok
	# Get the Package Information 
		if ! fexists(cPath) return ok
		eval(read(cPath))
	# Update All Packages Info 
		oAllPackagesInfo.RemovePackage(cPackageName)
	# Delete the Related Package 
		# Delete related packages 
			for aPackage in aPackageInfo[:libs]
				if aPackage[:name] = NULL loop ok
				RemovePackage(aPackage[:name]+GetMajorVersionText(aPackage[:Version]))
			next 
	# Delete the package 
		chdir(cMainPackagesFolder)
		DeletePackageFiles(cPackageName)

	DisplayOperationDone()
	chdir(cCurrentDir)

func DeletePackageFiles cFolder 
	# Load the Package File (To Be Used Later)
		eval(read(cFolder+"/package.ring"))
	RunRemoveScripts(aPackageInfo,cFolder)
	OSDeleteFolder(cFolder)
	# Delete the loader file in ring/bin folder 
		remove(exefolder()+cFolder+".ring")
	DeleteFilesInRingFolder(aPackageInfo,:RingFolderFiles)
	if isWindows()
		DeleteFilesInRingFolder(aPackageInfo,:WindowsRingFolderFiles)
	but isLinux()
		DeleteFilesInRingFolder(aPackageInfo,:LinuxRingFolderFiles)
		if fexists(exefolder()+"/ubuntu.txt")
			DeleteFilesInRingFolder(aPackageInfo,:UbuntuRingFolderFiles)
		but fexists(exefolder()+"/fedora.txt")
			DeleteFilesInRingFolder(aPackageInfo,:FedoraRingFolderFiles)
		ok

	but isMacOSX()
		DeleteFilesInRingFolder(aPackageInfo,:MacOSRingFolderFiles)
	ok

func DeleteFilesInRingFolder aPackageInfo,cAttribute
	cCurrentPackageDir = CurrentDir()
	# Remove Files Downloaded in the Ring Folder 
		chdir(exefolder()+"/../")
		for cFileName in aPackageInfo[cAttribute]
			Remove(cFileName)
		next
	chdir(cCurrentPackageDir)

func RunRemoveScripts aPackageInfo,cPackageFolderName
		cRemove = aPackageInfo[:remove]
		if cRemove != NULL or aPackageInfo[:WindowsRemove] != NULL or 
			aPackageInfo[:LinuxRemove] != NULL or aPackageInfo[:MacOSRemove] != NULL 
			Style("Removing files and folders ",:YellowBlack)
			cDir = CurrentDir()
			chdir(cMainPackagesFolder+"/"+cPackageFolderName)
			system(cRemove)
			if isWindows() and aPackageInfo[:Windowsremove] != NULL 
				System(aPackageInfo[:Windowsremove])
			but isLinux()
				if aPackageInfo[:Linuxremove] != NULL 
					System(aPackageInfo[:Linuxremove])
				ok
				if fexists(exefolder()+"/ubuntu.txt") and aPackageInfo[:Ubunturemove] != NULL 
					System(aPackageInfo[:Ubunturemove])
				but fexists(exefolder()+"/fedora.txt") and aPackageInfo[:Fedoraremove] != NULL 
					System(aPackageInfo[:Fedoraremove])
				ok
			but isMacosx() and aPackageInfo[:MacOSremove] != NULL 
				System(aPackageInfo[:MacOSremove])
			ok
			chdir(cDir)
		ok
