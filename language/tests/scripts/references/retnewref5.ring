# Author: Ilir Liburn
# Updated by Fayed

myid = NULL

x = test()
? "--------------"
if objectid(x) = myid 
	? "The same ID"
else
	? "Not the same ID"
ok
? refcount(x)
? x
? "--------------"
for y in x
        ? type(y)
        ? y
        ? refcount(y)
        y = 0
next
? "--------------"
? x
? refcount(x)
? :done

func test
        a = [[ref(a),ref(a),3],[4,5,6]]
        ? a
	? "--------------"
	myid = objectid(a[1])
	b = ref(a[1])
	? a
        return b