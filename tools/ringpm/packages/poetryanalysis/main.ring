func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "PoetryAnalysis Package"
	? copy("=",C_LINESIZE)
	? "PoetryAnalysis package for the Ring programming language"
	? "See the folder : ring/applications/poetryanalysis"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/poetryanalysis/src")
	system("ring Main.ring")
	chdir(cDir)