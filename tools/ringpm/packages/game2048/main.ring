func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "Game2048 Package"
	? copy("=",C_LINESIZE)
	? "Game2048 package for the Ring programming language"
	? "See the folder : ring/applications/game2048"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/game2048")
	system("ring game2048.ring")
	chdir(cDir)