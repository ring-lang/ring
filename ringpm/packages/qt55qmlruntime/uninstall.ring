func main
	? "Removing Files : Qt 5.5 QML runtime"
	cDir = CurrentDir()
	chdir(exefolder()+"../bin")
	OSDeleteFolder("qml")
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