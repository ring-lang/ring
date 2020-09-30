load "ziplib.ring"

func main
	? "Extracting File : visualstudio.zip"
	cDir = CurrentDir()
	chdir(exefolder()+"../tools/editor")
	zip_extract_allfiles("visualstudio.zip","../editor")
	remove("visualstudio.zip")
	chdir(cDir)