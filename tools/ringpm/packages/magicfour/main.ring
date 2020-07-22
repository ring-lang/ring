func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "MagicFour Package"
	? copy("=",C_LINESIZE)
	? "MagicFour package for the Ring programming language"
	? "See the folder : ring/applications/magicfour"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/magicfour")
	system("ring CalmoSoftMagicFour.ring")
	chdir(cDir)