/*
 Applecation   :All applecation on lec2
 Author        :Mohammed Azzam
 Date          : 28.12.2018
*/
see 'enter tow numbers to give you sum'+nl 
see "Enter firest number" give number1    // First way of output & input
put 'Enter second number' get number2     // second way of output & input
number1 =number(number1)                  // First way to convrt string to number
put 'sum ='? number1 +number2             // second way to convrt string to number

load "stdlib.ring"                        // Using library
print("Enter your name")
nam = getstring()
print ("Hello #{nam}")
