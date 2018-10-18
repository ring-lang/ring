/*
	Title :	The Ring Package Manager 
	Date  : 2018.10.18
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/


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
	# Print message if we don't have packages 
		if len(aPackagesInfoFiles) = 0
			? "No installed packages!"
		ok
