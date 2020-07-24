// *** step 1
// number to words (units:)

ones=["one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven",
 "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]

n = "12"                 // input as string (the number can be any length)
? "input: "+ n           // for control only

if number(n) > 19       // test input
 ? "Incorrect input!"   // message
else
 ? ones[number(n)]      // ones-element nr: 12 output: twelve
ok
