/*
	Ring programming language - Test.ring
	2018-2023, Mahmoud Fayed
*/


# Load Global Libraries
	load "stdlibcore.ring"
	load "consolecolors.ring"

# Load Local Libraries 
	load "cuilib.ring"

# Load Files
	load "globals.ring"
	eval('load "tests.ring"')
	load "getpara.ring"

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
		if isNumber(aTest[:Condition])
			if not aTest[:Condition]
				See nl + Width("Test ("+x+") ",11) + " : " + 
				Width(aTest[:Name],65)
				see " --- "
				style("IGNORE",:BlackYellow)
				nIgnoreCount++
				loop
			ok
		ok
		RunTest(x,aTest)
		ShowTestResult(x,aTest)		
	next
	if nFailCount = 0
		ReportColor = :BlackYellow
	else
		ReportColor = :WhiteBlue
	ok
	? nl line()	
	style(Width(" The Report Summary ",90), :BlackWhite)  			? ""
	line()	
	style(Width(" Tests Count : " + nMax,90)	, ReportColor)  ? ""
	style(Width(" PASS        : " + nPassCount,90)	, ReportColor)  ? ""
	style(Width(" FAIL        : " + nFailCount,90)	, ReportColor)  ? ""
	style(Width(" IGNORE      : " + nIgnoreCount,90), ReportColor)  ? ""
	line()


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
	chDir("scripts")
		cCurrentFileName = cOutputFolder+"/"+GetOutputFile(nIndex)
		remove(cCurrentFileName)
		System(aTest[:Command]+" > " + cCurrentFileName)
	chDir(cDir)

func ShowTestResult  nIndex,aTest
	if nTestMode = C_MODE_TESTING
		cCorrectFileName = C_CORRECT_FOLDER+"/"+GetOutputFile(nIndex)
		cCurrentFileName = C_CURRENT_FOLDER +"/"+GetOutputFile(nIndex)
		if ! fexists(cCorrectFileName)
			? ""
			? C_ERROR_FILEDOESNOTEXIST + " - File Name : " +
					 cCorrectFileName 
			return 
		ok
		see " --- " 
		if substr(read(cCorrectFileName),windowsnl(),nl) = substr(read(cCurrentFileName),windowsnl(),nl)
			style("PASS",:YellowBlack)
			nPassCount++
		else 
			style("FAIL",:WhiteBlue)
			DisplayFileName(aTest)
			nFailCount++
		ok
	ok

func DisplayFileName aTest
	cCommand = aTest[:command]
	cCommand = substr(cCommand,"ring ","")
	for cChar in ["<",">"]
		nPos = substr(cCommand,cChar)
		if nPos
			cCommand = left(cCommand,nPos-1)
		ok
	next
	cCommand = JustFileName(cCommand)
	see " (" + cCommand + ")"

func GetOutputFile nIndex
	cName = aTests[nIndex][:command]
	cName = trim(cName)
	cName = left(cName, substr(cName,".") - 1) # Remove .ring
	if lower(left(cName,4)) = "ring"
		cName = substr(cName,5)
	ok
	cName = trim(cName)
	cName = substr(cName,"\","_")
	cName = substr(cName,"/","_")
	cName = cName + ".txt"
	return cName