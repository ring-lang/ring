func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "Calendar Package"
	? copy("=",C_LINESIZE)
	? "Calendar package for the Ring programming language"
	? "See the folder : ring/applications/calendar"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/calendar")
	system("ring Calendar.ring")
	chdir(cDir)