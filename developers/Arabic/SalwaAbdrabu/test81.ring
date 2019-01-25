/*
	Application : Ring Lessons
	Author      : Salwa Abdrabu
*/


load "openssllib.ring"

See "Enter a string : " give cStr

cKey="mypassword"               # any string!
cIV = "my iv123"                # 8 bytes
	
cStr = Encrypt(cStr,cKey,cIV)
See "Cipher Text    : " + cStr + nl +
    "Plain Text     : " + Decrypt(cStr,cKey,cIV) + nl
