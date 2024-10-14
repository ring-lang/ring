/*
	Application	: Substr
	Author		: Ahmed Mohamed
	Date		: 2019/10/14
*/


# Variables Types (Strings, Number, List, Object, C Object)

cString = "Welcome To The Ring Programming Language (ring)"
? cString

? substr(cString, 16, 4) 				# Get Numbers Of Characters
? substr(cString, "Ring") 				# Get Position Of Substring
? substr(cString, "Ring", "****Ring****"); 		# Replace Substring

# Not Case Sensitive
	? substr(cString, "Ring", "****Ring****", true); 	# Replace Substring
