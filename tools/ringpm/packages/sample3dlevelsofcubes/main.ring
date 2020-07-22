func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "Sample3DLevelsOfCubes Package"
	? copy("=",C_LINESIZE)
	? "Sample3DLevelsOfCubes package for the Ring programming language"
	? "See the folder : ring/samples/3D/levelsofcubes"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../samples/3D/levelsofcubes")
	system("ring levelsofcubes.ring")
	chdir(cDir)