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
		OSDeleteFolder(cPackageName)
	# Delete the loader file in ring/bin folder 
		remove(exefolder()+cPackageName+GetMajorVersionText(aPackageInfo[:version])+".ring")

	DisplayOperationDone()
	chdir(cCurrentDir)

