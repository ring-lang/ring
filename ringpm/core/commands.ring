/*
	Title :	The Ring Package Manager 
	Date  : 2018.10.18
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

# Load Commands 
	load "../commands/install.ring"
	load "../commands/list.ring"
	load "../commands/remove.ring"

func ExecuteCommands
	# Check if we don't have commands
		if len(aCommand) < 1 return ok
	# The command is not case-sensitive
		cCommand = lower(trim(aCommand[1]))
	# Execute Commands
		switch cCommand 
			on "install"
				if len(aCommand) < 2 
					? C_ERROR_NOPACKAGENAME
					return 
				ok 
				cPackageName = aCommand[2]
				InstallPackage(cPackageName)
			on "list"
				PrintInstalledPackages()
			on "remove"
				cPackageName = aCommand[2]
				RemovePackage(cPackageName)
		off
	



