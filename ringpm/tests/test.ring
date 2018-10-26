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
	We may need a lot of tests!
*/

# Load Global Libraries
	load "stdlibcore.ring"
	load "consolecolors.ring"

# Load Local Libraries 
	load "../cuilib/cuilib.ring"

# Load Files
	load "globals.ring"
	load "tests.ring"
	load "../core/getpara.ring"

SelectMode()
SetTestingMode()
RunTests()

func SelectMode
	aCommand = GetParameters("test")
	if len(aCommand) >= 1
		cCommand = lower(trim(aCommand[1]))
		switch cCommand 
			on "test"
				nTestMode = C_MODE_TESTING
			on "update"
				nTestMode = C_MODE_UPDATETESTS
		off
	ok

func RunTests()	
	nMax = len(aTests)
	line()
	? "Tests Count : " + nMax
	line()
	for x = 1 to nMax
		aTest = aTests[x]
		RunTest(x,aTest)
		ShowTestResult(x,aTest)		
	next
	? nl line()	

func SetTestingMode
	switch nTestMode 
		on C_MODE_UPDATETESTS
			cOutputFolder += C_CORRECT_FOLDER
		on C_MODE_TESTING
			cOutputFolder += C_CURRENT_FOLDER
	off
	
func RunTest nIndex,aTest
	See nl + Width("Test ("+nIndex+") ",11) + " : " + 
		 Width(aTest[:Name],65)
	cDir = CurrentDir()
	ChDir("../")
		System(aTest[:Command]+" > "+cOutputFolder+
				"/test"+nIndex+".txt")
	chDir(cDir)

func ShowTestResult  nIndex,aTest
	if nTestMode = C_MODE_TESTING
		cFileNameCorrect = C_CORRECT_FOLDER+"/test"+nIndex+".txt"
		cFileNameCurrent = C_CURRENT_FOLDER +"/test"+nIndex+".txt"
		if ! fexists(cFileNameCorrect)
			? ""
			? C_ERROR_FILEDOESNOTEXIST + " - File Name : " +
					 cFileNameCorrect 
			return 
		ok
		see " --- " 
		if read(cFileNameCorrect) = read(cFileNameCurrent)
			style("PASS",:YellowBlack)
		else 
			style("FAIL",:WhiteBlue)
		ok
	ok

