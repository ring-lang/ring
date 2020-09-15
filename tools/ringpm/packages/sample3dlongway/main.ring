func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "Sample3DLongWay Package"
	? copy("=",C_LINESIZE)
	? "Sample3DLongWay package for the Ring programming language"
	? "See the folder : ring/samples/UsingOpenGL/longway"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../samples/UsingOpenGL/longway")
	system("ring longway.ring")
	chdir(cDir)