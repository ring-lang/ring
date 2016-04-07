Load "stdlib.ring"

# Application Path
see AppPath() + nl

# Execute a function nCount of times
Times ( 3 , func { see "Hello, World!" + nl } )

# Execute a function on each list item
aList = 1:10
See Map( aList, func x { return x*x } )

