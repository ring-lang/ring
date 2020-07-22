func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "MemoryGame Package"
	? copy("=",C_LINESIZE)
	? "MemoryGame package for the Ring programming language"
	? "See the folder : ring/applications/memorygame"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/memorygame")
	system("ring CalmoSoftMemoryGame.ring")
	chdir(cDir)