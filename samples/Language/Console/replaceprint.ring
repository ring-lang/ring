load "stdlib.ring"

name = "Ring"
p("Welcome to the #{name} programming language!")

func p vValue
	if isstring(vValue)
		see _Print2Str(vValue,3)
	else
		see vValue 
	ok
