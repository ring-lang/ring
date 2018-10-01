# The Ring Standard Library
# Common Functions and classes for applications
# 2016-2017, Mahmoud Fayed <msfclipper@yahoo.com>
# 2016-2017, CalmoSoft <calmosoft@gmail.com>

Load "stdlib.rh"
Load "stdfunctions.ring"

/*
	Function Name	: puts
	Usage		: print the value then print new line (nl)
	Parameters	: the value
*/
Func Puts vvalue
	see vvalue
	see nl

/*
	Function Name	: print
	Usage		: print string - support \n \t \r \\ #{variable}
	Parameters	: the string
*/
Func Print vValue
	if isstring(vValue)
		see _Print2Str(vValue,3)
	else
		see vValue 
	ok

/*
	Function Name	: print2str
	Usage		: print to string - support \n \t \r \\ #{variable}
	Parameters	: the string
*/
Func Print2Str vValue
	# Pass Three Scopes 
	if isnumber(vValue)
		vValue = "" + vValue 
	ok
	if isstring(vValue)
		return _Print2Str(vValue,3)
	else 
		raise("Type Error : Print2Str() Accept Strings/Numbers Only!")
	ok

/*
	Function Name	: _print2str
	Usage		: Internal function - print to string 
	Parameters	: the string , Scopes to pass 
*/
Func _Print2Str vValue,nScope
	cString = ""
	for t = 1 to len(vValue)
		switch vValue[t]
		on "\"
			t++
			switch vValue[t]
			on "\"
				cString +=  "\"
			on "n"
				cString +=  nl
			on "t"
				cString +=  char(9)
			on "r" 
				cString +=  char(13)
			off
		on "#"
			if vValue[t+1] = "{"
				cVar = ""
				for r=t+2 to len(vValue)
					if vValue[r] != "}"
						cVar += vValue[r]
					else
						exit
					ok					
				next
				# Access Local Variables in the Caller
				if not find(globals(),lower(cVar))
					aMem = ringvm_memorylist()
					if len(aMem) > 1
						# -2 to avoid two scopes 
						# scope used by ringvm_memorylist() 
						# scope used by _print2str() 
						aList = aMem[len(aMem)-nScope]
						nPos = find(aList,lower(cVar),1)
						if nPos 
							cVar = "aList[nPos][3]"
						ok
					ok
				else 
					aMem = ringvm_memorylist()
					aList = aMem[1]
					nPos = find(aList,lower(cVar),1)
					if nPos 
						cVar = "aList[nPos][3]"
					ok
				ok
				cCode = "cString += " + cVar				
				eval(cCode)
				t = r
			ok
		other
			cString +=  vValue[t]
		off
	next
	return cString


/*
	Function Name	: getstring
	Usage		: get input using the keyboard
	Parameters	: no Parameters
*/
Func GetString
	Give _temp_get_string
	return _temp_get_string


/*
	Function Name	: getnumber
	Usage		: get input using the keyboard - return number
	Parameters	: no Parameters
*/
Func GetNumber
	Give _temp_get_number
	return 0 + _temp_get_number

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
	Function Name	: JustFilePath
	Usage			: get the path of the file only - remove file name
	Parameters		: File Name
*/

func JustFilePath cFile
	for x = len(cfile) to 1 step -1
		if cfile[x] = "\" or cfile[x] = "/"
			cfile = left(cfile,x)
			return cFile
		ok
	next
	return ""

/*
	Function Name	: JustFileName
	Usage			: get the Name of the file only - remove file path
	Parameters		: File Name
*/

func JustFileName cFile
	for x = len(cfile) to 1 step -1
		if cfile[x] = "\" or cfile[x] = "/"
			cfile = substr(cfile,x+1)
			exit
		ok
	next
	return cFile 

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

