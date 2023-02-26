# Author: Ilir Liburn
# Updated by Fayed

a     = [1,2,3]
b     = ref(a) 
ID1   = objectid(a)
ID2   = objectid(b)
ID3   = NULL
b     = test()
ID4   = objectid(b)
? ID1 = ID2
? ID1 = ID3
? ID3 = ID4

func test
        a   = [1,2,3]
	ID3 = objectid(a)
        return ref(a) 