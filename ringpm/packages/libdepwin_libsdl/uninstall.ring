load "stdlib.ring"

func main
	? "Removing Folder : libsdl"
	cDir = CurrentDir()
	chdir(exefolder()+"../libdepwin")
	OSDeleteFolder("libsdl")
	chdir(cDir)