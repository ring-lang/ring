func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "RockPaperScissors Package"
	? copy("=",C_LINESIZE)
	? "RockPaperScissors package for the Ring programming language"
	? "See the folder : ring/applications/rockpaperscissors"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/rockpaperscissors")
	system("ring RockPaperScissorsGame.ring")
	chdir(cDir)