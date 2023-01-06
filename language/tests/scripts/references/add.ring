aList1 = [1,2,3]
aList2 = [4,5]
add(aList1,ref(aList2))

? refcount(aList1)
? refcount(aList2)
? "==="
? aList1
? "==="
aList1 = []
? refCount(aList2)