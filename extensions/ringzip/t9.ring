load "ziplib.ring"

new Zip {
	SetFileName("myfile.zip")
	Open("r")
	see FilesCount()
	Close()
}
