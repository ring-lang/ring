func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "Cards Package"
	? copy("=",C_LINESIZE)
	? "Cards package for the Ring programming language"
	? "See the folder : ring/applications/cards"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/cards")
	system("ring cards.ring")
	chdir(cDir)