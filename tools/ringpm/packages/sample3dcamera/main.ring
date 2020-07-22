func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "Sample3DCamera Package"
	? copy("=",C_LINESIZE)
	? "Sample3DCamera package for the Ring programming language"
	? "See the folder : ring/samples/3D/camera"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../samples/3D/camera")
	system("ring camera.ring")
	chdir(cDir)