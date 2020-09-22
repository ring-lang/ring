func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "QtClassConverter Package"
	? copy("=",C_LINESIZE)
	? "QtClassConverter package for the Ring programming language"
	? "See the folder : ring/extensions/ringqt/converter"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../extensions/ringqt/converter")
	system("ring QtClassConverter.ring")
	chdir(cDir)