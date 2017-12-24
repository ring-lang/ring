/*
Trying out basic ring commands
Author: Rashad Kamsheh
Date: 2017-12-24
*/

load "stdlib.ring" // imports standard ring library

// testing the ? command
see "hello, world" + nl
TIL = "today i learned that "
text = "'?' prints out a string + a new line"
see TIL ? text

// testing standard library 
name = getString()
print("my name is  #{name}" + nl)

// summing up 2 given variables
put "enter number 1: " get number1
put "enter number 2: " get number2
put "sum: " +(0 + number1 + number2)

