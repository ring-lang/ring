# The Ring Standard Library
# Common Functions and Classes for Applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>
# 2016, CalmoSoft <calmosoft@gmail.com>

/*
	Function Name	: Puts
	Usage		: Print the value then print new line (NL)
	Parameters	: The Value
*/
Func Puts vValue
	See vValue
	See nl

/*
	Function Name	: AppPath
	Usage		: Get the path of the application folder
	Parameters	: No Parameters
*/
Func AppPath
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
	Function Name	: Value
	Usage		: Create a copy from a list or object
	Parameters	: The List or the object
	Output		: The new copy of the List or the object
*/
Func Value vListOrObj
	vListOrObj2 = vListOrObj
	return vListOrObj2

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
	Output		: New List after applying the function to each item
*/
Func Map aList,cFunc
	aList2 = aList
	for x in aList2
		x = call cFunc(x)
	next
	return aList2


/*
	Function Name	: Filter
	Usage		: Execute a function on each list item to filter items
	Parameters	: The List and the function as string
	Output		: New List after filtering the items using the function
*/
Func Filter aList,cFunc
	aList2 = []
	for x in aList
		if call cFunc(x)
			aList2 + x
		ok
	next
	return aList2


/*
	Function Name	: Split
	Usage		: Convert String Words to List Items
	Parameters	: The String to be converted
	Output		: New List 
*/

Func Split cString
	return str2list(substr(cString," ",nl))
	
/*
	Function Name	: Newlist
	Usage		: Create a two dimensional list
	Parameters	: Number of dimensions
	Output		: Two Dimensional List 
*/

Func Newlist x, y
     if isstring(x) x=0+x ok
     if isstring(y) y=0+y ok
     aList = list(x)
     for t in aList
         t = list(y)
     next
     return aList
     
/*
	Function Name	: Isspecial
	Usage		: Test if the string containes special characters
	Parameters	: String to test
	Output		: Result of test 
*/     

func Isspecial char
     for c in "^'+-/\*~<>=@,%|&?!'"
         if char = c return true ok
     next
     return false 
