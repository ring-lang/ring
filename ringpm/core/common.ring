/*
	Title :	The Ring Package Manager 
	Date  : 2018.11.02
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

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
