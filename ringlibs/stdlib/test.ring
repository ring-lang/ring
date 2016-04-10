Load "stdlib.ring"

# Application Path
puts("Test AppPath()")
See AppPath() + nl

# Execute a function nCount of times
puts("Test Times()")
Times ( 3 , func { see "Hello, World!" + nl } )

# Execute a function on each list item
puts("Test Map()")
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
see "Enter array 1 greater than 0 : " give a1 see nl
see "Enter array 2 greater than 0 : " give a2 see nl
chrArray = newlist(a1,a2)
numArray = newlist(a1,a2)
chrArray[1][1] = "Hello"
numArray[1][1]  = 987.2
see chrArray[1][1] + nl
see numArray[1][1] + nl

