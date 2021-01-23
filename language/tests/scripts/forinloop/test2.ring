# This test program is written by Ilir Liburn

lst = list(2,1)
for x in lst
	for y in x
		y = list(1)
		for z in y
			exit 3
		next
	next
next
y = 1
? lst[1][1]
