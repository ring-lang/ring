func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "OthelloGame Package"
	? copy("=",C_LINESIZE)
	? "OthelloGame package for the Ring programming language"
	? "See the folder : ring/applications/othellogame"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/othellogame")
	system("ring OthelloGame.ring")
	chdir(cDir)