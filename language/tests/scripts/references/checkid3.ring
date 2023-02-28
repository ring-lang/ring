# Author: Ilir Librun
# Updated by Fayed to use IDs variables 

ID1=NULL ID2=NULL ID3=NULL ID4=NULL

x = test() { ID3 = objectid(self) }
ID4 = objectid(x)

? ID1=ID2
? ID1=ID3
? ID1=ID4

func test
        return ref(new Obj { ID1=objectid(self) }) { ID2=objectid(self) }

class Obj

