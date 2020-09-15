func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "QtClassConverter Package"
	? copy("=",C_LINESIZE)
	? "QtClassConverter package for the Ring programming language"
	? "See the folder : ring/extensions/ringqt/Converter"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../extensions/ringqt/Converter")
	system("ring QtClassConverter.ring")
	chdir(cDir)