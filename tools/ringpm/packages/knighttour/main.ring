func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "KnightTour Package"
	? copy("=",C_LINESIZE)
	? "KnightTour package for the Ring programming language"
	? "See the folder : ring/applications/knighttour"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/knighttour")
	system("ring AA-KnightTour.ring")
	chdir(cDir)