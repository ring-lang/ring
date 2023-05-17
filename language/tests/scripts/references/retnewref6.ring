# Author: Ilir Liburn
# Updated by Fayed

ret = [new Temp { data="test" }]
oid = NULL
cnd = 0
do
	? :Before
	ret = test(ref(ret[1]))
	? :After
again cnd
? objectid(ret) != oid
? refcount(ret)
? ret
ret { data = NULL }
? ret
? :done

func test x
	? refcount(x)		# 2
        return test2(ref(x))	# set lNewRef flag

func test2 x
        oid = objectid(x)
	? refcount(x)		# 3
	? "==="
        return ref(test3(x))

func test3 x
	? refcount(x)		# 3
	? "***"
        if !cnd ? refcount(x) ok	# 3
        ret = NULL
        if !cnd ? refcount(x) ok	# 2
        return ref(x)

class Temp
        data