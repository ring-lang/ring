// *** step 3
// number to words (hundreds)

load "stdlib.ring"   // need for string func.

n = "101"           // input
? "input: "+ n      // show input
? doWord(n)         // print the result in words

// -----------------------------------------------------------------------
func doWord(n)     // recursive (self-calling) function.
 ones=["one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]

 tens=["" , "twenty",  "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"]

// the zeros in the groups or whole null groups are not treated.

if n="000" see " Zero-Grp "+nl return end // a null group
if n="00" return end
if number(n)< 20        // 1-19 
  n = number(n)         // convert to num
  rtn = ones[n]         // ret value 
 elseif n < 100         // 20-99
  n=n*1                 // convert to num (another possible.)
  x = n % 10            // for ones
  y = floor(n / 10)     // for tens
  if x = 0 rtn = tens[y]
  else rtn = tens[y] +" "+ ones[x]  // whole tens
  end 
 elseif len(n) = 3      // first place: hundreds
  z = right(n,2)
  h = (floor(n / 100)) *1   // Find out the hundreds
  rtn = ones[h] +" hundred "
  rtn = rtn + doWord(z)     // And.. (Recursion)
 end //if
return rtn                  // pick up     
//? "doWord-rtn: "+rtn      // debug
//end-doWord()
