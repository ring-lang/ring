# define common variables
NL = "
"
true = 1
false = 0

# see messages
see "Welcome to my new programming language" + NL

# Variables, Loops and conditions 

x = 1 while x <= 10 for y = 1 to 10 see y if y = 3 see " Three " ok next
see NL x = x + 1 end

see NL + "After the first result --- " + NL

x = 1 
while x <= 10 
	for y = 1 to 10 
		see y 
		if y = 3  see " Three " ok 
	next
	see NL 
	x = x + 1 
end

# Math

x = 10
y = 20

see " x = " + x + NL
see " y = " + y + NL
see " x + y = " + (x + y) + NL

# loop on double

for x = 1 to 100

	x = x + 0.95
	see "x : " + x
	see NL

next

see 1.12 + 10.18
see NL

x = 1
y = 1.95
see x + y
see NL