load "guilib.ring"

# Create the String 
	mystring = new QString2()
	mystring.append("Hello, World!")

# Get One Character 
	cValue = mystring.mid(4,1)
	? "Character: " + cValue

# Using normar Ring functions
	? isalpha(cValue)
	? isdigit(cValue)

# Using QChar class 
	# QChar get an integer value as input
		oChar = new QChar(ASCII(cValue))	
	? oChar.isDigit()
	? oChar.isLetter()



