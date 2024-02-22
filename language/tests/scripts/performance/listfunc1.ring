# Written by Ilir Librun
# Updated by Mahmoud Fayed to show Fast/Slow

t1 = clock()
lst = NULL
test(10)
lst = NULL

# Time is around 700ms on my Computer
if (clock()-t1)/ClocksPerSecond() < 2
	? "Fast"
else
	? "Slow"
ok

func test cnt
	? cnt
	if !cnt return ok
	lst = list(1000,1000)
	test2(cnt--)

func test2 cnt
	? cnt
	if !cnt return ok
	lst = list(1000,1000)
	test(cnt--)
