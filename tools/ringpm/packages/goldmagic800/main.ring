func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "GoldMagic800 Package"
	? copy("=",C_LINESIZE)
	? "GoldMagic800 package for the Ring programming language"
	? "See the folder : ring/applications/goldmagic800"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/goldmagic800")
	system("ring goldmagic800.ring")
	chdir(cDir)