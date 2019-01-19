load "stdlib.ring"

func main
	? "Removing Folder : html"
	cDir = CurrentDir()
	chdir(exefolder()+"../docs/build")
	OSDeleteFolder("html")
	chdir(cDir)