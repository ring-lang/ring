func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "Sample3DLevelsOfCubes Package"
	? copy("=",C_LINESIZE)
	? "Sample3DLevelsOfCubes package for the Ring programming language"
	? "See the folder : ring/samples/UsingOpenGL/levelsofcubes"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../samples/UsingOpenGL/levelsofcubes")
	system("ring levelsofcubes.ring")
	chdir(cDir)