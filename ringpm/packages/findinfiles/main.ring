func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "FindInFiles Package"
	? copy("=",C_LINESIZE)
	? "FindInFiles package for the Ring programming language"
	? "See the folder : ring/applications/findinfiles"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/findinfiles")
	system("ring findinfilescontroller.ring")
	chdir(cDir)