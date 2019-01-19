func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "FifteenPuzzle Package"
	? copy("=",C_LINESIZE)
	? "FifteenPuzzle package for the Ring programming language"
	? "See the folder : ring/applications/fifteenpuzzle"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/fifteenpuzzle")
	system("ring CalmoSoftFifteenPuzzleGame.ring")
	chdir(cDir)