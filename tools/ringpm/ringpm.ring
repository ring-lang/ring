/*
	Title :	The Ring Package Manager 
	Date  : 2018.10.17
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

# Load Global Libraries 
	load "stdlibcore.ring"
	load "internetlib.ring"		# Download() Function
	load "consolecolors.ring"
	
# Load Local Libraries 
	load "cuilib/cuilib.ring"

# Load Application Files 
	load "core/core.ring"

func Main 
	aCommand = GetParameters("ringpm")
	oAllPackagesInfo.LoadInfo()
	cDir = CurrentDir()
	Title()
	Commands()	
	ExecuteCommands()
	chdir(cDir)
	oAllPackagesInfo.SaveInfo()
