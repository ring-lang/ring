func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "SixteenPuzzle Package"
	? copy("=",C_LINESIZE)
	? "SixteenPuzzle package for the Ring programming language"
	? "See the folder : ring/applications/sixteenpuzzle"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/sixteenpuzzle")
	system("ring CalmoSoftSixteenPuzzle.ring")
	chdir(cDir)