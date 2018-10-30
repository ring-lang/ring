/*
	Title :	The Ring Package Manager 
	Date  : 2018.10.18
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

func PrintInstalledPackages
	# Get Files
		Try
			new ListOfFiles {
				aFiles	= ListAllFiles("packages","ring")
			}
		Catch 
			? C_ERROR_CANTGETPACKAGESINFORMATION
			return 
		Done 
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
			see Style(Width("Package ("+aPackageInfo[:folder]+") ",25),:YellowBlack)+": " +
				 Width(aPackageInfo[:name],20) + " -- " +
				Width("("+aPackageInfo[:version]+ ")",15) 
				if lCheckUpdates 
					see  " -- "  
					See CheckUpdates(aPackageInfo) 
				ok
				see nl
		next 
	# Print message if we don't have packages 
		if len(aPackagesInfoFiles) = 0
			? "No installed packages!"
		ok

func CheckUpdates aLocalPackageInfo
	cPackageName = aLocalPackageInfo[:remotefolder]
	cPackageInfo = GetPackageFile(cPackageName)
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
	# Check Update 	
		if aPackageInfo[:version] != aLocalPackageInfo[:version]
			return Style("New Update : (" + aPackageInfo[:version] + ")",:WhiteBlue)
		ok
	return "No Update!"

class ListOfFiles

	func ListAllFiles cPath,cExt
		if left(cExt,2) = "*."
			cExt = substr(cExt,3)
		ok
		aList = dir(cPath)
		return ListAllFiles_process(cPath,aList,cExt)
	
	func ListAllFiles_Process cPath,aList,cExt
		aOutput = []
		for aSub in aList 
			if aSub[1] = "." or aSub[1] = ".."
				loop
			ok
			if aSub[2] # Directory
				Try
					cNewPath = cPath + "/" + aSub[1]
					aSubOutput = listAllFiles(cNewPath,cExt)
					for item in aSubOutput 
						aOutput + item
					next
				Catch 
					# We use Try/Catch/Done
					# To Workaround a bug in Linux
					# when aSub[2] = True for files (not folders)
				Done 
			else		# File
				if cExt != NULL
					if right(aSub[1],len(cExt)+1) = "."+cExt 
						aOutput + ( cPath + "/" + aSub[1] )
					ok
				else
					aOutput + ( cPath + "/" + aSub[1] )
				ok
			ok
		next
		return aOutput
	
