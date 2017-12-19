load "ziplib.ring"

new Zip {
	setFileName("myfile.zip")
	open("w")
	newEntry() {
		open("test.c")
		writefile("test.c")
		close()
	}
	close()
}

