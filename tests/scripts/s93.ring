see "Test Exit command!" + nl

# exit  # ERROR USING EXIT OUTSIDE LOOP

for x = 1 to 10 
	see x see nl
	if x = 3 see "three" + nl
	but x = 5 exit
	ok
 next

see "end of program - stage 1" + nl

for x = 1 to 5 
	see "nice " 
	for y = 1 to 15 
		see "!"
		if y = 5  exit  ok
	next
	see nl
 next

see "end of program - stage 2" + nl

r = 10
while r > 0
	see r see nl
	if r = 5 exit ok
	r = r - 1
end

see "end of program - stage 3" + nl

m = 20
while m > 0
	see m see nl
	testexit()
	m = m - 1
end

see "end of program - stage 4" + nl

see "Exit from more than one loop" + nl

for x = 1 to 10
	for t = 1 to 10
		see x + t
		see nl
		if t = 3
			exit 2
		ok
	next
next

see "end of program - stage 5" + nl

func testexit
	if m = 15 testexit2() ok

func testexit2
	see "wwwwwwwwwwwwwww" + nl
	exit