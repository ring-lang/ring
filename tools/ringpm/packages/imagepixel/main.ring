func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "ImagePixel Package"
	? copy("=",C_LINESIZE)
	? "ImagePixel package for the Ring programming language"
	? "See the folder : ring/applications/imagepixel"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/imagepixel")
	system("ring ImagePixel.ring")
	chdir(cDir)