# The Ring Standard Library
# Common Functions and Classes for Applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

/*
	Function Name	: AppPath
	Usage		: Get the path of the application folder
	Parameters	: No Parameters
*/
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


/*
	Function Name	: Times
	Usage		: Execute a function nCount times
	Parameters	: The nCount as Number and the Function Name as string
*/
Func Times nCount,F
	for x = 1 to nCount 
		Call F()
	next

/*
	Function Name	: Map
	Usage		: Execute a function on each list item
	Parameters	: The List and the function as string
*/
Func Map aList,cFunc
	for x in aList
		x = call cFunc(x)
	next
	return aList

