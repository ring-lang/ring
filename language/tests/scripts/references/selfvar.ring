# Author: Ilir Liburn
# Updated by Fayed

ret = [new Temp { data="test" }] 

cnd = 0		# Tested by setting (cnd=1) - No Memory Leak
do
	ret = test(ret)
	# Refcount() will return 2 instead of 1 because RETURN uses Temp. variable
		? refcount(ret)
	? ret
again cnd

ret[1] { data = NULL }
? ret
? :done

func test x
	return ref(x)	# Return a Reference - Use a Temp. variable to store the Ref.

class Temp
	data
