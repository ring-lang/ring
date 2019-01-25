/*
	Application : Ring Lessons
	Author      : Salwa Abdrabu
*/


load "openssllib.ring"

See "Enter a string : " give cStr

cKey="1234567890@#$%^&"               # 16 bytes
cIV = "87654321"  
	
cStr = Encrypt(cStr,cKey,cIV)
See "Cipher Text    : " + cStr + nl +
    "Plain Text     : " + Decrypt(cStr,cKey,cIV) + nl
