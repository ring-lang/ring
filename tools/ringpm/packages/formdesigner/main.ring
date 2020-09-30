func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "FormDesigner Package"
	? copy("=",C_LINESIZE)
	? "FormDesigner package for the Ring programming language"
	? "See the folder : ring/tools/formdesigner"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../tools/formdesigner")
	system("ring formdesigner.ring")
	chdir(cDir)