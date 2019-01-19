load "stdlib.ring"

func main
	? "Removing Folder : pgsql"
	cDir = CurrentDir()
	chdir(exefolder()+"../libdepwin")
	OSDeleteFolder("pgsql")
	chdir(cDir)