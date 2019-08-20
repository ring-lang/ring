/*
	Application 	: Ring Lessons
	Author		: Mahmoud Fayed
	Date		: 2017.12.15
*/

load "openssllib.ring"

See "Enter a string : " give cStr

cKey = "my password"		# Any string!
cIV  = "my iv123"		# 8 Bytes

cStr = Encrypt(cStr,cKey,cIV)
See "Cipher Text    : " + cStr + nl +
    "Plain Text     : " + Decrypt(cStr,cKey,cIV) + nl
