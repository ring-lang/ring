aList = 1:10
x = ref(aList)
y = x
y = x
y = ref(x)
? refcount(aList)