func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "ReadFiles Application Package"
	? copy("=",C_LINESIZE)
	? "ReadFiles Application package for the Ring programming language"
	? "See the folder : ring/applications/readfiles"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/readfiles")
	system("ring ReadBinaryController.ring")