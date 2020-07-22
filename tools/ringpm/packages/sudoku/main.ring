func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "Sudoku Package"
	? copy("=",C_LINESIZE)
	? "Sudoku package for the Ring programming language"
	? "See the folder : ring/applications/sudoku"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/sudoku/v3")
	system("ring AA-Sudoku.ring")
	chdir(cDir)