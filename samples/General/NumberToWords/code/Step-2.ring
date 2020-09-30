// *** step 2
// number to words (tens)

load "stdlib.ring"				// need for string func.

// units:
ones=["one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven",
"twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]

// tens: (whole numbers)
tens=["" , "twenty",  "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"]

n = "29"
? "len(n): "+len(n)         // n: is string
? "first digit: "+n[1]      // first digit
? "second digit: "+n[2]     // second digit
? "input: "+ n

if number(n) > 99           // test 
 ? "Incorrect input!"       // message
end

if number(n[1]) > 1 and number(n[2]) > 0
  ? tens[number(n[1])] +"-"+ ones[number(n[2])]
elseif number(n[2]) = 0
  ? tens[number(n[1])]
end
