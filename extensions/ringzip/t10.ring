load "ziplib.ring"

new Zip {
	SetFileName("myfile.zip")
	Open("r")
	for x = 1 to filescount() 
		See GetFileNameByIndex(x) + nl
	next
	Close()
}
