func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "Sample3DCameraAndBackground Package"
	? copy("=",C_LINESIZE)
	? "Sample3DCameraAndBackground package for the Ring programming language"
	? "See the folder : ring/samples/3D/cameraandbackground"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../samples/3D/cameraandbackground")
	system("ring Camera.ring")
	chdir(cDir)