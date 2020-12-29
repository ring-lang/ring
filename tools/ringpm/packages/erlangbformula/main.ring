func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "ErlangBFormula Package"
	? copy("=",C_LINESIZE)
	? "ErlangBFormula package for the Ring programming language"
	? "See the folder : ring/applications/erlangbformula"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/erlangbformula")
	system("ring myappController.ring")
	chdir(cDir)