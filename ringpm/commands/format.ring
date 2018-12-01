/*
	Title :	The Ring Package Manager 
	Date  : 2018.11.05
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

func DeleteAllPackages 
	? "RingPM - Format - Delete All Packages"
	# Delete AllPackages.ring 
		oAllPackagesInfo.DeleteAllPackagesFile()
	# Delete Folders 
		aPackages = Dir(cMainPackagesFolder)
		cDir = CurrentDir()
		chdir(cMainPackagesFolder)
		nCount = 0
		for aItem in aPackages 
			if aItem[2] 	# Folder 
				cFolder = aItem[1]	# Folder Name 
				# Be sure that it's a package 
					if ! fexists(cFolder+"/package.ring") loop ok
				Style("Deleting ",:YellowBlack) ? cFolder 
				OSDeleteFolder(cFolder)
				# Delete the loader file in ring/bin folder 
					remove(exefolder()+cFolder+".ring")

				nCount++
			ok
		next 
		? "Deleted Packages Count : " + nCount
		chdir(cDir)

