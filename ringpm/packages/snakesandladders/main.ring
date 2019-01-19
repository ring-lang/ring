func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "SnakesAndLadders Package"
	? copy("=",C_LINESIZE)
	? "SnakesAndLadders package for the Ring programming language"
	? "See the folder : ring/applications/snakesandladders"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/snakesandladders")
	system("ring CalmoSoftSnakesAndLadders.ring")
	chdir(cDir)