Func Split(cString, delimiter)

    doubleSpace = "  "
    singleSpace = " "
    singleTab   = char(9)
	
    if ( (delimiter = singleTab) or (delimiter = singleSpace) )
        delimiter = singleSpace
    ok

    if ( delimiter = singleSpace )
        do
            cString = substr(cstring, singleTab, singleSpace)   ### Replace Tab with Space
        again substr(cString, singleTab)

        do
            cString = substr(cString, doubleSpace, singleSpace) ### Replace DoubleSpace with Space
        again substr(cString, doubleSpace)
    ok
	
	cString = trim(cString) ### Remove leading and trailing spaces
    cStrList = str2list(substr(cString, delimiter, nl))

return cStrList

/*
	Function Name	: SplitMany
	Usage		: convert string words to list items
	Parameters	: the string to be converted , the delimiter characters
			: delimiter can be many characters written in one string or List 
	output		: new list 
*/

Func SplitMany cString,cCharacters
	for t in cCharacters
		cString = substr(cString,t,nl)
	next 
	return str2list(cString)


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

Func Factorial n if n = 0 return 1 else return n * factorial(n-1) ok

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
     if (num % 2 = 0)  and (num != 2)  return 0 ok
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

Func Factors n   
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
     if aString = bString return 1 ok
     return false
     
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
	 cOutput = ""
     n = 0
     while pow(2,n+1) < a
           n = n + 1
     end
     for i = n to 0 step -1
         x = pow(2,i)
         if a >= x cOutput += "1" a = a - x
         else cOutput += "0" ok
     next
	 return cOutput
     
/*
	Function Name	: Matrixmulti
	Usage		: Multiply two matrices together. 
	Parameters	: Two matrices to multiply.
	output		: Result of multiply.
*/     

Func Matrixmulti A, B
	n = len(A)
	C = newlist(n,n)
	for i = 1 to n
		for j = 1 to n
			for k = 1 to n
				C[i][k] += A[i][j] * B[j][k]  
			next
		next
	next
	return C
     
/*
	Function Name	: Matrixtrans
	Usage		: Transpose an arbitrarily sized rectangular Matrix. 
	Parameters	: Two matrices to transpose.
	output		: Result of transpose.
*/     

Func Matrixtrans matrix
	rows = len(matrix)
	cols = len(matrix[1])	
	transpose = newlist(cols,rows)
	for i = 1 to cols
		for j = 1 to rows
			transpose[i][j] = matrix[j][i]             
		next         
	next
	return transpose
	 
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
     return sday 
     
/*
	Function Name	: Fridays
	Usage		: Fridays the 13th between start and end year.
	Parameters	: Start and end year.
	output		: Dates of Fridays on 13th.
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
	nClock = clock()
	while clock() - nClock < nTime end
     
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
	if len(sysargv) >= 2
		if PrevFileName() = substr(sysargv[2],"ringo","ring")
			return true
		ok
	else    # We are using Ring2EXE and we have executable code 
		if Prevfilename() = substr(ringvm_fileslist()[1],"ringo","ring")
			return true 
		ok
	ok
	return false

/*
	Function Name	: Substring
	Usage		: Return a position of a substring starting from a given position in a string.
	Parameters	: String, substring, position. 
	output		: Position of substring. 
*/  	
func Substring str,substr,n
       newstr=right(str,len(str)-n+1)
       nr = substr(newstr, substr)
       if nr = 0
          return 0
       else
          return n + nr -1
       ok
       
/*
	Function Name	: Changestring
	Usage		: Change substring from given position for given position with a substring.
	Parameters	: Original string, position, length, substring
	output		: Result string. 
*/         
func Changestring text, pos1, pos2, str
       string = left(text,pos1-1) + str + substr(text, pos2+1)
       return string


/*
	Function Name	: DirExists
	Usage		: Check if directory exists
	Parameters	: Path
	output		: True/False
*/         

Func DirExists cDir
	try
		dir(cDir)
		return true
	catch
		return false
	done


/*
	Function Name	: MakeDir
	Usage		: Make Directory
	Parameters	: Directory Name
*/         

Func MakeDir cFolder
	if iswindows()
		SystemSilent("mkdir " + cFolder)
	else 
		# -p :  parents, will also create all directories leading up to the given directory that do not exist already. 
		#       If the given directory already exists, ignore the error.
		SystemSilent("mkdir -p " + cFolder)
	ok
	
