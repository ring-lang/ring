func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "RingHelpPDF Package"
	? copy("=",C_LINESIZE)
	? "RingHelpPDF package for the Ring programming language"
	? "See the folder : ring/documents"
	? copy("=",C_LINESIZE)
	if isWindows()
		cDir = currentdir()
		chdir(exefolder()+"/../documents")
		system("ring.pdf")
		chdir(cDir)
	ok