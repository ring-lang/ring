load "stdlib.ring"

func main
	? "Removing Folder : ring/android/ringqt"
	cDir = CurrentDir()
	chdir(exefolder()+"../android")
	OSDeleteFolder("ringqt")
	chdir(cDir)