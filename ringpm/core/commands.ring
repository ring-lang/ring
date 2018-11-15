/*
	Title :	The Ring Package Manager 
	Date  : 2018.10.18
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

# Load Commands 
	load "common.ring"
	load "../commands/install.ring"
	load "../commands/installcommand.ring"
	load "../commands/lockfile.ring"
	load "../commands/list.ring"
	load "../commands/remove.ring"
	load "../commands/format.ring"
	load "../commands/update.ring"
	load "../commands/run.ring"
	load "../commands/new.ring"

func ExecuteCommands
	# Check if we don't have commands
		if len(aCommand) < 1 return ok
	# The command is not case-sensitive
		cCommand = lower(trim(aCommand[1]))
	# Execute Commands
		switch cCommand 
			on "install"				
				cPackageName = GetPackageNameFromParameters()
				if cPackageName = "" ? C_ERROR_NOPACKAGENAME return ok
				oInstall = new InstallCommand
				oInstall.SetBranchFromCommandLine()
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
				if cPackageName = "" ? C_ERROR_NOPACKAGENAME return ok
				RunPackage(cPackageName)
			on "new"
				cPackageName = GetPackageNameFromParameters()
				if cPackageName = "" ? C_ERROR_NOPACKAGENAME return ok
				NewPackage(cPackageName)
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
