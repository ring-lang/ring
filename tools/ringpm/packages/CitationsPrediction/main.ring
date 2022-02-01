func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "CitationsPrediction Package"
	? copy("=",C_LINESIZE)
	? "CitationsPrediction package for the Ring programming language"
	? "See the folder : ring/applications/citationsprediction"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/citationspredictiton")
	system("ring predictController.ring")
	chdir(cDir)