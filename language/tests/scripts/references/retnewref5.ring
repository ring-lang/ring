# Author: Ilir Liburn
# Updated by Fayed

x = test()
? "--------------"
? objectid(x)
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
	b = ref(a[1])
	? a
        return b