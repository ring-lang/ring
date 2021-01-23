lst = [[10],[20],[30]]
for v in lst
	exit
next
? v
? copy("=",50)
for x in lst
	? x
	for y in x
		y = [100]
		for z in y
			exit 3
		next
	next
next
? copy("=",50)
y = 1
? lst
? lst[1][1]
? x
? copy("=",50)
x = 600
? x
? lst