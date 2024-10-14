/*
	Application	: Ring Lessons
	Author		: Khaled ABID
	Date		: 03/04/2018
*/

load "openssllib.ring"

See "Enter a string : " give cStr

cKey= "1234567890&é@-]^"			
cIV = "87654321"   

cStr = Encrypt(cStr,cKey,cIV)
See "Cipher Text    : " + cStr + nl +
    "Plain Text     : " + Decrypt(cStr,cKey,cIV) + nl
