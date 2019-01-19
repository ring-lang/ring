func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "SuperMan2016 Package"
	? copy("=",C_LINESIZE)
	? "SuperMan2016 package for the Ring programming language"
	? "See the folder : ring/applications/superman2016"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/superman2016")
	system("ring superman.ring")
	chdir(cDir)