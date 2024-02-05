# Author: Ilir Liburn
# Updated by Fayed

y = new Obj { ID1 = objectid(self) }
x = test(y) { ID2 = objectid(self) }
x.oSelf = "SELF"
	
? y.oSelf 
? type(y) 
? x.oSelf
	
? ID1=ID2
	
func test o
      return o
	
class Obj
	oSelf
