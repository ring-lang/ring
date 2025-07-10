func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "SnakesAndLadders2 Package"
	? copy("=",C_LINESIZE)
	? "SnakesAndLadders2 package for the Ring programming language"
	? "See the folder : ring/applications/snakesandladders2"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/snakesandladders2")
	system("ring SnakesAndLadders-BM.ring")
	chdir(cDir)