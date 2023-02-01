# In this version we uses a loop 
# To see the effect of Performance instructions

for m=1 to 10
	aList = 1:10
	? refcount(aList)
	ref1 = ref(aList)
	? refcount(aList)
	ref(aList)
	ref(aList)
	? refcount(aList)
	? refcount(ref1)
	ref1 = NULL
	? "before"
	? ref1
	? "after"
	? refcount(aList)
	? refcount(ref1)
	? copy("*",10)
	? aList
next