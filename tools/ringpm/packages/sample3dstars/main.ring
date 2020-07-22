func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "Sample3DStars Package"
	? copy("=",C_LINESIZE)
	? "Sample3DStars package for the Ring programming language"
	? "See the folder : ring/samples/3D/stars"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../samples/3D/stars")
	system("ring stars.ring")
	chdir(cDir)