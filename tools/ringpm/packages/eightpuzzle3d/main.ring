func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "EightPuzzle3D Package"
	? copy("=",C_LINESIZE)
	? "EightPuzzle3D package for the Ring programming language"
	? "See the folder : ring/applications/eightpuzzle3d"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/eightpuzzle3d")
	system("ring EightPuzzleGame3D.ring")
	chdir(cDir)