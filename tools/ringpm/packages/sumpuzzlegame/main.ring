func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "SumPuzzleGame Package"
	? copy("=",C_LINESIZE)
	? "SumPuzzleGame package for the Ring programming language"
	? "See the folder : ring/applications/sumpuzzlegame"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/sumpuzzlegame")
	system("ring CalmoSoftSumsPuzzle.ring")
	chdir(cDir)