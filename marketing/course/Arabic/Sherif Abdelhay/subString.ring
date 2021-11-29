/*
		Application	: SubStr()
		Author		: Sherif Abdelhay
		Date		: 2018.6.4

*/

cString = "Welcome to the Ring programming language (ring)"

? subStr(cString, 16, 4)				# Get a number of characters
? subStr(cString, "Ring")				# Get position of substring
? subStr(cString, "Ring", "***Ring***")			# Replace substring -> Case Sensitive
? subStr(cString, "Ring", "***Ring***", true)		# Replace substring -> Not A Case Sensitive
