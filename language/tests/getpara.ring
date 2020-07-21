/*
	Ring programming language
	2018, Mahmoud Fayed
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
	else			
		nStart = 2
	ok
	aList = []
	if len(aPara) >= nStart
		for x = nStart to len(aPara)
			aList + aPara[x]
		next
	ok
	return aList
