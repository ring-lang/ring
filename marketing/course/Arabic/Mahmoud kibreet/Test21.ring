/*
          Application : Variables(Lists) version2 
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

? aList[:name]
? aList[:job]  ? aList[:country]

if aList[:city] = Null aList[:city] = "Beirut" ok
? aList[:city]
