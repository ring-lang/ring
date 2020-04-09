/*
	Application	: Using StdLib
	Author		: Khaled ABID
	Date		: 18/12/2017
*/

load "stdlib.ring"

print("Hello, World!\nWelcome to my first app!\nWhat is your name?\n")

name = getstring()
print("Hello, #{name}")
