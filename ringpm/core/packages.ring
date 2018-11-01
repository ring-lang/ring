/*
	Title :	The Ring Package Manager 
	Date  : 2018.10.18
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

C_ALLPACKAGESINFO_PACKAGENAME = 1
C_ALLPACKAGESINFO_RELATED     = 2

class AllPackagesInfo

	cAllPackagesFile = "allpackages.ring"
	
	aAllPackagesInfo = [
		# [ Package Name , [ List of packages that use this package ] ]
	]
	
	func LoadInfo 
		if ! fexists(cAllPackagesFile) SaveInfo() return ok
		cAllPackagesInfo = read(cAllPackagesFile)
		eval(cAllPackagesInfo)
	
	func AddPackage  cPackageName 
		if find(aAllPackagesInfo,cPackageName,1) return ok
		aAllPackagesInfo + [ cPackageName , [] ]
	
	func AddRelatedPackage cPackageName,cRelatedPackageName
		# Second Package ----> First Package 
		# AddRelatedPackage(:FirstPackage,:SecondPackage)
		AddPackage(cPackageName)
		nPos = find(aAllPackagesInfo,cPackageName,1)
		# Add the related package
			if ! find(aAllPackagesInfo[nPos][C_ALLPACKAGESINFO_RELATED],cRelatedPackageName)
				aAllPackagesInfo[nPos][C_ALLPACKAGESINFO_RELATED] + cRelatedPackageName
			ok
	
	func SaveInfo
		write(cAllPackagesFile,
		"aAllPackagesInfo = " + List2Code(aAllPackagesInfo))

	func CheckRelatedPackages cPackageName 
		AddPackage(cPackageName)
		nPos = find(aAllPackagesInfo,cPackageName,1)
		return aAllPackagesInfo[nPos][C_ALLPACKAGESINFO_RELATED]

	func RemovePackage cPackageName 
		for t=1 to len(aAllPackagesInfo)
			aPackage = aAllPackagesInfo[t]
			for x = len(aPackage[C_ALLPACKAGESINFO_RELATED]) to 1 step -1 
				if aPackage[C_ALLPACKAGESINFO_RELATED][x] = cPackageName 
					del(aAllPackagesInfo[t][C_ALLPACKAGESINFO_RELATED],x)
				ok
			next 
		next 

	func DeleteAllPackagesFile 
		remove(cAllPackagesFile)
