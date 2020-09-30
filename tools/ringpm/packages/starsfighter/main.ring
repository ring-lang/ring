func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "StarsFighter Package"
	? copy("=",C_LINESIZE)
	? "StarsFighter package for the Ring programming language"
	? "See the folder : ring/applications/starsfighter"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/starsfighter")
	system("ring starsfighter.ring")
	chdir(cDir)