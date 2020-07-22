func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "Help2Wiki Package"
	? copy("=",C_LINESIZE)
	? "Help2Wiki package for the Ring programming language"
	? "See the folder : ring/samples/tools/help2wiki"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../samples/tools/help2wiki")
	system("ring help2wiki.ring")
	chdir(cDir)