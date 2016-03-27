#!b:\mahmoud\apps\nova2\nova.exe 

func main

	starthtml()
	
	see "string length" + get("CONTENT_LENGTH") + newline()
	size = 1+get("CONTENT_LENGTH")
	if size > 1
		data = input(size)
		see data + newline()
	else
		see "error" + newline()
	ok
	
	see "File Name : " + get("SCRIPT_FILENAME") + newline()
	see "Method : " + get("REQUEST_METHOD") + newline()
	
func starthtml
	see "Content-type: text/html"+nl+nl
	
func newline
	see "<br />"
	