func main
	? "Removing Allegro5.2.8"
	cDir = CurrentDir()
	chdir(exefolder()+"../extensions/libdepwin")
	OSDeleteFolder("Allegro5.2.8")
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