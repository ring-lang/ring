/*
	Title :	The Ring Package Manager 
	Date  : 2018.10.26
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

func WriteLockFile aPackageInfo,oInstall
	cPackageName = aPackageInfo[:folder]
	cFolder = "packages/"+cPackageName
	cLockFile = cFolder + "/lock.ring"
	# Create the Lock File List
		aLockFile = []
	# Add the current Package 
		aLockFile + [:name = cPackageName, :version = aPackageInfo[:version]]
	# Get information from related packages 
		for aRelatedPackage in aPackageInfo[:libs]
			cSubPackageName = aRelatedPackage[:name]
			if aRelatedPackage[:branch] = NULL
				cSubLockFile = "packages/"+cSubPackageName+"/lock.ring"
			else 
				cSubLockFile = "packages/"+cSubPackageName+aRelatedPackage[:branch]+"/lock.ring"
			ok
			eval(read(cSubLockFile))
			for aSubPackage in aLockInfo
				# Don't repeat the Packages 
					for aPackageInLock in aLockFile
						if aPackageInLock[:name] = aSubPackage[:name] and 
						   aPackageInLock[:version] = aSubPackage[:version] 
							loop 2
						ok 
					next 
				aLockFile + aSubPackage 
			next
		next	
	# Write the Lock File
		write(cLockFile,"aLockInfo = " + list2code(aLockFile))
