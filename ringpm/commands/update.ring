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
		cRemotePackageFile = GetPackageFile(cPackageName)
		if cRemotePackageFile = "" return ok
		cLocalPackageFile  = read(cLocalPackageFileName)
		eval(cRemotePackageFile)
		cRemoteVersion = aPackageInfo[:version]
		eval(cLocalPackageFile)
		cLocalVersion  = aPackageInfo[:version]
	# Check if no updates (---> Return)
		if cLocalVersion = cRemoteVersion
			? C_ERROR_NOUPDATES 
			? "Package Name : " + cPackageName
			return
		ok
	# Install Update 
		? "Update Package : " + cPackageName
		GetPackage(cPackageName)
