cStr = "welcome"

for t=1 to 10
	? left(cStr,t)
next

? copy("*",10)

for t=1 to 10
	? right(cStr,t)
next

? copy("*",10)

for t=1 to 10
	? substr(cStr,1,t)
next