func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "ASCIITable Package"
	? copy("=",C_LINESIZE)
	? "ASCIITable package for the Ring programming language"
	? "See the folder : ring/applications/asciitable"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/asciitable")
	system("ring CalmoSoftAsciiTable.ring")
	chdir(cDir)