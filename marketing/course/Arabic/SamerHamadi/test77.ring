/*
**	Application    : Ring Lessons
**	Author 	       : Samer Hammadi
**	Date           : 22/12/2017
*/
#================================================================

load "openssllib.ring"

See "Enter a string : " give cStr

	cKey=""    			# 16 Byte
	for x = 1 to 15
		cKey += char(x) 
	next

	cIV = ""   
	for x = 1 to 8 
		cIV += char(x) 
	next

cStr = Encrypt(cStr,cKey,cIV)
See "Cipher Text    : " + cStr + nl +
    "Plain Text     : " + Decrypt(cStr,cKey,cIV) + nl
