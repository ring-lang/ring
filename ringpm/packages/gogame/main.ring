func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "GoGame Package"
	? copy("=",C_LINESIZE)
	? "GoGame package for the Ring programming language"
	? "See the folder : ring/applications/go"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/go")
	system("ring GoGame.ring")
	chdir(cDir)