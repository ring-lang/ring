func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "Sample3DStars Package"
	? copy("=",C_LINESIZE)
	? "Sample3DStars package for the Ring programming language"
	? "See the folder : ring/samples/UsingOpenGL/stars"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../samples/UsingOpenGL/stars")
	system("ring stars3.ring")
	chdir(cDir)