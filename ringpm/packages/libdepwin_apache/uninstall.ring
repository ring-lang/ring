load "stdlib.ring"

func main
	? "Removing Folder : Apache2.2"
	cDir = CurrentDir()
	chdir(exefolder()+"../libdepwin")
	OSDeleteFolder("Apache2.2")
	chdir(cDir)