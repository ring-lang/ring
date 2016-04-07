Load "stdlib.ring"

# Application Path
See AppPath() + nl

# Execute a function nCount of times
Times ( 3 , func { see "Hello, World!" + nl } )

# Execute a function on each list item
See Map( 1:10, func x { return x*x } )

# Test the value function to copy a list or object
See value(1:10)
