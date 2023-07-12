load "ziplib.ring"

func main

	? "Extracting File : ringhttplib.zip"
	cDir = CurrentDir()
	chdir(exefolder()+"../extensions")
	zip_extract_allfiles("ringhttplib.zip","../extensions")
	remove("ringhttplib.zip")
	chdir(cDir)

	? "Extracting File : UsingHTTPLib.zip"
	chdir(exefolder()+"../samples")
	zip_extract_allfiles("UsingHTTPLib.zip","../samples")
	remove("UsingHTTPLib.zip")
	chdir(cDir)
