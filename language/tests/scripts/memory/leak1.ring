? "Using Memory Pool: " + ringvm_ismempool()
if ! ringvm_ismempool() return ok

for t=1 to 110000
	test()
next

if ringvm_ismempool()
	? "No Memory Leak!"
else
	? "We have a memory leak in Function Call operations"
ok

func test
	x = "I Love Programming!"