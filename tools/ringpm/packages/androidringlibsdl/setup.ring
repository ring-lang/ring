load "ziplib.ring"

func main
	? "Extracting File : ringlibsdl.zip"
	cDir = CurrentDir()
	chdir(exefolder()+"../android")
	zip_extract_allfiles("ringlibsdl.zip","../android")
	remove("ringlibsdl.zip")
	chdir(cDir)