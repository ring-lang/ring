load "stdlib.ring"

func main
	? "Removing Folder : MySQL"
	cDir = CurrentDir()
	chdir(exefolder()+"../libdepwin")
	OSDeleteFolder("MySQL")
	chdir(cDir)