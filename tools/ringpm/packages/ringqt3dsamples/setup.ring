load "ziplib.ring"

func main
	? "Extracting File : samples.zip"
	cDir = CurrentDir()
	chdir(exefolder()+"../samples")
	zip_extract_allfiles("samples.zip","../samples")
	remove("samples.zip")
	chdir(cDir)