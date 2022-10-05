/*
 * Application   : All application on lec2
 * Author        : Mohammed Azzam
 * Date          : 28.12.2018
 */

see 'Enter two numbers to give you sum' + nl 
see "Enter first  number: " give number1  // First  way of output & input
put 'Enter second number: ' get  number2  // Second way of output & input
number1 = number(number1)                 // First  way to convert string to number
put 'sum ='? number1 + number2            // Second way to convert string to number

load "stdlib.ring"                        // Using library
print("Enter your name: ")
your_name = getstring()
print ("Hello #{your_name}")
