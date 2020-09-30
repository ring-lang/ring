func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "EightQueensGame Package"
	? copy("=",C_LINESIZE)
	? "EightQueensGame package for the Ring programming language"
	? "See the folder : ring/applications/eightqueens"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/eightqueens")
	system("ring EightQueensGame.ring")
	chdir(cDir)