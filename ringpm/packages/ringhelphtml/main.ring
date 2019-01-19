func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "RingHelpHTML Package"
	? copy("=",C_LINESIZE)
	? "RingHelpHTML package for the Ring programming language"
	? "See the folder : ring/docs/build/html"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../docs/build/html")
	system("index.html")
	chdir(cDir)