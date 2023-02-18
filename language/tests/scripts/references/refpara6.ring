# Author: Ilir Liburn
# Updated by Fayed 

cnd = 0
do
a = [1,2,3]
? refcount(a)
b = ref(a)
? refcount(b)
? "=========="
a = test(ref(a),ref(b),ref(a),ref(b))
? "------"
again cnd
? :done

func test(x,y,x2,y2)
	? refcount(x)
	? "=========="
        ? x
        ? refcount(x2)
	? refcount(y2)
        a = NULL
        ? type(x)
	? "=========="
        ? refcount(x)
        b = NULL
        ? type(y)
        ? refcount(y)
        ? y
	? "=========="
        return y
