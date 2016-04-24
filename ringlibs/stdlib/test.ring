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
See Split("one two three four five")

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
leap = Isleapyear(year)
if leap true see "" + year + " is a leap year."
else see "" + year + " is not a leap year." ok

# Compute the sequence of binary digits for a given non-negative integer.
Puts("Test Binarydigits()")
b = 35
see "Binary digits of " + b + " = "
Binarydigits(b)

# Multiply two matrices together.
Puts("Test Matrixmulti()")
A = [[1,2,3], [4,5,6], [7,8,9]]
B = [[1,0,0], [0,1,0], [0,0,1]]
Matrixmulti(A, B)

# Transpose an arbitrarily sized rectangular Matrix.
Puts("Test Matrixtrans()")
matrix = [[78,19,30,12,36], [49,10,65,42,50], [30,93,24,78,10], [39,68,27,64,29]]
Matrixtrans(matrix)

# Return the day of the week of given date.
Puts("Test Dayofweek()")
date = "2016-04-24"
Dayofweek(date)



