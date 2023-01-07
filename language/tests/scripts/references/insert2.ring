alist  = [0,1,2,3]
alist2 = [0,4,5]
aList[1]  = ref(aList2)
aList2[1] = ref(aList)
? aList
? "==="
? refcount(aList)
? refcount(aList2)
? "==="
aList2 = []
? refcount(aList)
? refcount(aList2)
? "==="
aList = []
? refcount(aList)
? refcount(aList2)
? "==="