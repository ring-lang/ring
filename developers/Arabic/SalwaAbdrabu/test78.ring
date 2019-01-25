/*
	Application : Ring Lessons
	Author      : Salwa Abdrabu
*/


load "openssllib.ring"

See "Enter a string : " give cStr
list = 0:15                          # [1,2,3,4, ...,15]
	cKey=""                      # 16 bytes  
	for x in list 
		cKey += char(x)
	next
list = 1:8                           # [1,2,3,4,5,6,7,8]
	cIV = ""  
	for x in list
		cIV += char(x) 
	next
cStr = Encrypt(cStr,cKey,cIV)
See "Cipher Text    : " + cStr + nl +
    "Plain Text     : " + Decrypt(cStr,cKey,cIV) + nl
