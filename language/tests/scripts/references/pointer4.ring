# Author: Ilir Liburn 
# Updated by Fayed

cnd = 0
do
 x = test(new Temp { data = "test" })
again cnd

? x
? :three
? :done

func test obj
        ptr = obj2ptr(obj)
	? :one
	? ptr2obj(ptr)
	? :two
        return ptr2obj(ptr)

class Temp
        data