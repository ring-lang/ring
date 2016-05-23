# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>
# 2016, CalmoSoft <calmosoft@gmail.com>

Load "stdlib.rh"
Load "stdclasses.ring"

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
	Parameters	: the string to be converted , the delimiter
			: delimiter can be char of choice. Example: " "  or  ","   or  "|" 
	output		: new list 
*/

Func Split cstring , delimiter
	return str2list(substr(cstring, delimiter, nl))

	
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

Func Endswith str, substr
     str = trim(str)
     if right(str, len(substr)) = substr return 1 else return 0 ok 
     
/*
	Function Name	: Startwith
	Usage		: Returns true if the given string starts with the specified substring. Leading white spaces are ignored.
	Parameters	: The original and substring
	output		: Returns the result of search (0,1)
*/

Func Startswith str, substr
     str = trim(str)
     if left(str, len(substr)) = substr return 1 else return 0 ok   
     
/*
	Function Name	: Gcd
	Usage		: Finding of the greatest common divisor of two integers.
	Parameters	: Two integers for gcd.
	output		: The greatest common divisor.
*/

Func Gcd gcd, b
       while b
             c   = gcd
             gcd = b
             b   = c % b
       end
       return gcd
       
/*
	Function Name	: Lcm
	Usage		: Compute the least common multiple of two integers.
	Parameters	: Two integers to compute.
	output		: The least common multiple.
*/     

Func Lcm m,n
     lcm = m*n / gcd(m,n)
     return lcm
     
/*
	Function Name	: Sumlist
	Usage		: Compute the sum of a list of integers.
	Parameters	: List to compute
	output		: Sum of a list.
*/ 

Func Sumlist bList
     sum = 0
     for n = 1 to len(bList)
         sum += bList[n]
     next
     return sum	
     
/*
	Function Name	: Prodlist
	Usage		: Compute the product of a list of integers.
	Parameters	: List to compute
	output		: Product of a list.
*/

Func Prodlist bList
     prod = 1
     for n = 1 to len(bList)
         prod *= bList[n]
     next
     return prod
     
/*
	Function Name	: Evenorodd
	Usage		: Test whether an integer is even or odd.
	Parameters	: Integer to test.
	output		: Result of test (1=odd 2=even).
*/     

Func Evenorodd n 
     if n % 2 = 1 return 1 ok
     return 2
     
/*
	Function Name	: Factors
	Usage		: Compute the factors of a positive integer.
	Parameters	: Integer to compute.
	output		: Result of compute.
*/  

Func Factors nArray    
     nArray = []
     j = 0
     for i = 1 to n
         if n % i = 0 j = j + 1 add(nArray, i) ok
     next
     return nArray
     
/*
	Function Name	: Palindrome
	Usage		: Check if a sequence of characters is a palindrome or not. 
	Parameters	: Characters to check.
	output		: Result of check.
*/  

Func Palindrome aString
     bString = ""
     for i=len(aString) to 1 step -1
         bString = bString + aString[i]
     next
     see aString
     if aString = bString see " is a palindrome." + nl
     else see " is not a palindrome" + nl ok
     
/*
	Function Name	: Isleapyear
	Usage		: Check whether a given year is a leap year in the Gregorian calendar. 
	Parameters	: Year to check.
	output		: Result of check.
*/

Func Isleapyear year
     if (year % 400) = 0 return true 
        but (year % 100) = 0 return false
        but (year % 4) = 0 return true
        else return false ok  
        
/*
	Function Name	: Binarydigits
	Usage		: Compute the sequence of binary digits for a given non-negative integer. 
	Parameters	: Integer to compute.
	output		: Result of compute.
*/   

Func Binarydigits a
     n = 0
     while pow(2,n+1) < a
           n = n + 1
     end
     for i = n to 0 step -1
         x = pow(2,i)
         if a >= x see 1 a = a - x
         else see 0 ok
     next
     
/*
	Function Name	: Matrixmulti
	Usage		: Multiply two matrices together. 
	Parameters	: Two matrices to multiply.
	output		: Result of multiply.
*/     

Func Matrixmulti A, B
     n = 3
     C = newlist(n,n)
     for i = 1 to n
         for j = 1 to n
             for k = 1 to n
                 C[i][k] += A[i][j] * B[j][k]  
             next
         next
     next
     for i = 1 to n
         for j = 1 to n
             see C[i][j] + " "
         next
         see nl
     next
     
