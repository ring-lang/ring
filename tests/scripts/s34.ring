
NL = "
"

z = 5
count = 0
while count <= 99
	count = 0
	for x = 1 to z
		for y = 1 to 100
			if x = y
				count = count + 1				
			ok 
		next
	next
	z = z + 1
	see NL + "Count : " + count + NL
end

see "done" + NL
