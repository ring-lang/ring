func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "HoursCounter Package"
	? copy("=",C_LINESIZE)
	? "HoursCounter package for the Ring programming language"
	? "See the folder : ring/applications/hourscounter"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/hourscounter")
	system("ring mainController.ring")
	chdir(cDir)