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
load "globals.ring"
load "tests.ring"

SetTestingMode()
RunTests()

func RunTests()	
	nMax = len(aTests)
	? "Tests Count : " + nMax
	for x = 1 to nMax
		aTest = aTests[x]
		RunTest(x,aTest)
		ShowTestResult(x,aTest)
	next
	
func SetTestingMode
	switch nTestMode 
		on C_MODE_UPDATETESTS
			cOutputFolder += C_CORRECT_FOLDER
		on C_MODE_TESTING
			cOutputFolder += C_CURRENT_FOLDER
	off
	
func RunTest nIndex,aTest
	cDir = CurrentDir()
	ChDir("../")
		System(aTest[:Command]+" > "+cOutputFolder+
				"/test"+nIndex+".txt")
	chDir(cDir)

func ShowTestResult  nIndex,aTest
	if nTestMode = C_MODE_TESTING
		See "Test ("+nIndex+") : " + aTest[:Name] 
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
			? "PASS"
		else 
			? "FAIL"
		ok
	ok
	
