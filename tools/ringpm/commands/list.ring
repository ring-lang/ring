/*
	Title :	The Ring Package Manager 
	Date  : 2018.10.18
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

func PrintInstalledPackages
	# Get Files
		Try
			new ListOfFiles {
				aFiles	= ListAllFiles(cMainPackagesFolder,"ring")
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
			see Style(Width("("+aPackageInfo[:folder]+") ",30),:YellowBlack)+": " +
				 Width(aPackageInfo[:name] + " [" + aPackageInfo[:branch] + "]",50) +
				 " -- " +
				Width("("+aPackageInfo[:version]+ ")",15) 
				if lCheckUpdates 
					see  " -- "  
					See CheckUpdates(aPackageInfo) 
				ok
				see nl
		next 
	# Print Packages Count 
		if len(aPackagesInfoFiles) != 0
			? nl + "Packages Count : " + len(aPackagesInfoFiles)
		ok
	# Print message if we don't have packages 
		if len(aPackagesInfoFiles) = 0
			? "No installed packages!"
		ok

func CheckUpdates aLocalPackageInfo
	cPackageName = aLocalPackageInfo[:remotefolder]
	cBranchName = aLocalPackageInfo[:branch]
	cProviderUserName = aLocalPackageInfo[:ProviderUserName] 
	cProviderWebsite  = aLocalPackageInfo[:ProviderWebsite]
	cPackageInfo = GetPackageFile(cPackageName,cBranchName,cProviderUserName,cProviderWebsite)
	if cPackageInfo = "" ? C_ERROR_PACKAGENOTFOUND return ok
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
			if IsCompatible(aLocalPackageInfo[:Version],aPackageInfo[:Version])
				cColor = :WhiteBlue
			else 
				cColor = :WhiteRed
			ok
			return Style("New Update : (" + aPackageInfo[:version] + ")",cColor)
		ok
	return "No Update!"
