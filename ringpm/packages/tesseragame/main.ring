func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "TesseraGame Package"
	? copy("=",C_LINESIZE)
	? "TesseraGame package for the Ring programming language"
	? "See the folder : ring/applications/tesseragame"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/tesseragame")
	system("ring CalmoSoftTesseraGame.ring")
	chdir(cDir)