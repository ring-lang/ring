func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "LightsOut Package"
	? copy("=",C_LINESIZE)
	? "LightsOut package for the Ring programming language"
	? "See the folder : ring/applications/lightsout"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/lightsout")
	system("ring LightsOut.ring")
	chdir(cDir)