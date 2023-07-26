load "constantslib.ring"

constants = new constants()

? constants.pi
? constants.count

constants {
	? pi
	? count
}

constants.count = 100 	# ERROR

class constants from constantsParent

	Pi = 3.142
	Count = 10