/*
          Application : Conversion between lists and strings
          Author      : Mahmoud Kibreet
          Date        : 2018.01.24
*/

# Variable Types (String , Number , List , Object , C Object)

#          1       2      3         4       5
aList = [:one , : two , :three , :four , :five]

? aList
? len(aList)

cstring = List2str(aList) 
? Len(cstring)

? cstring 

aList2 = str2List(cString)
? Len(aList2)
