func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "QtClassConverter Package"
	? copy("=",C_LINESIZE)
	? "QtClassConverter package for the Ring programming language"
	? "See the folder : ring/samples/tools/QtClassConverter"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../samples/tools/QtClassConverter")
	system("ring QtClassConverter.ring")
	chdir(cDir)