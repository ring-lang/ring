# Passing a string to a function copies the whole value onto the VM stack
# (RING_VM_STACK_PUSHCVAR). len() only reads a size that is already
# stored, so both loops below do the same work — 20,000 length queries.
# Only the size of the argument differs.

cTiny = "0123456789"
cBig = "a"
while len(cBig) < 1048576
	cBig += cBig
end

? "len() on 10 bytes, 20,000 times"
t1 = clock()
nSum = 0
for i = 1 to 20000
	nSum += len(cTiny)
next
? "Time : " + ((clock()-t1)/clockspersecond()) + " seconds"

? "len() on 1 MB, 20,000 times"
t1 = clock()
nSum2 = 0
for i = 1 to 20000
	nSum2 += len(cBig)
next
? "Time : " + ((clock()-t1)/clockspersecond()) + " seconds"
