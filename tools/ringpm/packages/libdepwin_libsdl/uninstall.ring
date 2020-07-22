func main
	? "Removing Folder : libsdl"
	cDir = CurrentDir()
	chdir(exefolder()+"../libdepwin")
	OSDeleteFolder("libsdl")
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