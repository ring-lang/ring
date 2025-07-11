func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "TriangleCalculator Package"
	? copy("=",C_LINESIZE)
	? "TriangleCalculator package for the Ring programming language"
	? "See the folder : ring/applications/trianglecalculator"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/trianglecalculator")
	system("ring TriangleCalculator.ring")
	chdir(cDir)