
#####################################
# Application  : Variables (Lists)- version 2
# Author        : Azzeddine Remmal            
# Date           : 06.01.2018                  
####################################

# -----------Variable Types (String, Number, List, Object, C Object)
 
aList = [

	:name 	= "Mahmoud Fayed",
	:job	= "Programmer",
	:Country= "Egypt",
	:city	= "Alex"

]

? aList[:name]
? aList[:job] ? aList[:country]

if aList[:city] = NULL aList[:city] = "Cairo" ok
? aList[:city]
