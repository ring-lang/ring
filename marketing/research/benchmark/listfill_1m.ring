size  = 1_000_000
aList = list(size)

t1   = clock()
for t=1 to size aList[t] = t next
t2 = clock()

? t2-t1
	