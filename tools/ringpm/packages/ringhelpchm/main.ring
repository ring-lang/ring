func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "RingHelpCHM Package"
	? copy("=",C_LINESIZE)
	? "RingHelpCHM package for the Ring programming language"
	? "See the folder : ring/documents"
	? copy("=",C_LINESIZE)
	if isWindows()
		cDir = currentdir()
		chdir(exefolder()+"/../documents")
		system("ring.chm")
		chdir(cDir)
	ok