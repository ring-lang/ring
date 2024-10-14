# ------------ Variables (Numbers) Part 2 ------------
# Conversion
  x = 95
   # Way 1 
     myString  = string(x)          # Number To String
     myNumber  = number(mystring)   # String To Number
   # Way 2
   /* 
   * This Way Is Better Than Way 1 In Performance
   * Because, Operators Is Faster Than Functions.
   */
     myString2 = "" + x             # String + Number -> String
     myNumber2 = 0 + myString2      # Number + String -> Number 
