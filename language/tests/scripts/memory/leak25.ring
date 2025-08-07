# Author: Ilir Liburn
# Updated by Fayed

? :start
? ringvm_ismempool()
for t=1 to 110000
	x = ref(1:3)
	x2 = x
	x = ref(list(3))
	x2 = x
	y = ref(new RefIt { data="test" })
	y2 = y
	z = ref([1,2,3])
	z2 = z
next
? ringvm_ismempool()
? :done

class RefIt
        data