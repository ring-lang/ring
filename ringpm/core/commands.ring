/*
	Title :	The Ring Package Manager 
	Date  : 2018.10.18
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

# Load Commands 
	load "common.ring"
	load "../commands/install.ring"
	load "../commands/lockfile.ring"
	load "../commands/list.ring"
	load "../commands/remove.ring"
	load "../commands/format.ring"
	load "../commands/update.ring"
	load "../commands/run.ring"
	load "../commands/new.ring"
	load "../commands/search.ring"

func ExecuteCommands
	# Check if we don't have commands
		if len(aCommand) < 1 return ok
	# The command is not case-sensitive
		cCommand = lower(trim(aCommand[1]))
	# Execute Commands
		switch cCommand 
			on "install"				
				cPackageName = GetPackageNameFromParameters()
				if cPackageName = "" 
					if fexists("package.ring")
						oInstall = new InstallCommand
						oInstall.InstallPackageFromCurrentFolder()
					else 
						? C_ERROR_NOPACKAGENAME 
					ok
					return 
				ok
				oInstall = new InstallCommand
				oInstall.SetBranchFromCommandLine()
				if lInstallError return ok
				oInstall.SetUserNameFromCommandLine()
				if lInstallError return ok
				oInstall.InstallPackage(cPackageName)
			on "update"
				cPackageName = GetPackageNameFromParameters()
				if cPackageName = "" ? C_ERROR_NOPACKAGENAME return ok
				UpdatePackage(cPackageName)				
			on "list"
				CheckFastList()
				PrintInstalledPackages()
			on "remove"
				cPackageName = GetPackageNameFromParameters()
				if cPackageName = "" ? C_ERROR_NOPACKAGENAME return ok
				RemovePackage(cPackageName)
			on "format"
				DeleteAllPackages()
			on "run"
				cPackageName = GetPackageNameFromParameters()
				if cPackageName = "" 
					if fexists("package.ring")
						RunCurrentPackage()
					else 
						? C_ERROR_NOPACKAGENAME 
					ok
					return 
				ok
				RunPackage(cPackageName)
			on "new"
				cPackageName = GetPackageNameFromParameters()
				if cPackageName = "" ? C_ERROR_NOPACKAGENAME return ok
				NewPackage(cPackageName)
			on "search"
				aKeywords = GetKeywordsFromParameters()
				if len(aKeywords) = 0 ? C_ERROR_NOKEYWORDS return ok
				Search(aKeywords)
		off
	
func GetPackageNameFromParameters
	if len(aCommand) < 2 
		return ""
	ok 
	return aCommand[2]


func CheckFastList
	if find(aCommand,"-f") or find(aCommand,"-F")
		lCheckUpdates = False 
	ok


func GetKeywordsFromParameters
	aKeywords = []
	if len(aCommand) >= 2 
		for x = 2 to len(aCommand)
			aKeywords + aCommand[x]
		next 
	ok 
	return aKeywords
