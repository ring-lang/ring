func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "Escape Game Package"
	? copy("=",C_LINESIZE)
	? "Escape Game package for the Ring programming language"
	? "See the folder : ring/applications/escape"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/escape")
	system("ring EscapeGame.ring")
	chdir(cDir)