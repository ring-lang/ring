# ------------ Variables (Strings) Part6 ------------
# ------------  Strings Functions Part2  ------------
# ------------     subStr() Function     ------------ 
cString = "Welcome To The Ring Programming Language (ring)"
? cString
? substr(cString, 16, 4) //Extract 4 Characters From Index 16
? substr(cString, "Ring") //Index Of Some Characters
? substr(cString, "Ring", "ring") //Replace Some Characters
? substr(cString, "Ring", "this", True) //Case Insensitive = True
