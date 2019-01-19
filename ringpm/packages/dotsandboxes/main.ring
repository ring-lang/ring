func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "DotsAndBoxes Package"
	? copy("=",C_LINESIZE)
	? "DotsAndBoxes package for the Ring programming language"
	? "See the folder : ring/applications/dotsandboxes"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/dotsandboxes")
	system("ring CalmoSoftDotsAndBoxes.ring")
	chdir(cDir)