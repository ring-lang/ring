load "ziplib.ring"

func main
	? "Extracting File : Allegro5.2.8.zip"
	cDir = CurrentDir()
	chdir(exefolder()+"../extensions/libdepwin")
	zip_extract_allfiles("Allegro5.2.8.zip","../libdepwin")
	remove("Allegro5.2.8.zip")
	chdir(cDir)