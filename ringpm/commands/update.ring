/*
	Title :	The Ring Package Manager 
	Date  : 2018.10.22
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

func UpdatePackage cPackageName
	cLocalPackageFileName = "packages/"+cPackageName+"/package.ring"
	# Check if we don't have the package ---> Return 
		if not fexists(cLocalPackageFileName)
			? C_ERROR_WEDONTHAVETHISPACKAGE
			? "Package Name : " + cPackageName
			return 
		ok
	# Get Package File (Local & Remote) ---> Compare 
		cLocalPackageFile  = read(cLocalPackageFileName)
		eval(cLocalPackageFile)
		cLocalVersion  = aPackageInfo[:version]
		cRemotePackageFile = GetPackageFile(cPackageName,aPackageInfo[:branch])
		if cRemotePackageFile = "" return ok
		eval(cRemotePackageFile)
		cRemoteVersion = aPackageInfo[:version]
	
	# Check if no updates (---> Return)
		if cLocalVersion = cRemoteVersion
			? C_ERROR_NOUPDATES 
			? "Package Name : " + cPackageName
			return
		ok
	# Install Update 
		Style("Update ",:YellowBlack) ? cPackageName
		GetPackage(cPackageName)
