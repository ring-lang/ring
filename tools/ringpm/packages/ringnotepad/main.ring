func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "RingNotepad Package"
	? copy("=",C_LINESIZE)
	? "RingNotepad package for the Ring programming language"
	? "See the folder : ring/applications/rnote"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/rnote")
	system("ring rnote.ring")
	chdir(cDir)