/*
	Application : Conversion between Lists And Strings
	Author      : Salwa Abdrabu
*/

# Variables Type( String, Number, List, Object, C Object )

aList = [ :One ,:Two ,:Three ,:Four ,:Five]

? aList
? "Len aList1 :"+ len(aList)

cString = List2str(aList)

? "Len cString :"+ len(cString)
aList2 = str2List(cString)
? "Len aList2 :"+ len(aList2)

