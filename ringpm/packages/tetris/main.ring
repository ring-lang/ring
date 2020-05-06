func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "Tetris Package"
	? copy("=",C_LINESIZE)
	? "Tetris package for the Ring programming language"
	? "See the folder : ring/applications/tetris"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/tetris")
	system("ring tetris.ring")
	chdir(cDir)