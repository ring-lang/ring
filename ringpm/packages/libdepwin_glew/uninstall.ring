load "stdlib.ring"

func main
	? "Removing Folder : glew"
	cDir = CurrentDir()
	chdir(exefolder()+"../libdepwin")
	OSDeleteFolder("glew")
	chdir(cDir)