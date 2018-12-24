cOutput = ""
for t = 1 to 100000
	cOutput += 'x = ' + t + windowsnl()
next
write("test1.ring",cOutput)
