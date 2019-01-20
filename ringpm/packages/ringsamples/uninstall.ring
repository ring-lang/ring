func main
	? "Removing Samples"
	cDir = CurrentDir()
	chdir(exefolder()+"../samples")
	OSDeleteFolder("fromdoc")
	OSDeleteFolder("other")
	OSDeleteFolder("rosettacode")
	chdir(cDir)

func OSDeleteFolder cFolder 
	if isWindows() 
		systemSilent("rd /s /q " + cFolder)
	else
		systemSilent("rm -r " + cFolder)
	ok

func SystemSilent cCmd
	if isWindows()
		system(cCmd + " >nul 2>nul")
	else 
		system(cCmd + " > /dev/null")
	ok