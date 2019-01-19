func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "String2Constant Package"
	? copy("=",C_LINESIZE)
	? "String2Constant package for the Ring programming language"
	? "See the folder : ring/samples/tools/string2constant"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../samples/tools/string2constant")
	system("ring string2constantController.ring")
	chdir(cDir)