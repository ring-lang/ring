? "Using Memory Pool: " + ringvm_ismempool()
if ! ringvm_ismempool() return ok

for t=1 to 110000
	aList = [ 1:100 , 1:100 ]
	test(aList, aList[1])	# Pass a list and sub list
next

if ringvm_ismempool()
	? "No Memory Leak!"
else
	? "We have a memory leak in Function Call operations"
ok

func test v1, v2
	v1 = NULL	# Delete the parent list, Keep sub list
	v3 = v2		# We can use the sub list
	# By the end of the function, the sub list will be deleted