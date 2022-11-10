/*------------------------------------------------------------------------------------
/	Name         : RING WIN APIs \Or/ WIN APIs FOR RING
/	Purpose      : Brings the power of WIN APIs easily into Ring Programming Language
/
/	Authors : 
/			1- Majdi Sobain <MajdiSobain@Gmail.com>
/			2- 
/
/						Copyright (c) 2016
/------------------------------------------------------------------------------------*/


LoadLib ("ring_winapi.dll")
Load "winapi.rh"



/*
Function Name : rShellExecuteResult
Func. Purpose : it is a good function to reveal the code returned by rShellExecute()
Func. Params  : ( RetID ) is the code that has been returned by rShellExecute() function
Func. Return  : a string containing the interpretation of the code returned by rShellExecute()
Func. Author  : Majdi Sobain <MajdiSobain@Gmail.com>
*/
Func rShellExecuteResult RetID
aList = [
	[0,  "Error  (0): The operating system is out of memory or resources"],
	[2,  "Error  (2): The specified file was not found"],
	[3,  "Error  (3): The specified path was not found"],
	[5,  "Error  (5): The operating system denied access to the specified file"],
	[6,  "Error  (6): Library required separate data segments for each task"],
	[8,  "Error  (8): There was not enough memory to complete the operation"],
	[10, "Error (10): Windows version was incorrect"],
	[11, "Error (11): The .exe file is invalid (non-Win32 .exe or error in .exe image)"],
	[12, "Error (12): Application was designed for a different operating system"],
	[13, "Error (13): Application was designed for MS-DOS 4.0"],
	[14, "Error (14): Type of executable file was unknown"],
	[15, "Error (15): Attempt was made to load a real-mode application (developed for an earlier version of Windows)"],
	[16, "Error (16): Attempt was made to load a second instance of an executable file containing multiple data segments that were not marked read-only"],
	[19, "Error (19): Attempt was made to load a compressed executable file. The file must be decompressed before it can be loaded"],
	[20, "Error (20): Dynamic-link library (DLL) file was invalid. One of the DLLs required to run this application was corrupt"],
	[21, "Error (21): Application requires Microsoft Windows 32-bit extensions"],
	[26, "Error (26): A sharing violation occurred"],
	[27, "Error (27): The file name association is incomplete or invalid"],
	[28, "Error (28): The DDE transaction could not be completed because the request timed out"],
	[29, "Error (29): The DDE transaction failed"],
	[30, "Error (30): The DDE transaction could not be completed because other DDE transactions were being processed"],
	[31, "Error (31): There is no application associated with the given file name extension. This error will also be returned if you attempt to print a file that is not printable"],
	[32, "Error (32): The specified DLL was not found"]
		]
If RetID > 32 
	Return "The Function Succeeded Perfectly (Returned Code " + RetID + ")"
OK
For L in aList
	If RetID = L[1] 
		Return L[2]
	Ok
Next
Return "Error (" + RetID + "): Unknown Error. Please Search internet about it like 'ShellExecute error (" + RetID + ")'"
	
	
	
