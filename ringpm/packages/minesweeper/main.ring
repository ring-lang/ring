func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "MinwSweeper Package"
	? copy("=",C_LINESIZE)
	? "MineSweeper package for the Ring programming language"
	? "See the folder : ring/applications/minesweeper"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/minesweeper")
	system("ring minesweeper.ring")
	chdir(cDir)