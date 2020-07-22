func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "AnalogClock Package"
	? copy("=",C_LINESIZE)
	? "AnalogClock package for the Ring programming language"
	? "See the folder : ring/applications/analogclock"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/analogclock")
	system("ring AnalogClock-Image.ring")
	chdir(cDir)