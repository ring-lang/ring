func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "FifteenPuzzle3D Package"
	? copy("=",C_LINESIZE)
	? "FifteenPuzzle3D package for the Ring programming language"
	? "See the folder : ring/applications/fifteenpuzzle3d"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/fifteenpuzzle3d")
	system("ring FifteenPuzzleGame3D.ring")
	chdir(cDir)