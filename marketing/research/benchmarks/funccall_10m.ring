t1=clock()
for t=1 to 10_000_000 test() next
t2 = clock()
? t2-t1
func test return 0