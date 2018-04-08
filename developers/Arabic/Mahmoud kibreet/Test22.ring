/*
          Application : Variables(Lists) version3
          Author      : Mahmoud Kibreet
          Date        : 2018.01.24
*/

# Variable Types (String , Number , List , Object , C Object)

aList = [
	:name 	= "Mahmoud Kibret",
	:job  	= "Programmer",
	:country= "Lebanon"   ,
	:city = "Alex"
]

? "Size: " + len(aList)
for aItem in aList
	?aItem[2]
next 
