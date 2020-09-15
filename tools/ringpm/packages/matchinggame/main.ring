func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "Matching game Package"
	? copy("=",C_LINESIZE)
	? "Matching game package for the Ring programming language"
	? "See the folder : ring/applications/matching"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/matching")
	system("ring MatchingGame.ring")
	chdir(cDir)