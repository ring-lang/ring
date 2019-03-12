/**
	*Application: Ring Package Manager (RingPM)
	*Author: Zaghdoudi Chokri
	*Date: 2019/03/10
*/

func GetParams cProgName
	# sysargv = C:\Ring\bin\ringw.exe & C:/Ring/learning/myringpm/ringpm.ring
	aParams = sysargv
	cExeFileName = JustFileName(exefilename())
	# Sur windows sera ring.exe|ringpm.exe
	# Sur Linux|macOs sera ring
	# Enlever l'extension du fichier
		cExeFileName = substr(cExeFileName,".exe","")
	if cExeFileName != cProgName
		nStart = 3
	else nStart = 2   # cProgName.exe
	ok
	aList = []
	if len(aParams) >= nStart
		for x = nStart to len(aParams)
			aList + aParams[x]
		next
	ok
	return aList
