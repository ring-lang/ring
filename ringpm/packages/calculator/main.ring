func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "Calculator Package"
	? copy("=",C_LINESIZE)
	? "Calculator package for the Ring programming language"
	? "See the folder : ring/applications/calculator"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/calculator")
	system("ring calc-gui.ring")
	chdir(cDir)