# Author: Ilir Liburn

aList = []

add(ref(aList),0)

aList2 = aList

add(ref(aList),ref(aList2))

? aList
? refcount(aList)

? copy("*",20)

aList2 = aList

? aList2
? refcount(aList2)
? refcount(aList[2])
? refcount(aList2[2])

? copy("*",20)

? aList