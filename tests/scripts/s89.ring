main()

func main

x = "welcome "

see x[1] + nl
see x[8] + nl

# see x[9] + nl	# Error index out of array range 
# x[1] = 10 	# error varaible is not string 
# x[1] = "10" 	# error more than one letter

x[1] = "W"  # right
see x + nl

see upper(x) + nl

y = "mahmoud samir fayed"
see upper2(y) + nl

z = "welcome"
see upper3(z) + nl

see 0 + "M" 
SEE nl

func upper string
	for x = 1 to len(String)
		if string[x] = "a" string[x] = "A"
		but string[x] = "b" string[x] = "B"
		but string[x] = "c" string[x] = "C"
		but string[x] = "d" string[x] = "D"
		but string[x] = "e" string[x] = "E"
		but string[x] = "f" string[x] = "F"
		but string[x] = "g" string[x] = "G"
		but string[x] = "h" string[x] = "H"
		but string[x] = "i" string[x] = "I"
		but string[x] = "j" string[x] = "J"
		but string[x] = "k" string[x] = "K"
		but string[x] = "l" string[x] = "L"
		but string[x] = "m" string[x] = "M"
		but string[x] = "n" string[x] = "N"
		but string[x] = "o" string[x] = "O"
		but string[x] = "p" string[x] = "P"
		but string[x] = "q" string[x] = "Q"
		but string[x] = "r" string[x] = "R"
		but string[x] = "s" string[x] = "S"
		but string[x] = "t" string[x] = "T"
		but string[x] = "u" string[x] = "U"
		but string[x] = "v" string[x] = "V"
		but string[x] = "w" string[x] = "W"
		but string[x] = "x" string[x] = "X"
		but string[x] = "y" string[x] = "Y"
		but string[x] = "z" string[x] = "Z"
		ok
	next
	return string

func upper2 string
	lower = "abcdefghijklmnopqrstuvwxyz"
	upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	for x = 1 to len(String)
		for t = 1 to 26
			if string[x] = lower[t]
				string[x] = upper[t]
			ok
		next
	next
	return string

func upper3 string
	letters = [	"abcdefghijklmnopqrstuvwxyz",
				"ABCDEFGHIJKLMNOPQRSTUVWXYZ"]
	see letters[1] + nl
	see letters[2] + nl
	for x = 1 to len(string)
		for t = 1 to 26
			if string[x] = letters[1][t]
				string[x] = letters[2][t]
			ok
		next
	next
	return string