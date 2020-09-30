func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "Sample3DCameraAndBackground Package"
	? copy("=",C_LINESIZE)
	? "Sample3DCameraAndBackground package for the Ring programming language"
	? "See the folder : ring/samples/UsingOpenGL/cameraandbackground"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../samples/UsingOpenGL/cameraandbackground")
	system("ring Camera.ring")
	chdir(cDir)