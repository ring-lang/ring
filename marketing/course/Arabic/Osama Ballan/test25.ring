/*
**	Application  	: substr() .
**	Author 	    	: Osama Ballan .
**	Date			: 2018 - 01 - 04 .
*/

# Variable Types (String, Number, List, Object, c Object)

cString = "Welcome To The Ring Programming Language (ring)"
? cString
? substr(cString, 1, 7)				# Get Characters From 1 Position To 7
? substr(cString, "Ring")			# Get Position Of String
? substr(cString, "Ring", upper("ring"))	# Replace SubString Not Case Sensitive
? substr(cString, "Ring", lower("ring"), True)	# Replace SubString Case Sensitive
