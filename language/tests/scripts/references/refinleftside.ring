# Author: Ilir Liburn
tmp = new Temp { data="test" }
tmp2 = ref(tmp)
ref(tmp) = [1,2,3]
tmp { data="test2" }
? tmp
class temp
	data