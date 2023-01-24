aList = [1:10]
aList + ref(aList)
? refcount(aList)
aList = NULL
? refcount(aList)
? aList
