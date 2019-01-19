func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "RingHelpCHM Package"
	? copy("=",C_LINESIZE)
	? "RingHelpCHM package for the Ring programming language"
	? "See the folder : ring/docs"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../docs")
	system("ring.chm")
	chdir(cDir)