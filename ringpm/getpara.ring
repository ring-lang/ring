/*
	Title :	The Ring Package Manager 
	Date  : 2018.10.18
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

func GetParameters cProgramName
	aPara = sysargv
	cEXEFileName = JustFileName(exefilename())
	# Windows ---> ring.exe | ringw.exe 
	# Linux | macOS --->  ring 
	# Remove .exe from the file name 
		cEXEFileName = substr(cEXEFileName,".exe","")
	if cEXEFileName != cProgramName
		nStart = 3
	else			# ringpm.exe 
		nStart = 2
	ok
	aList = []
	if len(aPara) >= nStart
		for x = nStart to len(aPara)
			aList + aPara[x]
		next
	ok
	return aList