/*
	Function Name	: sortFirstSecond
	Usage		: Sort a list on first or second index
	Parameters	: list to sort
	output          : sorted list 
*/ 

Func sortFirstSecond aList, ind
        aList = sort(aList,ind)
        for n=1 to len(alist)-1
             for m=n to len(aList)-1 
                   if ind = 1 nr = 2 else nr = 1 ok
                   if alist[m+1][ind] = alist[m][ind] and alist[m+1][nr] < alist[m][nr]
                      temp = alist[m+1]
                      alist[m+1] = alist[m]
                      alist[m] = temp ok
             next
       next
       return aList

Func Fsize(fh)
	Fseek(fh,0,2)
	size = Ftell(fh)
	Fseek(fh,0,0)
	return size

/*------------
 + EpochTime()
 + Example:  EpochSec = EpochTime( Date(), Time() )
 + Format:   EpochSec = EpochTime( "15/07/2016", "10:15:30" )
 + Output:   EpochSec = 1468577730
 +------------
*/

Func EpochTime(Date, Time)

    arrayDate = split(Date, "/")
    arrayTime = split(Time, ":")

    Year = arrayDate[3] ; Month  = arrayDate[2] ; Day    = arrayDate[1]
    Hour = arrayTime[1] ; Minute = arrayTime[2] ; Second = arrayTime[3]

    cDate1    = Day +"/"+ Month +"/"+ Year
    cDate2    = "01/01/" + Year
    DayOfYear = DiffDays( cDate1, cDate2)

    ### Formula
    tm_sec  = Second    * 1
    tm_min  = Minute    * 60
    tm_hour = Hour      * 3600
    tm_yday = DayOfYear * 86400
    tm_year = Year      - 1900

    tm_year1 =         ( tm_year -  70)          * 31536000
    tm_year2 = ( floor(( tm_year -  69) /   4 )) * 86400
    tm_year3 = ( floor(( tm_year -   1) / 100 )) * 86400
    tm_year4 = ( floor(( tm_year + 299) / 400 )) * 86400

    ### Result
    EpochSec = tm_sec + tm_min + tm_hour + tm_yday + tm_year1 + tm_year2 - tm_year3 + tm_year4

return EpochSec

Func TrimLeft(cStr)
  $tab   = char(09)
  $space = char(32)
  index  = 1
      while cStr[index] = $space or cStr[index] = $tab
            index++
      end  
  cStr = substr(cStr, index, len(cStr) - index + 1)
return cStr     


Func TrimRight(cStr)
  $tab   = char(09)
  $space = char(32)
  index  = len(cStr)
      while cStr[index] = $space or cStr[index] = $tab
            index--
      end    
  cStr = substr(cStr, 1, index)
return cStr     


Func TrimAll(cStr)
  $tab   = char(09)
  $space = char(32)
  $empty = ""
    cStr = substr(cStr, $space, $empty)
    cStr = substr(cStr, $tab,   $empty)
return cStr

/*
   Remove NewLine chars
*/

Func chomp(cStr)
   cStr = substr(cStr, nl, "" )
return cStr


/*
   SystemCmd() outputs to Variable
   Example: cYou = SystemCmd("whoami")
   See "SystemCmd: whoami ====="+ nl + cYou +nl
*/

Func SystemCmd(cmd)
   System(cmd + "> cmd.txt")
   cStr = read("cmd.txt")
return cStr

/*
	Get a List of all files in a directory and it's sub directories 
	Parameters : Path as String
					  Extension as String, example "ring"
	Output : List contains the files only 
	Note : (1) Each sub directory will be opened 
			 (2) if the extension is empty, all files will be included

	Examples
			aList = ListAllFiles("b:/ring/ringlibs","ring") # *.ring only
			aList = sort(aList)
			see aList
	Example 
			load "stdlib.ring"
			see listallfiles("b:/ring/ringlibs/weblib","") # All Files
*/

func ListAllFiles cPath,cExt
	if left(cExt,2) = "*."
		cExt = substr(cExt,3)
	ok
	aList = dir(cPath)
	return ListAllFiles_process(cPath,aList,cExt)

