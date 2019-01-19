func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "Checkers Package"
	? copy("=",C_LINESIZE)
	? "Checkers package for the Ring programming language"
	? "See the folder : ring/applications/checkers"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/checkers")
	system("ring CalmoSoftCheckersGame.ring")
	chdir(cDir)