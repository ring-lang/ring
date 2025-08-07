# Author: Ilir Liburn
# Updated by Fayed to check the Memory Pool usage

? "Using Memory Pool: " + ringvm_ismempool()
if ! ringvm_ismempool() return ok

for t=1 to 110000
	myList = newlist(3)
	myList[1] = ["Hello"]
	swap(myList,1,3)
next

if ringvm_ismempool()
	? "No Memory Leak!"
else
	? "We have a memory leak in List operations"
ok
