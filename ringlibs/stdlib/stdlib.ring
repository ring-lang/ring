# The Ring Standard Library
# Common functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>
# 2016, CalmoSoft <calmosoft@gmail.com>

/*
	Function Name	: puts
	Usage		: print the value then print new line (nl)
	Parameters	: the value
*/
Func Puts vvalue
	see vvalue
	see nl

/*
	Function Name	: apppath
	Usage		: get the path of the application folder
	Parameters	: no Parameters
*/
Func AppPath
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
	Function Name	: value
	Usage		: create a copy from a list or object
	Parameters	: the list or the object
	output		: the new copy of the list or the object
*/
Func Value vlistorobj
	vlistorobj2 = vlistorobj
	return vlistorobj2

/*
	Function Name	: times
	Usage		: execute a Function ncount times
	Parameters	: the ncount as number and the Function Name as string
*/
Func Times ncount,f
	for x = 1 to ncount 
		call f()
	next

/*
	Function Name	: map
	Usage		: execute a Function on each list item
	Parameters	: the list and the Function as string
	output		: new list after applying the Function to each item
*/
Func Map alist,cFunc
	alist2 = alist
	for x in alist2
		x = call cFunc(x)
	next
	return alist2


/*
	Function Name	: filter
	Usage		: execute a Function on each list item to filter items
	Parameters	: the list and the Function as string
	output		: new list after filtering the items using the Function
*/
Func Filter alist,cFunc
	alist2 = []
	for x in alist
		if call cFunc(x)
			alist2 + x
		ok
	next
	return alist2


/*
	Function Name	: split
	Usage		: convert string words to list items
	Parameters	: the string to be converted
	output		: new list 
*/

Func Split cstring
	return str2list(substr(cstring," ",nl))
	
/*
	Function Name	: newlist
	Usage		: create a two dimensional list
	Parameters	: number of dimensions
	output		: two dimensional list 
*/

Func NewList x, y
     if isstring(x) x=0+x ok
     if isstring(y) y=0+y ok
     alist = list(x)
     for t in alist
         t = list(y)
     next
     return alist	

/*
	Function Name	: capitalized
	Usage		: return a copy with the first letter capitalized
	Parameters	: string to capitalize
	output		: capitalized string
*/

Func Capitalized str
       return substr(str,left(str,1),upper(left(str,1))) 
       
/*
	Function Name	: isspecial
	Usage		: check whether a character is special or not
	Parameters	: the character to be tested
	output		: the result of the test (0,1)
*/

Func IsSpecial char
       for c in "^'+-/\*~<>=@,%|&?!'"
           if char = c return true ok
       next
       return false 

/*
	Function Name	: isvowel
	Usage		: check whether a character is vowel or not
	Parameters	: the character to be tested
	output		: the result of the test (0,1)
*/

Func IsVowel char
       for c in "aeiou"
           if upper(char) = c return true ok
       next
       return false 
       
/*
	Function Name	: linecount
	Usage		: return the lines count in a text file.
	Parameters	: string contains the file name
	output		: the number of lines (lines count).
*/       
       
Func LineCount text
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
	Function Name	: factorial
	Usage		: return the factorial of a number.
	Parameters	: number for factorial.
	output		: factorial of a number.
*/

Func Factorial n if n = 1 return 1 else return n * factorial(n-1) ok

/*
	Function Name	: fibonacci
	Usage		: return the fibonacci number.
	Parameters	: number for fibonacci.
	output		: fibonacci number.
*/

Func Fibonacci n
    if n = 0 return 0 ok
    if n = 1 return 1 ok 
    if n > 1 return fibonacci(n-1) + fibonacci(n-2) ok
    
/*
	Function Name	: isprime
	Usage		: check whether a number is prime or not
	Parameters	: the number to be tested
	output		: the result of the test (0,1)
*/ 

Func IsPrime num
     if (num <= 1) return 0 ok
     if (num % 2 = 0) return 0 ok
     for i = 3 to floor(num / 2) - 1 step 2
         if (num % i = 0) return 0 ok
     next
     return 1
     
/*
	Function Name	: sign
	Usage		: returns an integer value indicating the sign of a number.
	Parameters	: the number to be tested.
	output		: the result of the test (-1,0,1).
*/	
	
Func Sign n
     if n < 0 return -1 ok
     if n = 0 return 0 ok
     if n > 0 return 1 ok 

/*
	Function Name	: List2File
	Usage		: Write list items to text file (each item in new line).
	Parameters	: The list to be written and the file name.
	output		: No Output
*/	

Func List2File aList,cFileName
	for x in aList if isnumber(x) x = "" + x ok next
	cStr = list2str(aList)
	if iswindows() cStr = substr(cStr,nl,windowsnl()) ok
	write(cFileName,cStr)

/*
	Function Name	: File2List
	Usage		: Read text file and convert lines to list items
	Parameters	: The file name.
	output		: The new list.
*/	
Func File2List cFileName
	cStr = read(cFileName)
	aList = str2list(cStr)
	return aList

/*
	Function Name	: Endswith
	Usage		: Returns true if the given string ends with the specified substring. Trailing white spaces are ignored.
	Parameters	: The original and substring
	output		: Returns the result of search (0,1)
*/

func Endswith str, substr
     str = trim(str)
     if right(str, len(substr)) = substr return 1 else return 0 ok 
     
/*
	Function Name	: Startwith
	Usage		: Returns true if the given string starts with the specified substring. Leading white spaces are ignored.
	Parameters	: The original and substring
	output		: Returns the result of search (0,1)
*/

func Startswith str, substr
     str = trim(str)
     if left(str, len(substr)) = substr return 1 else return 0 ok   
     
/*
	Function Name	: Gcd
	Usage		: Finding of the greatest common divisor of two integers.
	Parameters	: Two integers for gcd.
	output		: The greatest common divisor.
*/

func Gcd gcd, b
       while b
             c   = gcd
             gcd = b
             b   = c % b
       end
       return gcd
       
/*
	Function Name	: Lcm
	Usage		: Compute the least common multiple of two integers.
	Parameters	: Two integrs to compute.
	output		: The least common multiple.
*/     

func Lcm m,n
     lcm = m*n / gcd(m,n)
     return lcm
     
*
	Function Name	: Prodlist
	Usage		: Compute the product of a list of integers.
	Parameters	: List to compute
	output		: Product of a list.
*/

func Prodlist bList
       prod = 1
       for n = 1 to len(bList)
            prod *= bList[n]
       next
       return prod
