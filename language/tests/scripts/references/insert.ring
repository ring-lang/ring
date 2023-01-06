alist  = [1,2,3]
alist2 = [4,5]
insert(aList,0,ref(aList2))
? "======="
? aList
? "======="
? refcount(aList2)
aList[1] = []
? refcount(aList2)
? "======="
? aList