func ListAllFiles_Process cPath,aList,cExt
	aOutput = []
	for aSub in aList 
		# Workaround a bug in Linux, when aSub[2] = True for files (not folders)
			if aSub[1] = "." or aSub[1] = ".."
				loop
			ok
			if aSub[2] and substr(aSub[1],".")
				aSub[2] = 0
			ok
		if aSub[2] # Directory
			cNewPath = cPath + "/" + aSub[1]
			aSubOutput = listAllFiles(cNewPath,cExt)
			for item in aSubOutput 
				aOutput + item
			next
		else		# File
			if cExt != NULL
				if right(aSub[1],len(cExt)+1) = "."+cExt 
					aOutput + ( cPath + "/" + aSub[1] )
				ok
			else
				aOutput + ( cPath + "/" + aSub[1] )
			ok
		ok
	next
	return aOutput

/*
	Function Name	: SystemSilent
	Usage 		: Execute system command without displaying the output 
	Parameters   	: Command as String 
	Output		: None
*/

func SystemSilent cCmd
	if isWindows()
		system(cCmd + C_WINDOWS_NOOUTPUTNOERROR)
	else 
		system(cCmd + C_LINUX_NOOUTPUTNOERROR)
	ok


/*
	Create folder then change the current folder to this new folder 
*/
func OSCreateOpenFolder cFolder
	MakeDir(cFolder)
	chdir(cFolder)

/*
	Copy folder to the current folder 
	Parameters : The path to the parent folder of the Source  and the folder name
*/

func OSCopyFolder cParentFolder,cFolder
	cCurrentFolder = currentdir()
	OSCreateOpenFolder(cFolder)
	if isWindows()
		systemsilent("copy " + cParentFolder + cFolder)
	else 
		systemsilent("cp -R " + cParentFolder + cFolder + " ./")
	ok
	chdir(cCurrentFolder)

/*
	Delete Folder in the current Directory
*/

func OSDeleteFolder cFolder 
	if isWindows() 
		systemSilent("rd /s /q " + cFolder)
	else
		systemSilent("rm -r " + cFolder)
	ok

/*
	Copy File to the current directory
*/
func OSCopyFile cFile
	if isWindows()
		cFile = substr(cFile,"/","\")
		systemSilent("copy " + cFile)
	else 
		systemSilent("cp " + cFile + " .")
	ok

/*
	Delete file 
*/

func OSDeleteFile cFile
	if isWindows() 
		systemSilent("del " + cFile)
	else 
		systemSilent("rm " + cFile)
	ok

/*
	Rename File 
*/
func OSRenameFile cOldFile,cNewFile
	if isWindows()
		systemSilent("rename " + cOldFile + " " + cNewFile)
	but isLinux() or isMacosx()
		systemSilent("mv " + cOldFile + " " + cNewFile)
	ok

/*
	Convert a Ring List to Ring source code 
*/
func List2Code aList
	cCode = "["+Windowsnl()
	lStart = True
	for item in aList 
		if !lStart 
			cCode += ","
		else 
			lStart = False
		ok
		if isString(item) 
			cCode += '"' + item + '"' 
		but isnumber(item)
			cCode += (""+item)
		but islist(item)
			cCode += List2Code(item)
		ok
	next
	cCode += windowsnl()+"]"
	return cCode


/*
	Convert string to a List of numbers 
	Where each number is the ASCII code of a character 
*/
	func Str2ASCIIList cStr 
		if not isString(cStr)
			raise("Type Error in Str2ASCIIList() function")
		ok
		aList = []
		for cChar in cStr 
			aList + ASCII(cChar)
		next 
		return aList 

/*
	Convert List of numbers where each number is the ASCII code of character 
	To String 
*/
	func ASCIIList2Str aList 
		if not isList(aList)
			raise("Type Error in ASCIIList2Str() function")
		ok
		cStr = ""
		for nNum in aList 
			if not isNumber(nNum)
				raise("Type Error in ASCIIList2Str() function - Item is not a number!")
			ok
			cStr += char(nNum)
		next 
		return cStr 
