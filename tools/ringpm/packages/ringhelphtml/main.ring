func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "RingHelpHTML Package"
	? copy("=",C_LINESIZE)
	? "RingHelpHTML package for the Ring programming language"
	? "See the folder : ring/documents/build/html"
	? copy("=",C_LINESIZE)
	if isWindows()
		cDir = currentdir()
		chdir(exefolder()+"/../documents/build/html")
		system("index.html")
		chdir(cDir)
	ok