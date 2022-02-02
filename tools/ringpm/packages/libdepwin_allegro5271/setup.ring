load "ziplib.ring"

func main
	? "Extracting File : Allegro5.2.7.1.zip"
	cDir = CurrentDir()
	chdir(exefolder()+"../extensions/libdepwin")
	zip_extract_allfiles("Allegro5.2.7.1.zip","../libdepwin")
	remove("Allegro5.2.7.1.zip")
	chdir(cDir)