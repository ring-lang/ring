# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>
# 2016, CalmoSoft <calmosoft@gmail.com>
Load "stdlib.ring"

# Application Path
Puts("Test AppPath()")
See AppPath() + nl

# Execute a function nCount of times
Puts("Test Times()")
Times ( 3 , func { see "Hello, World!" + nl } )

# Execute a function on each list item
Puts("Test Map()")
See Map( 1:10, func x { return x*x } )

# Test the Value function to copy a list or object
Puts("Test Value()")
See value(1:10)

# Test the Filter function
Puts("Test Filter()")
See Filter( 1:10 , func x { if x <= 5 return true else return false ok } )

# Test the Split function
Puts("Test Split()")
See Split("one two three four five"," ")

# Test the Newlist function
Puts("Test Newlist()")
a1 = 3
a2 = 5
chrArray = newlist(a1,a2)
numArray = newlist(a1,a2)
chrArray[1][1] = "Hello"
numArray[1][1]  = 987.2
See chrArray[1][1] + nl
See numArray[1][1] + nl

# Return a copy with the first letter capitalized
Puts("Test Capitalized()")
See capitalized("welcome to the Ring Programming Language")

# Test if the character is a special character?
Puts("Test Isspecial()")
See "Isspecial  = " + isSpecial("%") + nl

# Test if the character is a vowel character?
Puts("Test Isvowel()")
See "Isvowel = " + isVowel("c") + nl

# Return the number of lines (lines count) in a text file
Puts("Test Linecount()")
See "the number of lines = " + lineCount("test.ring")

# Return the factorial of number
Puts("Test Factorial()")
see "6 factorial is : " + Factorial(6)

# Return the Fibonacci number
Puts("Test Fibonacci()")
see "6 Fibonacci is : " + Fibonacci(6)

# Check whether a number is prime or not
Puts("Test Isprime()")
flag = isPrime(16)
if flag = 1 see "16 is a prime number"
else see "16 is not a prime number" ok

# Returns an Integer value indicating the sign of a number.
Puts("Test Sign()")
see "sign of 12 is = " + sign(12) + nl

# Test List2File
Puts("Test List2File()")
list2file(1:100,"myfile.txt")

# Test File2List
Puts("Test File2List()")
see len(file2list("myfile.txt"))

# Returns true if the given string ends with the specified substring. Trailing white spaces are ignored.
Puts("Test Endswith()")
see endsWith("CalmoSoft", "Soft") + nl

# Returns true if the given string starts with the specified substring. Leading white spaces are ignored.
Puts("Test Startswith()")
see Startswith("CalmoSoft", "Calmo") + nl

# Finding of the greatest common divisor of two integers.
Puts("Test Gcd()")
see gcd (24, 32) + nl

# Compute the least common multiple of two integers.
Puts("Test Lcm()")
see Lcm(24,36) + nl

# Compute the product of a list of integers.
Puts("Test Prodlist()")
aList = [1,2,3,4,5]
see Prodlist(aList) + nl

# Compute the sum of a list of integers.
Puts("Test Sumlist()")
aList = [1,2,3,4,5]
see Sumlist(aList) + nl

# Compute the sum of a list of integers.
Puts("Test Evenorodd()")
nr = 17
see Evenorodd(nr) + nl

# Compute the factors of a positive integer.
Puts("Test Factors()")
n = 45
aList = factors(n)
see "Factors of " + n + " = "
for i = 1 to len(aList)
    see "" + aList[i] + " "
next

# Check if a sequence of characters is a palindrome or not.
Puts("Test Palindrome()")
cString = "radar"
Palindrome(cString)

# Check whether a given year is a leap year in the Gregorian calendar.
Puts("Test Isleapyear()")
year = 2016
if Isleapyear(year) see "" + year + " is a leap year."
else see "" + year + " is not a leap year." ok

# Compute the sequence of binary digits for a given non-negative integer.
Puts("Test Binarydigits()")
b = 35
see "Binary digits of " + b + " = "
see Binarydigits(b) + nl

# Multiply two matrices together.
Puts("Test Matrixmulti()")
A = [[1,2,3], [4,5,6], [7,8,9]]
B = [[1,0,0], [0,1,0], [0,0,1]]
see Matrixmulti(A, B)

# Transpose an arbitrarily sized rectangular Matrix.
Puts("Test Matrixtrans()")
matrix = [[78,19,30,12,36], [49,10,65,42,50], [30,93,24,78,10], [39,68,27,64,29]]
see Matrixtrans(matrix)

# Return the day of the week of given date.
Puts("Test Dayofweek()")
date = "2016-04-24"
see "Data : " + date + " - Day : " + Dayofweek(date) + nl

# Friday the 13th between start and end year.
Puts("Test Fridays()")
year1 = 2010
year2 = 2020
Fridays(year1, year2)

# Generates all permutations of n different numerals
Puts("Test Permutation()")
list = [1, 2, 3, 4]
for perm = 1 to 24
     for i = 1 to len(list)
          see list[i] see " "
     next
     see nl
     Permutation(list)
next


# Sleep for the given amount of time.
Puts("Test Sleep()")
see "Wait 3 Seconds!"
Sleep(3)
see nl

# Read a file line by line.
Puts("Test Readline()")
fp = fopen("test.ring","r")
while not feof(fp)
See Readline(fp) end
fclose(fp)

# Return a position of a substring starting from a given position in a string.
Puts("Test Substring()")
a = "abcxyzqweabc"
b = "abc"
i = 4
see substring(a,b,i)

# Change substring from given position for given position with a substring.
Puts("Test Changestring()")
see Changestring("Rmasdg",2,5,"in")

# Test print()
print("\nHello, World\n\nHow are you? \t\t I'm fine!\n")
x=10 y=20
print("\nx value = #{x} , y value = #{y} \n")

# Check directory
see "Check dir : b:\ring " 
puts( DirExists("b:\ring") )
see "Check dir : C:\ring " 
Puts( DirExists("C:\ring") )

# Create Directory
puts("create Directory : myfolder")
makedir("myfolder")

# Test GetString() and GetNumber()
See "Test getstring() and getnumber()"+nl
See "Enter your name ?" 
cName = getstring()
see "Your name is : " + cName + nl
See "Enter your Age? "
nAge = getnumber()
nAge++
See "Your age after 1 year : " + nAge + nl

# Test Main Source File
see "IsMainSourceFile() : " + ismainsourcefile() + nl
See "Previous File Name : " + PrevFileName() + nl
see "IsMainSourceFile() : " + ismainsourcefile() + nl

