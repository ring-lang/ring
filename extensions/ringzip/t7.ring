load "ziplib.ring"

new Zip {
	SetFileName("myfile.zip")
	Open("w")
	AddFile("test.c")
	AddFile("zip.c")
	AddFile("zip.h")
	AddFile("miniz.h")
	Close()
}