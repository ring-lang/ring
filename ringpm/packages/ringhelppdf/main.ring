func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "RingHelpPDF Package"
	? copy("=",C_LINESIZE)
	? "RingHelpPDF package for the Ring programming language"
	? "See the folder : ring/docs"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../docs")
	system("ring.pdf")
	chdir(cDir)