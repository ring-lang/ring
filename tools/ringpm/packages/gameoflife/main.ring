func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "GameOfLife Package"
	? copy("=",C_LINESIZE)
	? "GameOfLife package for the Ring programming language"
	? "See the folder : ring/applications/gameoflife"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/gameoflife")
	system("ring AA-GameOfLife.ring")
	chdir(cDir)