func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "WeightHistory Package"
	? copy("=",C_LINESIZE)
	? "WeightHistory package for the Ring programming language"
	? "See the folder : ring/applications/weighthistory"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/weighthistory")
	system("ring weighthistory.ring")
	chdir(cDir)