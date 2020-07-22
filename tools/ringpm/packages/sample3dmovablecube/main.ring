func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "Sample3DMovableCube Package"
	? copy("=",C_LINESIZE)
	? "Sample3DMovableCube package for the Ring programming language"
	? "See the folder : ring/samples/3D/movablecube"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../samples/3D/movablecube")
	system("ring cube.ring")
	chdir(cDir)