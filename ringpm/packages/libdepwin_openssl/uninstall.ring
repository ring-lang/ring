load "stdlib.ring"

func main
	? "Removing Folder : openssl"
	cDir = CurrentDir()
	chdir(exefolder()+"../libdepwin")
	OSDeleteFolder("openssl")
	chdir(cDir)