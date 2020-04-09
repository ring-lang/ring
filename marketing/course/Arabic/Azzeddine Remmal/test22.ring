
#####################################
# Application  : Variables (Lists)- version 3
# Author        : Azzeddine Remmal            
# Date           : 06.01.2018                  
####################################

# ------------Variable Types (String, Number, List, Object, C Object)
 
aList = [
	:name 	= "Mahmoud Fayed",
	:job	= "Programmer",
	:Country= "Egypt",
	:city	= "Alex"
]

? "Size: " + len(aList)
for aItem in aList 
	? aItem[2]
next
