func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "Sokoban Package"
	? copy("=",C_LINESIZE)
	? "Sokoban package for the Ring programming language"
	? "See the folder : ring/applications/sokoban"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/sokoban")
	system("ring sokoban.ring")
	chdir(cDir)