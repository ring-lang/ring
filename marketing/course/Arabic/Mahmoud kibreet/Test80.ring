/*
          Application : Ring Lessons
          Author      : Mahmoud Kibreet
          Date        : 2018.01.29
*/

load "openssllib.ring"

See "Enter a string : " give cStr

cKey = "1234567890@#$%^&"
cIV  = "87654321"       	      
	

cStr = Encrypt(cStr,cKey,cIV)
See "Cipher Text    : " + cStr + nl +
    "Plain Text     : " + Decrypt(cStr,cKey,cIV) + nl
