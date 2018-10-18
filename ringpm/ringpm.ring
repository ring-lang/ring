/*
	Title :	The Ring Package Manager 
	Date  : 2018.10.17
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

# Load Global Libraries 
	load "stdlibcore.ring"
	load "internetlib.ring"		# Download() Function

# Load Local Libraries 
	load "cuilib.ring"

# Load Application Files 
	load "globals.ring"
	load "console.ring"
	load "getpara.ring"
	load "commands.ring"

func Main 
	aCommand = GetParameters("ringpm")
	Title()
	Commands()	
	ExecuteCommands()
	
