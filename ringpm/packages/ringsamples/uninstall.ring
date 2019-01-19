load "stdlib.ring"

func main
	? "Removing Samples"
	cDir = CurrentDir()
	chdir(exefolder()+"../samples")
	OSDeleteFolder("fromdoc")
	OSDeleteFolder("other")
	OSDeleteFolder("rosettacode")
	chdir(cDir)