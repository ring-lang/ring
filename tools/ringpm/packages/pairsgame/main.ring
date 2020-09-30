func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "Pairs game Package"
	? copy("=",C_LINESIZE)
	? "Pairs game package for the Ring programming language"
	? "See the folder : ring/applications/pairs"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/pairs")
	system("ring PairsGame.ring")
	chdir(cDir)