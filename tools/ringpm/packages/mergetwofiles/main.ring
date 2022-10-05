func main
	C_LINESIZE = 80
	? copy("=",C_LINESIZE)
	? "MergeTwoFiles Package"
	? copy("=",C_LINESIZE)
	? "MergeTwoFiles package for the Ring programming language"
	? "See the folder : ring/applications/mergetwofiles"
	? copy("=",C_LINESIZE)
	cDir = currentdir()
	chdir(exefolder()+"/../applications/mergetwofiles")
	system("ring MergeController.ring")
	chdir(cDir)