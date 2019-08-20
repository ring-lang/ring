/*
	Application 	: Ring Lessons
	Author		: Mahmoud Fayed
	Date		: 2017.12.15
*/

load "openssllib.ring"

See "Enter a string : " give cStr

	cKey=""    			# 16 bytes
	for x = 0 to 15
		cKey += char(x) 
	next

	cIV = ""   
	for x = 1 to 8
		cIV += char(x) 
	next


cStr = Encrypt(cStr,cKey,cIV)
See "Cipher Text    : " + cStr + nl +
    "Plain Text     : " + Decrypt(cStr,cKey,cIV) + nl
