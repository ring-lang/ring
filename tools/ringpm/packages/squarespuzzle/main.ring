func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "SquaresPuzzle Package"
	? copy("=",C_LINESIZE)
	? "SquaresPuzzle package for the Ring programming language"
	? "See the folder : ring/applications/squarespuzzle"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/squarespuzzle")
	system("ring squarespuzzle.ring")
	chdir(cDir)