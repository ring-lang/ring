/*
	Title :	The Ring Package Manager 
	Date  : 2018.10.18
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

func Title
	# Don't display instruction if we have commands
		if len(aCommand) >= 1 return ok
	Line70()
	? "Ring Package Manager (RingPM)" 
	? "2018, Mahmoud Fayed <msfclipper@yahoo.com>"
	Line70()

func Commands
	# Don't display instruction if we have commands
		if len(aCommand) >= 1 return ok
	see "Usage   : " Style("ringpm ",:YellowBlack)  see " <command>"     + nl
	see "Command : " Style("install",:YellowBlack)  see " <packagename>" + nl
	see "Command : " Style("update ",:YellowBlack)  see " <packagename>" + nl
	see "Command : " Style("remove ",:YellowBlack)  see " <packagename>" + nl
	see "Command : " Style("list   ",:YellowBlack)  see " [-f : Don't check updates]" + nl
	line70()
	
