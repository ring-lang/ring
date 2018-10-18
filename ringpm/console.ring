/*
	Title :	The Ring Package Manager 
	Date  : 2018.10.18
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

func Title
	# Don't display instruction if we have commands
		if len(aCommand) >= 1 return ok
	Line()
	? "Ring Package Manager (RingPM)" 
	? "2018, Mahmoud Fayed <msfclipper@yahoo.com>"
	Line()

func Line
	? copy("=",70)

func Commands
	# Don't display instruction if we have commands
		if len(aCommand) >= 1 return ok
	? "Usage   : ringpm  <command>"
	? "Command : install <packagename>"
	? "Command : remove  <packagename>"
	? "Command : list"
	
