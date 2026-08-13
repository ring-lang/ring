# An empty Catch block must not grow the VM stack.
# Each statement frees the stack, so a Catch block with no statement in it
# used to leave one value behind per caught error, and about 1003 of them
# aborted with Error (R4) : Stack Overflow.

nBefore = ringvm_info()[18]

for i = 1 to 2000
    try
        raise("x")
    catch
    done
next

nAfter = ringvm_info()[18]

? "stack grew : " + (nAfter - nBefore)
? "survived 2000 empty catches"

# a Catch block that does contain a statement was never affected
n = 0
for i = 1 to 2000
    try
        raise("y")
    catch
        n++
    done
next
? "non-empty catch ran " + n + " times"
