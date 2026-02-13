func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "LineDrawing3D Package"
	? copy("=",C_LINESIZE)
	? "LineDrawing3D package for the Ring programming language"
	? "See the folder : ring/applications/linedrawing3d"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/linedrawing3d")
	system("ring linedrawing3d.ring")
	chdir(cDir)