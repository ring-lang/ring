func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "Word game Package"
	? copy("=",C_LINESIZE)
	? "Word game package for the Ring programming language"
	? "See the folder : ring/applications/wordgame"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/wordgame")
	system("ring WordGame.ring")
	chdir(cDir)