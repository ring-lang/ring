func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "FindInFiles Package"
	? copy("=",C_LINESIZE)
	? "FindInFiles package for the Ring programming language"
	? "See the folder : ring/tools/findinfiles"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../tools/findinfiles")
	system("ring findinfilesController.ring")
	chdir(cDir)