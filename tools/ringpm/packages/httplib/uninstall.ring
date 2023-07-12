func main
	? nl+"Removing Folder : ring/extensions/ringhttplib"
	cDir = CurrentDir()
	chdir(exefolder()+"../extensions")
	OSDeleteFolder("ringhttplib")
	chdir(cDir)

	? "Removing Folder : ring/samples/UsingHTTPLib"
	chdir(exefolder()+"../samples")
	OSDeleteFolder("UsingHTTPLib")
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