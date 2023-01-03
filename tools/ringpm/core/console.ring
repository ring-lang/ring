/*
	Title :	The Ring Package Manager 
	Date  : 2018.10.18
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

func Title
	# Don't display instruction if we have commands
		if len(aCommand) >= 1 return ok
	Line75()
	? "Ring Package Manager (RingPM)" 
	? "2018-2023, Mahmoud Fayed <msfclipper@yahoo.com>"
	Line75()

func Commands
	# Don't display instruction if we have commands
		if len(aCommand) >= 1 return ok
	  ? "Usage   : ringpm [command]"
	see "Command : " Style("search ",:YellowBlack)  see " [keywords...]" + nl
	see "Command : " Style("refresh",:YellowBlack)  see " : Update the Registry (Packages List)" + nl
	see "Command : " Style("install",:YellowBlack)  
	see " [ <packagename> [from <UserName>] [branch <branchname>] ]" + nl
	see "Command : " Style("list   ",:YellowBlack)  see " [-u : Check updates]" + nl
	see "Command : " Style("run    ",:YellowBlack)  see " [packagename]" + nl
	see "Command : " Style("update ",:YellowBlack)  see " <packagename>" + nl
	see "Command : " Style("remove ",:YellowBlack)  see " <packagename>" + nl
	see "Command : " Style("format ",:YellowBlack)  see " : Delete All Packages" + nl
	see "Command : " Style("new    ",:YellowBlack)  see " <packagename>" + nl
	see "Command : " Style("package",:YellowBlack)  see " : Create package in the current folder" + nl
	Line75()
	
