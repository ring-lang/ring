func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "StockAnalysis Package"
	? copy("=",C_LINESIZE)
	? "StockAnalysis package for the Ring programming language"
	? "See the folder : ring/applications/stockanalysis"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/stockanalysis")
	system("ring main.ring")
	chdir(cDir)