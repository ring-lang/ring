# Author: Ilir Liburn

ID1=NULL ID2=NULL ID3=NULL
	
x = ref(test()) { ID2 = objectid(self) }
y = x
ID3 = objectid(x)
	
? ID1=ID2
? ID1=ID3
	
? refcount(x)
? refcount(y)
	
func test
        return new Obj { ID1=objectid(self) oSelf = ref(self) }
	
func test2
        o = new Obj { ID1=objectid(self) oSelf = ref(self) }
        return o
	
class Obj
        oSelf