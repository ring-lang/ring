load "stdlib.ring"

func main
	? "Removing Folder : ring/editor/visualstudio"
	cDir = CurrentDir()
	chdir(exefolder()+"../editor")
	OSDeleteFolder("visualstudio")
	chdir(cDir)