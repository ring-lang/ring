/*
	Title :	The Ring Package Manager 
	Date  : 2018.10.26
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

class InstallCommand

	cPackageURL 	= ""
	cBranchName 	= "master"
	cPackageVersion = ""
	lUpdate	    	= False

	# Where we have our package 
		lLocalPackages	   = True 
		cPackagesLocations = exefolder()+"../tools/ringpm/local"
	
	cProviderUserName = ""
	cProviderWebsite  = "github.com"

	func InstallFrom cUserName 
		if cUserName = NULL return ok
		lLocalPackages	   = False
		cPackagesLocations = C_GITHUBUSERCONTENT + cUserName
		cProviderUserName  = cUserName

	func InstallPackage cPackageName
		if lUpdate = False
			Style("Installing ",:YellowBlack) 
		else 
			Style("Updating ",:YellowBlack) 
		ok
		see Width(cPackageName + " (" + cBranchName + ")" , 10)
		GetPackage(cPackageName)

	func GetPackage cPackageName
		cPackageInfo = GetPackageFile(cPackageName)
		aCheck = CheckPackageFile(cPackageInfo)
		# Support installing from the Registry (To download packages from the Internet)
			# When we install from registry, We will not find the package file in local folders
			# And the lInstallError flag will be True, So we set it to False 
				lInstallError = False
			if ! aCheck[1] 
				if lLocalPackages = True 
					lInstallError = ! InstallFromRegistry(cPackageName)
					if lInstallError = True 
						? nl+C_ERROR_PACKAGENOTFOUND
					ok
				ok
				return 
			ok
		aPackageInfo = aCheck[2]
		DisplayPackageInformation(aPackageInfo)
		# Check that we have the required Ring version
			if ! CheckRingVersion(aPackageInfo) 
				? C_ERROR_BADRINGVERSION			
				? "Current  Ring Version : " + version()
				? "Required Ring Version : " + aPackageInfo[:ringversion]
				lInstallError 	= True
	 			return 
			ok
		# Check Package Version 
			if cPackageVersion != NULL 
				if not IsCompatible(cPackageVersion,aPackageInfo[:version])
					? nl + C_NOTE_PACKAGEVERSIONISNOTCOMPATIBLE
					? "Package  Version : " + aPackageInfo[:version]
					? "Required Version : " + cPackageVersion
					if cBranchName = "master"
						? "Searching for a compatible version"
						if isList(aPackageInfo[:versions])
							for aVersion in aPackageInfo[:versions]
								if IsCompatible(cPackageVersion,aVersion[:Version])
									if aVersion[:Branch] != "master"
										cBranchName 	= aVersion[:Branch]
										? "Found .. version : " + aVersion[:Version] +
										   " .. Using Branch : " + aVersion[:Branch]
										InstallPackage(cPackageName)
							 			return 
									ok
								ok
							next 
						ok
						? "Not Found! Contact the package creator for support!"
					ok
					lInstallError 	= True
		 			return 
				ok
			ok
		cPackageFolderName = GetPackageFolderName(aPackageInfo)
		see " ---> " + cPackageFolderName + nl
		# If we have the package ---> Return (Don't install it)
			if lUpdate = False
				if fexists(cMainPackagesFolder+"/"+cPackageFolderName+"/package.ring")
					? " - " + C_NOTE_PACKAGEALREADYEXISTS
					# Check Update 
						if CheckPackageUpdate(cPackageFolderName) = True 
							UpdatePackage(cPackageFolderName)
						ok
					return 
				ok
			ok
		DownloadRelatedPackages(aPackageInfo,True)
		if ! lInstallError 
			if lDisplayPackageFiles
				Style("Download Package Files For ",:YellowBlack)  ? cPackageName
			ok
			DownloadPackageFiles(aPackageInfo,cPackageInfo)
		else 
			? "Install Operation (Not Completed)"
			return 
		ok
		WriteLockFile(aPackageInfo,self)
		# Create file for loading the package in ring/bin folder 
			if find(aPackageInfo[:files],"lib.ring")
				cCompletePackageName = cPackageName+GetMajorVersionText(aPackageInfo[:version])
				write(exefolder()+cCompletePackageName+".ring",
					'load "'+cMainPackagesFolder+'/'+cCompletePackageName+'/lib.ring"')
			ok
		SetupPackage(cPackageName,cPackageFolderName,aPackageInfo)

	func SetupPackage cPackageName,cPackageFolderName,aPackageInfo
		cSetup = aPackageInfo[:setup]
		if cSetup != NULL or aPackageInfo[:WindowsSetup] != NULL or 
			aPackageInfo[:LinuxSetup] != NULL or aPackageInfo[:MacOSSetup] != NULL 
			Style("Preparing ",:YellowBlack)
			? cPackageName
			cDir = CurrentDir()
			chdir(cMainPackagesFolder+"/"+cPackageFolderName)
			system(cSetup)
			if isWindows() and aPackageInfo[:WindowsSetup] != NULL 
				System(aPackageInfo[:WindowsSetup])
			but isLinux()
				if aPackageInfo[:LinuxSetup] != NULL 
					System(aPackageInfo[:LinuxSetup])
				ok
				if fexists(exefolder()+"/ubuntu.txt") and aPackageInfo[:UbuntuSetup] != NULL 
					System(aPackageInfo[:UbuntuSetup])
				but fexists(exefolder()+"/fedora.txt") and aPackageInfo[:FedoraSetup] != NULL 
					System(aPackageInfo[:FedoraSetup])
				ok
			but isMacosx() and aPackageInfo[:MacOSSetup] != NULL 
				System(aPackageInfo[:MacOSSetup])
			ok
			chdir(cDir)
		ok

	func GetPackageFile cPackageName
		if lLocalPackages
			cPackageURL  	= cPackagesLocations + "/" + cPackageName + "/"
			cDir = CurrentDir()
				chdir(cPackageURL)				
				if fexists("package.ring")	# Be sure that we have a Package
					# Select the Correct Branch 
					SystemSilent("git checkout " + cBranchName + " --quiet")
				ok
			chdir(cDir)
		else 
			cPackageURL  	= cPackagesLocations + "/" + cPackageName +
						 C_BRANCHSEPARATOR+cBranchName+"/"
		ok
		cPackageFileURL = cPackageURL + "package.ring"
		cPackageInfo 	= DownloadFile(cPackageFileURL)
		# We are using local packages, and the package doesn't exist
			if cPackageInfo = "" return ok
		if substr(cPackageInfo,"404") 
			see nl
			? C_ERROR_CANTDOWNLOADTHEPACKAGEFILE
			? "File URL : " + cPackageFileURL
			cPackageInfo = ""
			lInstallError 	= True
		ok
		return cPackageInfo
	
	func DisplayPackageInformation aPackageInfo
		if lDisplayPackageInfo = False return ok
		? "Package Name         : " + aPackageInfo[:name]
		? "Package Description  : " + aPackageInfo[:Description]
		? "Package Developer    : " + aPackageInfo[:developer]
		? "Package License      : " + aPackageInfo[:license]
	
	func DownloadRelatedPackages aPackageInfo,lAllPackages
		cFolder = GetPackageFolderName(aPackageInfo) 
		for x = 1 to len(aPackageInfo[:libs])
			aRelatedPackage = aPackageInfo[:libs][x]
			if aRelatedPackage[:name] = NULL loop ok
			oInstall = new InstallCommand
			cRelatedPackageName = aRelatedPackage[:name]
			# Support installing from different branches 
				if aRelatedPackage[:branch] != NULL 
					oInstall.cBranchName 	 = aRelatedPackage[:branch]
					cRelatedPackageName += aRelatedPackage[:branch]
				ok
				if aRelatedPackage[:ProviderWebsite] != NULL 
					oInstall.cProviderWebsite = aRelatedPackage[:ProviderWebsite]
				else 
					oInstall.cProviderWebsite = cProviderWebsite
				ok
				if aRelatedPackage[:ProviderUserName] != NULL 
					oInstall.InstallFrom(aRelatedPackage[:ProviderUserName])
				else 
					oInstall.InstallFrom(cProviderUserName)
				ok
			oInstall.cPackageVersion = aRelatedPackage[:version]
			oInstall.lUpdate = False
			oInstall.InstallPackage(aRelatedPackage[:name])
			if lAllPackages
				oAllPackagesInfo.AddRelatedPackage(
					cRelatedPackageName+GetMajorVersionText(aRelatedPackage[:version]),
					cFolder
				)
			ok
		next

	func DownloadPackageFiles aPackageInfo,cPackageInfo
		cCurrentDir = CurrentDir()
		# Create the package folder
			chdir(cMainPackagesFolder)
			OSCreateOpenFolder(GetPackageFolderName(aPackageInfo))
		# Write the Package File
			cPackageInfo = UpdateFolderName(aPackageInfo) 	
			write("package.ring",cPackageInfo)
		# Download package files 
		lWriteError = False
		DownloadListOfFiles(aPackageInfo,:Files)
		DownloadListOfFilesInRingFolder(aPackageInfo,:RingFolderFiles)
		if isWindows()
			DownloadListOfFiles(aPackageInfo,:WindowsFiles)
			DownloadListOfFilesInRingFolder(aPackageInfo,:WindowsRingFolderFiles)
		but isLinux()
			DownloadListOfFiles(aPackageInfo,:LinuxFiles)
			DownloadListOfFilesInRingFolder(aPackageInfo,:LinuxRingFolderFiles)
			if fexists(exefolder()+"/ubuntu.txt")
				DownloadListOfFiles(aPackageInfo,:UbuntuFiles)
				DownloadListOfFilesInRingFolder(aPackageInfo,:UbuntuRingFolderFiles)
			but fexists(exefolder()+"/fedora.txt")
				DownloadListOfFiles(aPackageInfo,:FedoraFiles)
				DownloadListOfFilesInRingFolder(aPackageInfo,:FedoraRingFolderFiles)
			ok
		but isMacOSX()
			DownloadListOfFiles(aPackageInfo,:MacOSFiles)
			DownloadListOfFilesInRingFolder(aPackageInfo,:MacOSRingFolderFiles)
		ok
		if ! lWriteError
			DisplayOperationDone()
		ok
		chdir(cCurrentDir)

	func DownloadListOfFilesInRingFolder aPackageInfo,cAttribute
		cCurrentPackageDir = CurrentDir()
		# Download Files in the Ring Folder (Not the package folder)
			chdir(exefolder()+"/../")
			DownloadListOfFiles(aPackageInfo,cAttribute)
		chdir(cCurrentPackageDir)

	func DownloadListOfFiles aPackageInfo,cAttribute
		for cFileName in aPackageInfo[cAttribute]
			DownloadFileInPackage(cFileName)
		next

	func DownloadFileInPackage cFileName
		if lDisplayPackageFiles
			Style("Download File : ",:YellowBlack) ? cFileName 
		ok
		cFileURL 	= cPackageURL + cFileName
		cFileContent 	= DownloadFile(cFileURL)
		if lInstallError = True 
			? nl+"Can't download the file : " + cFileURL
			loop
		ok
		cDir  = CurrentDir()
		CreateSubFolders(cFileName)
		chdir(cDir)
		if isWindows() and Right(cFileName,5) = ".ring" 
			cFileContent = substr(cFileContent,nl,WindowsNL())
		ok
		Try
			write(cFileName,cFileContent)
		Catch
			? C_ERROR_CANTWRITETHEFILE 
			? "File Name : " + cFileName 
			lWriteError = True
		Done 

	func SetBranchFromCommandLine
		nPos = find(aCommand,"branch")
		if ! nPos return ok
		if len(aCommand) > nPos 	# We have branch name 
			cBranchName = aCommand[nPos+1]	
		else 
			? C_ERROR_BRANCHNAMEISMISSING
			lInstallError 	= True
		ok

	func SetUserNameFromCommandLine
		nPos = find(aCommand,"from")
		if ! nPos return ok
		if len(aCommand) > nPos 	# We have User Name 
			cUserName = aCommand[nPos+1]	
			InstallFrom(cUserName)
		else 
			? C_ERROR_USERNAMEISMISSING
			lInstallError 	= True
		ok

	func GetPackageFolderName aPackageInfo
		return aPackageInfo[:folder] + GetMajorVersionText(aPackageInfo[:Version])

	func UpdateFolderName aPackageInfo
		aPackageInfo[:remotefolder] = aPackageInfo[:folder]
		aPackageInfo[:folder] = GetPackageFolderName(aPackageInfo)
		aPackageInfo[:branch] = cBranchName
		aPackageInfo[:ProviderUserName] = cProviderUserName
		aPackageInfo[:ProviderWebsite] = cProviderWebsite
		new List2Code {
			cPackageInfo = "aPackageInfo = " + List2Code(aPackageInfo)
		}
		return cPackageInfo

	func InstallPackageFromCurrentFolder
		? "Get Package Information"
		cPackageInfo = read("package.ring")
		aCheck = CheckPackageFile(cPackageInfo)
		if ! aCheck[1] lInstallError = True return ok
		aPackageInfo = aCheck[2]
		? "Install Dependencies"
		DownloadRelatedPackages(aPackageInfo,False)
		DisplayOperationDone()

	func DownloadFile cURL
		if lLocalPackages 
			if isWindows()
				cURL = substr(cURL,"/","\")
			ok
			if ! fexists(cURL)
				lInstallError 	= True
				return 
			ok
			return Read(cURL)
		ok
		return Download(AddTimeStamp(cURL))


	func InstallFromRegistry cPackageName 
		eval(read(C_REGISTRYFILE))
		# Now we have aPackagesRegistry
		for aPackage in aPackagesRegistry	
			if aPackage[:name] = cPackageName
				# Install from registry 
					oInstall = new InstallCommand 
					oInstall.InstallFrom(aPackage[:ProviderUserName])
					oInstall.GetPackage(cPackageName)									
				return True
			ok
		next   	
		return False
