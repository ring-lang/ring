# The next code works !
n = 10
cStr = string(n)
for x in cStr
	see x see nl
next

# The next code doesn't work !
n = 10
for x in string(n)
	see x see nl
next

# The next code doesn't work !
for x in "10"
	see x see nl
next