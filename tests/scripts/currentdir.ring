Func Main
	see "Hello" + nl +
	    "Current dir : " + currentdir()  + nl +
	    "File name : " + filename() + nl +
	    "Application path : " + apppath() + nl


func apppath
	cFile = filename()
	update = false
	for x = len(cFile) to 1 step -1
		if cFile[x] = "\" or cFile[x] = "/"
			cFile = left(cFile,x)
			update = true
			exit
		ok
	next
	if update = true
		if cFile[1] != "/" and cFile[2] != ":"
			cPath = currentdir() + "\" + cFile
		else
			cPath = cFile
		ok
	else
		cPath = currentdir()
	ok
	return cPath
