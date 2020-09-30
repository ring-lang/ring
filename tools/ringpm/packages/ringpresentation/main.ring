func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "RingPresentation Package"
	? copy("=",C_LINESIZE)
	? "RingPresentation package for the Ring programming language"
	? "See the folder : ring/marketing/presentation"
	? copy("=",C_LINESIZE)
	if isWindows()
		cDir = currentdir()
		chdir(exefolder()+"/../marketing/presentation")
		system("Ring.pptx")
		chdir(cDir)
	ok