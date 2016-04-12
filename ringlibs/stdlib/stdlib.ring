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
	Output		: Two dimensional list 
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
	Function Name	: Capitalized
	Usage		: Return a copy with the first letter capitalized
	Parameters	: String to capitalize
	Output		: Capitalized string
*/

func Capitalized str
       return substr(str,left(str,1),upper(left(str,1))) 
       
/*
	Function Name	: Isspecial
	Usage		: Check whether a character is special or not
	Parameters	: The Character to be tested
	Output		: The result of the test (0,1)
*/

func Isspecial char
       for c in "^'+-/\*~<>=@,%|&?!'"
           if char = c return true ok
       next
       return false 

/*
	Function Name	: Isvowel
	Usage		: Check whether a character is vowel or not
	Parameters	: The Character to be tested
	Output		: The result of the test (0,1)
*/

func Isvowel char
       for c in "AEIOU"
           if upper(char) = c return true ok
       next
       return false 
       
/*
	Function Name	: Linecount
	Usage		: Return the lines count in a text file.
	Parameters	: String contains the file name
	Output		: The number of lines (lines count).
*/       
       
func Linecount text
     number = 0
     fp = fopen(text,"r")
     r = fgetc(fp)
     while isstring(r)
           r = fgetc(fp)
           if r = char(10) number += 1 ok
     end
     fclose(fp)
     return number

/*
	Function Name	: Factorial
	Usage		: Return the factorial of a number.
	Parameters	: Number for factorial.
	Output		: Factorial of a number.
*/

func Factorial n if n = 1 return 1 else return n * Factorial(n-1) ok

/*
	Function Name	: Fibonacci
	Usage		: Return the Fibonacci number.
	Parameters	: Number for Fibonacci.
	Output		: Fibonacci number.
*/

func Fibonacci n
    if n = 0 return 0 ok
    if n = 1 return 1 ok 
    if n > 1 return Fibonacci(n-1) + Fibonacci(n-2) ok
    
/*
	Function Name	: Isprime
	Usage		: Check whether a number is prime or not
	Parameters	: The number to be tested
	Output		: The result of the test (0,1)
*/ 

func Isprime num
     if (num <= 1) return 0 ok
     if (num % 2 = 0) return 0 ok
     for i = 3 to floor(num / 2) - 1 step 2
         if (num % i = 0) return 0 ok
     next
     return 1

/*
	Function Name	: Startswith
	Usage		: Returns true if the given string starts with the specified substring. Leading white spaces are ignored.
	Parameters	: Original string and string to be tested.
	Output		: The result of the test (0,1). 
*/

func Startswith str, substr
     str = trim(str)
     if left(str, len(substr)) = substr return 1 else return 0 ok
