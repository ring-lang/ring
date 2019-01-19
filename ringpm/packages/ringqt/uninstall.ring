load "stdlib.ring"

func main
	? "Removing Folder : ringqt"
	cDir = CurrentDir()
	chdir(exefolder()+"../extensions")
	OSDeleteFolder("ringqt")
	chdir(cDir)