load "zerolib.ring"

? "Using List - Index start from 0"
List = Z( [1,2,3] )
List.Add(4)
List.Add(5)
? List[0]
? List[1]
? List[2]
? List[3]
? List[4]
nIndex = List.find(2)
? "Find(2) = " + nIndex
List.delete(0)
? "After deleting the first item : List[0]" 
? "Now List[0] = " + List[0] 

? "Using String - Index start from 0"
String = Z( "Welcome" )
? String[0]
? String[1]
? String[2]
? String[3]
? String[4]
? String[5]
? String[6]
