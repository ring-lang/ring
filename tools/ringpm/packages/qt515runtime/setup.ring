load "ziplib.ring"

func main
	? "Extracting File : bin.zip"
	cDir = CurrentDir()
	chdir(exefolder()+"../bin")
	zip_extract_allfiles("bin.zip","../bin")
	remove("bin.zip")
	? "Extracting File : bin2.zip"
	zip_extract_allfiles("bin2.zip","../bin")
	remove("bin2.zip")
	chdir(cDir)