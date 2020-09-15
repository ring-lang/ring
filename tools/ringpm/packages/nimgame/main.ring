func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "NimGame Package"
	? copy("=",C_LINESIZE)
	? "NimGame package for the Ring programming language"
	? "See the folder : ring/applications/nimgame"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/nimgame")
	system("ring NimGame.ring")
	chdir(cDir)