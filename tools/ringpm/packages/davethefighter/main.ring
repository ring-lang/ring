func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "DaveTheFighter Package"
	? copy("=",C_LINESIZE)
	? "DaveTheFighter package for the Ring programming language"
	? "See the folder : ring/applications/davethefighter"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/davethefighter")
	system("ring davethefighter.ring")
	chdir(cDir)