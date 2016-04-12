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
See "the number of lines = " + lineCount("C:\Ring\ReadMe.txt")

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

# Returns true if the given string ends with the specified substring. Trailing white spaces are ignored.
Puts("Test Endswith()")
see Endswith("CalmoSoft", "Soft") + nl
