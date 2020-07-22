load "ziplib.ring"

func main
	? "Extracting File : Allegro5.2.4.zip"
	cDir = CurrentDir()
	chdir(exefolder()+"../libdepwin")
	zip_extract_allfiles("Allegro5.2.4.zip","../libdepwin")
	remove("Allegro5.2.4.zip")
	chdir(cDir)