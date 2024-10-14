/*
	Application  	: Using stdlib .
	Author 	    	: Osama Ballan .
	Date			: 2017 - 12 - 18 .
*/

load "stdlib.ring"

print("Hello, World!\nWelcome To My First App\nWhat is Your Name?\n")
name = getstring()
num = getnumber()
print("Hello #{name}")
print("\nYour Number = #{num}")
