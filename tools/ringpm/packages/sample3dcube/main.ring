func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "Sample3DCube Package"
	? copy("=",C_LINESIZE)
	? "Sample3DCube package for the Ring programming language"
	? "See the folder : ring/samples/UsingOpenGL/ringcube"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../samples/UsingOpenGL/ringcube")
	system("ring cube.ring")
	chdir(cDir)