/*
	Function Name	: Matrixtrans
	Usage		: Transpose an arbitrarily sized rectangular Matrix. 
	Parameters	: Two matrices to transpose.
	output		: Result of transpose.
*/     

Func Matrixtrans matrix
     transpose = newlist(5,4)
     for i = 1 to 5
         for j = 1 to 4
             transpose[i][j] = matrix[j][i]
             see "" + transpose[i][j] + " "
         next
         see nl
     next
     
/*
	Function Name	: Dayofweek
	Usage		: Return the day of the week of given date. (yyyy-mm-dd)
	Parameters	: Date to compute.
	output		: The day of the week.
*/

Func Dayofweek date
     year = number(substr(date,1,4))
     month = number(substr(date,6,2))
     day = number(substr(date,9,2))
     mo = [4,0,0,3,5,1,3,6,2,4,0,2]
     days = ["monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"]
     if year < 2100 leap = year - 1900 else leap = year - 1904 ok
     m = (((year-1900)%7) + floor(leap/4) + mo[month] + day) % 7
     switch m
            on 1 sday = days[4]
            on 2 sday = days[5]
            on 3 sday = days[6]
            on 4 sday = days[7]
            on 5 sday = days[1]
            on 6 sday = days[2]
            on 0 sday = days[3]
     off
     see "" + year + "-" + month + "-" + day + " is : " + sday + nl
     
/*
	Function Name	: Fridays
	Usage		: Fridays the 13th between start and end year.
	Parameters	: Start and end year.
	output		: Dates of Fridays od 13th.
*/  

Func Fridays year1, year2
     mo = [4,0,0,3,5,1,3,6,2,4,0,2]
     for year = year1 to year2
         if year < 2100 leap = year - 1900 else leap = year - 1904 ok
         for month = 1 to 12
             m = (((year-1900)%7) + floor(leap/4) + mo[month] + 13) % 7
             if month < 10 smonth = "0" + month ok
             if m = 2 see "" + year + "-" + smonth + "-" + "13 is friday" + nl ok
         next
     next
     
/*
	Function Name	: Permutation
	Usage		: Generates all permutations of n different numerals.
	Parameters	: List of numerals to generate.
	output		: Permutations of numerals.
*/     

Func Permutation a
       elementcount = len(a)
       if elementcount < 1 then return ok
       pos = elementcount-1
       while a[pos] >= a[pos+1] 
               pos -= 1
               if pos <= 0 permutationReverse(a, 1, elementcount)
                  return ok
       end
       last = elementcount
       while a[last] <= a[pos]
               last -= 1
       end
       temp = a[pos]
       a[pos] = a[last]
       a[last] = temp
       permutationReverse(a, pos+1, elementcount)

Func permutationReverse a, first, last
        while first < last
                 temp = a[first]
                 a[first] = a[last]
                 a[last] = temp
                 first += 1
                 last -= 1
        end
   
/*
	Function Name	: Sleep
	Usage		: Sleep for the given amount of time.
	Parameters	: Time for sleep.
	output		: Result of sleeping.
*/          
     
Func Sleep x
	nTime = x * C_SECONDSIZE
	if isclass("qTest")
		oTest = new qTest
		oTest.qsleep(nTime)
	else
		nClock = clock()
		while clock() - nClock < nTime end
	ok
     
/*
	Function Name	: Readline
	Usage		: Read a file line by line.
	Parameters	: File to read.
	output		: Result of reading.
*/      
      
Func Readline fp
	if not feof(fp) 
		r = fgets(fp,C_LINESIZE) 
		if r != NULL Return r ok
	ok


/*
	Function Name	: IsMainSourceFile
	Usage		: Check if the current file is the main source file
	Parameters	: No Paramters 
	output		: True/False 
*/      
Func IsMainSourceFile
	if filename() = sysargv[2]
		return true
	ok
	return false
	
/*
	Function Name	: Substring
	Usage		: Return a position of a substring starting form a given position in a string.
	Parameters	: String, substring, position. 
	output		: Position of substring. 
*/  	
func Substring str,substr,n
       newstr=right(str,len(str)-n+1)
       nr = substr(newstr, substr)
       return n + nr -1
