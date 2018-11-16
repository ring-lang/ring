/*
	Title :	The Ring Package Manager 
	Date  : 2018.11.02
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

func GetPackageFile cPackageName,cBranchName
	oInstall = new InstallCommand 
	if cBranchName != NULL
		oInstall.cBranchName = cBranchName
	ok
	return oInstall.GetPackageFile(cPackageName)

func GetPackage cPackageName,cBranchName,lUpdate
	oInstall = new InstallCommand 
	oInstall.cBranchName = cBranchName
	oInstall.lUpdate = lUpdate
	return oInstall.GetPackage(cPackageName)

func GetLocalPackageFile cPackageName
	cLocalPackageFileName = cMainPackagesFolder+"/"+cPackageName+"/package.ring"
	# Check if we don't have the package ---> Return 
		if not fexists(cLocalPackageFileName)
			? C_ERROR_WEDONTHAVETHISPACKAGE
			? "Package Name : " + cPackageName
			return 
		ok
	return read(cLocalPackageFileName)

func CheckPackageFile cPackageInfo
	if cPackageInfo = "" return [False,[]] ok
	try
		eval( cPackageInfo )
	catch
		see nl
		? C_ERROR_PACKAGEINFOISNOTCORRECT
		? cPackageInfo
		return [False,[]]
	done 
	if ! islocal(:aPackageInfo)
		? C_ERROR_NOPACKAGEINFO
		return [False,[]]
	ok
	return [True,aPackageInfo]

func DisplayOperationDone
	if lDisplayOperationDone
		? "Operation done!"
	ok
