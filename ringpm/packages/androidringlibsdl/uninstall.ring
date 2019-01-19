load "stdlib.ring"

func main
	? "Removing Folder : ring/android/ringlibsdl"
	cDir = CurrentDir()
	chdir(exefolder()+"../android")
	OSDeleteFolder("ringlibsdl")
	chdir(cDir)