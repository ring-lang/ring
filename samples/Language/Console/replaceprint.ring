name = "Ring"
p("Welcome to the #{name} programming language!")

func p vValue
	if isstring(vValue)
		see Print2Str(vValue)
	else
		see vValue 
	ok
