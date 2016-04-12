# the ring standard library
# common functions and classes for applications
# 2016, mahmoud fayed <msfclipper@yahoo.com>
# 2016, calmosoft <calmosoft@gmail.com>

/*
	function name	: puts
	usage		: print the value then print new line (nl)
	parameters	: the value
*/
func puts vvalue
	see vvalue
	see nl

/*
	function name	: apppath
	usage		: get the path of the application folder
	parameters	: no parameters
*/
func apppath
	cfile = sysargv[2] # the main file
	update = false
	for x = len(cfile) to 1 step -1
		if cfile[x] = "\" or cfile[x] = "/"
			cfile = left(cfile,x)
			update = true
			exit
		ok
	next
	if update = true
		if cfile[1] != "/" and cfile[2] != ":"
			cpath = currentdir() + "\" + cfile
		else
			cpath = cfile
		ok
	else
		cpath = currentdir()
	ok
	if right(cpath,1) != "\" and right(cpath,1) != "/" cpath += "/" ok
	return cpath

/*
	function name	: value
	usage		: create a copy from a list or object
	parameters	: the list or the object
	output		: the new copy of the list or the object
*/
func value vlistorobj
	vlistorobj2 = vlistorobj
	return vlistorobj2

/*
	function name	: times
	usage		: execute a function ncount times
	parameters	: the ncount as number and the function name as string
*/
func times ncount,f
	for x = 1 to ncount 
		call f()
	next

/*
	function name	: map
	usage		: execute a function on each list item
	parameters	: the list and the function as string
	output		: new list after applying the function to each item
*/
func map alist,cfunc
	alist2 = alist
	for x in alist2
		x = call cfunc(x)
	next
	return alist2


/*
	function name	: filter
	usage		: execute a function on each list item to filter items
	parameters	: the list and the function as string
	output		: new list after filtering the items using the function
*/
func filter alist,cfunc
	alist2 = []
	for x in alist
		if call cfunc(x)
			alist2 + x
		ok
	next
	return alist2


/*
	function name	: split
	usage		: convert string words to list items
	parameters	: the string to be converted
	output		: new list 
*/

func split cstring
	return str2list(substr(cstring," ",nl))
	
/*
	function name	: newlist
	usage		: create a two dimensional list
	parameters	: number of dimensions
	output		: two dimensional list 
*/

func newlist x, y
     if isstring(x) x=0+x ok
     if isstring(y) y=0+y ok
     alist = list(x)
     for t in alist
         t = list(y)
     next
     return alist	

/*
	function name	: capitalized
	usage		: return a copy with the first letter capitalized
	parameters	: string to capitalize
	output		: capitalized string
*/

func capitalized str
       return substr(str,left(str,1),upper(left(str,1))) 
       
/*
	function name	: isspecial
	usage		: check whether a character is special or not
	parameters	: the character to be tested
	output		: the result of the test (0,1)
*/

func isspecial char
       for c in "^'+-/\*~<>=@,%|&?!'"
           if char = c return true ok
       next
       return false 

/*
	function name	: isvowel
	usage		: check whether a character is vowel or not
	parameters	: the character to be tested
	output		: the result of the test (0,1)
*/

func isvowel char
       for c in "aeiou"
           if upper(char) = c return true ok
       next
       return false 
       
/*
	function name	: linecount
	usage		: return the lines count in a text file.
	parameters	: string contains the file name
	output		: the number of lines (lines count).
*/       
       
func linecount text
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
	function name	: factorial
	usage		: return the factorial of a number.
	parameters	: number for factorial.
	output		: factorial of a number.
*/

func factorial n if n = 1 return 1 else return n * factorial(n-1) ok

/*
	function name	: fibonacci
	usage		: return the fibonacci number.
	parameters	: number for fibonacci.
	output		: fibonacci number.
*/

func fibonacci n
    if n = 0 return 0 ok
    if n = 1 return 1 ok 
    if n > 1 return fibonacci(n-1) + fibonacci(n-2) ok
    
/*
	function name	: isprime
	usage		: check whether a number is prime or not
	parameters	: the number to be tested
	output		: the result of the test (0,1)
*/ 

func isprime num
     if (num <= 1) return 0 ok
     if (num % 2 = 0) return 0 ok
     for i = 3 to floor(num / 2) - 1 step 2
         if (num % i = 0) return 0 ok
     next
     return 1
     
/*
	function name	: sign
	usage		: returns an integer value indicating the sign of a number.
	parameters	: the number to be tested.
	output		: the result of the test (-1,0,1).
*/	
	
func sign n
     if n < 0 return -1 ok
     if n = 0 return 0 ok
     if n > 0 return 1 ok 
