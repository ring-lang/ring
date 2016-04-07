# The Ring Standard Library
# Common Functions and Classes for Applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

func apppath
	cFile = sysargv[2] # The Main File
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
	if right(cPath,1) != "\" and right(cPath,1) != "/" cPath += "/" ok
	return cPath
