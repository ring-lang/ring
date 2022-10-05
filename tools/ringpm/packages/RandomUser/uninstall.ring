func main
	? "Removing Folder : ring/applications/randomuser"
	cDir = CurrentDir()
	chdir(exefolder()+"../applications")
	OSDeleteFolder("randomuser")
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