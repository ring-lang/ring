load "guilib.ring"

cValue = "M"
oChar = new QChar(ASCII(cValue))    
? oChar.unicode()

# If the character is ASCII Number 
	? Char(oChar.unicode())

? copy("*",10)

# Let's try a Unicode Character 

oChar = new QChar(0xFEED)    
? Upper(Hex(oChar.unicode()))
? :done
