# Author: Ilir Liburn
# Updated by Fayed

cnd = 0		# Tested using (cnd=1) - No Memory Leak
do
	ret = test()
	? refcount(ret)	# 2 instead of 1 because of Temp. variable
again cnd

func test
	ret = test2()
	return ref(ret) # Uses a Temp. variable

func test2
	cls2 = [new Temp { data="test2" }]
	cls = ref(cls2[1])
	return cls	# Uses a Temp. variable

class Temp
	data
