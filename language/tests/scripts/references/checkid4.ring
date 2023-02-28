# Author: Ilir Librun
# Updated by Fayed to use IDs variables 
# Note: No need to use Ref() function

ID1=NULL ID2=NULL ID3=NULL 

x = test() { ID2 = objectid(self) }
ID3 = objectid(x)

? ID1=ID2
? ID1=ID3

func test
        return new Obj { ID1=objectid(self) }

class Obj

