func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "CodeRooms3D Package"
	? copy("=",C_LINESIZE)
	? "CodeRooms3D package for the Ring programming language"
	? "See the folder : ring/applications/coderooms3d"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/coderooms3d")
	system("ring coderooms3d.ring")
	chdir(cDir)