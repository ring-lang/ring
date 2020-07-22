load "ziplib.ring"

func main
	? "Extracting File : libsdl.zip"
	cDir = CurrentDir()
	chdir(exefolder()+"../libdepwin")
	zip_extract_allfiles("libsdl.zip","../libdepwin")
	remove("libsdl.zip")
	chdir(cDir)