/**
	*Application: Ring Package Manager (RingPM)
	*Author: Zaghdoudi Chokri
	*Date: 2019/03/10
*/

/*
	Ce qu'on a besoin de tester
		1- L'executable s'exécute --> Message de copyright
		2- Installation des fifférents packages
		3- Affichage la liste des packages installés
		4- Désinstallation des packages
		5- Afficher la liste des packages aprés l'installation
		6- Faite une list des packages aprés désinstallation
		...
*/

load "stdlibCore.ring"
load "globals.ring"
load "tests.ring"
load "../getparams.ring"

SelectMode()
SetTestingMode() # C_MODE_TESTING = 2|C_MODE_UPDATETEST =  1
RunTests()

func SelectMode
	aCommand = GetParams("test")
	if len(aCommand) >= 1
		cCmd = lower(trim(aCommand[1]))
		switch cCmd
			on "test"
				nTestMode = C_MODE_TESTING
			on "update"
				nTestMode = C_MODE_UPDATETEST
			other
				? "Mode not selected!"
				return
		off
	ok

func RunTests
	? "Mode du teste     : " + nTestMode
	nMax = len(aTests)
	? "Nombre des testes : " + nMax
	? copy("=",40)
	for x = 1 to nMax
		aTest = aTests[x]
		RunTest(x,aTest)
		ShowResult(x,aTest)
	next

func SetTestingMode
	switch nTestMode
		on C_MODE_UPDATETEST
			cOutputFolder += cCorrectFolder
		on C_MODE_TESTING
			cOutputFolder += cCurrentFolder
		other
			? "The test mode is not correct set!"
			return 
	off

func RunTest nIndex,aTest
	see nl + With("Test ("+nIndex+") ",10) + ": " + 
		With(aTest[:name],52)
	cCurrDir = CurrentDir()
	chdir("../")
	# Prend une commande sans afficher son (output)
		System(aTest[:Command]+" > "+cOutputFolder+
				"/test"+nIndex+".txt")
	chdir(cCurrDir)

func ShowResult nIndex,aTest
	if nTestMode = C_MODE_TESTING
		cFileNameCorrect = cCorrectFolder+"/test"+nIndex+".txt"
		cFileNameCurr = cCurrentFolder+"/test"+nIndex+".txt"
		# Verifier la difference entre les deux fichier
			if ! fexists(cFileNameCorrect)
				? ""
				? C_ERR_FILENOEXIST + " (" +cFileNameCorrect + ")"
				return
			ok
			see "- Etat: "
			if read(cFileNameCorrect) = read(cFileNameCurr)
				see "PASS"
			else see "FAILED !"
			ok
	ok

func With cStr,nWith
	# Accept String |Number
		if isnumber(cStr) cStr = "" + cStr  ok # Convertir en string
	# Ajout espace
		if len(cStr) < nWith cStr += copy(" ",nWith-len(cStr)) ok
	return cStr
