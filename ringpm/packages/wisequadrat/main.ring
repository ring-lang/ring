func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "WiseQuadrat Package"
	? copy("=",C_LINESIZE)
	? "WiseQuadrat package for the Ring programming language"
	? "See the folder : ring/applications/wisequadrat"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/wisequadrat")
	system("ring CalmoSoftWiseQuadratGame.ring")
	chdir(cDir)