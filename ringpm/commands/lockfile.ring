/*
	Title :	The Ring Package Manager 
	Date  : 2018.10.26
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

func WriteLockFile aPackageInfo,oInstall
	cPackageName = aPackageInfo[:folder]
	cRemotePackageName = aPackageInfo[:remotefolder]
	cFolder = cMainPackagesFolder+"/"+cPackageName
	cLockFile = cFolder + "/lock.ring"
	# Create the Lock File List
		aLockFile = []
	# Add the current Package 
		aLockFile + [:name = cRemotePackageName, 
			     :branch = oInstall.cBranchName,
			     :version = aPackageInfo[:version],
			     :providerusername = aPackageInfo[:ProviderUserName]]
	# Get information from related packages 
		for aRelatedPackage in aPackageInfo[:libs]
			cSubPackageName = aRelatedPackage[:name]
			if cSubPackageName = NULL loop ok
			cSubLockFile = cMainPackagesFolder+"/"+cSubPackageName+GetMajorVersionText(aRelatedPackage[:version])+"/lock.ring"
			if ! fexists( cSubLockFile )
				? C_ERROR_LOCKFILEDOESNOTEXIST + " : " + cSubLockFile 
				return 
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
		new List2Code {
			write(cLockFile,"aLockInfo = " + list2code(aLockFile))
		}
