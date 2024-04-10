load "ziplib.ring"

func main
	? "Extracting File : html.zip"
	cDir = CurrentDir()
	chdir(exefolder()+"../documents/build")
	zip_extract_allfiles("html.zip","../build")
	remove("html.zip")
	chdir(cDir)