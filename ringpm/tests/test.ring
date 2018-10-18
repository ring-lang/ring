/*
	Title :	The Ring Package Manager 
	Date  : 2018.10.18
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

/*
	What we need to test ?
	1 - The executable works ---> Print Copyright Message 
	2 - Installing (Different Packages)
	3 - Listing Packages 
	4 - Removing Packages 
	5 - Listing Packages after install 
	6 - Listing Packages after remove 
	.....
	We may need a lot tests!
*/

load "stdlibcore.ring"

C_MODE_UPDATETESTS	= 1
C_MODE_TESTING		= 2
C_CORRECT_FOLDER 	= "correct"
C_CURRENT_FOLDER	= "current"


nTestMode	=	 C_MODE_TESTING


cOutputFolder = "tests/"

switch nTestMode 
	on C_MODE_UPDATETESTS
		cOutputFolder += C_CORRECT_FOLDER
	on C_MODE_TESTING
		cOutputFolder += C_CURRENT_FOLDER
off

cDir = CurrentDir()
ChDir("../")
	System("ringpm.exe > "+cOutputFolder+"/test1.txt")
chDir(cDir)

if nTestMode = C_MODE_TESTING
	See "Test (1) --- " 
	cFileNameCorrect = C_CORRECT_FOLDER+"/test1.txt"
	cFileNameCurrent = C_CURRENT_FOLDER +"/test1.txt"
	if read(cFileNameCorrect) = read(cFileNameCurrent)
		? "PASS"
	else 
		? "FAIL"
	ok
ok
