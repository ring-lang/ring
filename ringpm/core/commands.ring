/*
	Title :	The Ring Package Manager 
	Date  : 2018.10.18
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

# Load Commands 
	load "../commands/install.ring"
	load "../commands/list.ring"
	load "../commands/remove.ring"
	load "../commands/update.ring"

func ExecuteCommands
	# Check if we don't have commands
		if len(aCommand) < 1 return ok
	# The command is not case-sensitive
		cCommand = lower(trim(aCommand[1]))
	# Execute Commands
		switch cCommand 
			on "install"				
				cPackageName = GetPackageNameFromParameters()
				if cPackageName = "" return ok
				InstallPackage(cPackageName)
			on "update"
				cPackageName = GetPackageNameFromParameters()
				if cPackageName = "" return ok
				UpdatePackage(cPackageName)				
			on "list"
				CheckFastList()
				PrintInstalledPackages()
			on "remove"
				cPackageName = aCommand[2]
				RemovePackage(cPackageName)
		off
	
func GetPackageNameFromParameters
	if len(aCommand) < 2 
		? C_ERROR_NOPACKAGENAME
		return ""
	ok 
	return aCommand[2]


func CheckFastList
	if find(aCommand,"-f") or find(aCommand,"-F")
		lCheckUpdates = False 
	ok
