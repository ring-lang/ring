/*
	Title :	The Ring Package Manager 
	Date  : 2018.10.22
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

func UpdatePackage cPackageName
	# Get Branch Name
		cLocalPackageFile  = GetLocalPackageFile(cPackageName)
		if cLocalPackageFile = NULL return ok
		eval(cLocalPackageFile)
		cBranchName = aPackageInfo[:branch]
		cProviderUserName = aPackageInfo[:ProviderUserName]
		cProviderWebsite  = aPackageInfo[:ProviderWebsite]
	# Check if no updates (---> Return)
		if CheckPackageUpdate(cPackageName) = False 
			? C_ERROR_NOUPDATES 
			? "Package Name : " + cPackageName
			return
		ok
	# Install Update 
		Style("Updating ",:YellowBlack) see cPackageName
		GetPackage(aPackageInfo[:remotefolder],cBranchName,
				cProviderUserName,cProviderWebsite,
				True) # True = Update Operation (Not Install)

func CheckPackageUpdate cPackageName
	# Get Package File (Local & Remote) ---> Compare 
		cLocalPackageFile  = GetLocalPackageFile(cPackageName)
		if cLocalPackageFile = NULL return False ok
		eval(cLocalPackageFile)
		cLocalVersion  = aPackageInfo[:version]
		cBranchName = aPackageInfo[:branch]
		# Remove branch name from package name 
			cPackageName = RemoveBranchNameFromPackageName(aPackageInfo,cPackageName,cBranchName)
		cRemotePackageFile = GetPackageFile(cPackageName,aPackageInfo[:branch],
						aPackageInfo[:ProviderUserName],
						aPackageInfo[:ProviderWebsite])
		if cRemotePackageFile = "" ? C_ERROR_PACKAGENOTFOUND return False ok		
		eval(cRemotePackageFile)
		cRemoteVersion = aPackageInfo[:version]
	# Check if no updates (---> Return)
		if cLocalVersion = cRemoteVersion
			return False
		ok
	return True

func RemoveBranchNameFromPackageName aPackageInfo,cPackageName,cBranchName 
	if cBranchName = NULL or cBranchName = "master"
		cBranchName = GetMajorVersionText(aPackageInfo[:Version])
	ok
	if cBranchName != NULL and cBranchName != "master"
		if len(cPackageName) > len(cBranchName)
			# If we have version like 0.1.0 it must be part of the package name 
			# But we check also if this is not the case (like manual decreasing of package version)
			if substr(cPackageName,cBranchName)
				cPackageName = left(cPackageName,len(cPackageName)- len(cBranchName))
			ok
		ok
	ok
	return cPackageName
