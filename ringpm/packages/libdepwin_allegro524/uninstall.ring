load "stdlib.ring"

func main
	? "Removing Allegro5.2.4"
	cDir = CurrentDir()
	chdir(exefolder()+"../libdepwin")
	OSDeleteFolder("Allegro5.2.4")
	chdir(cDir)