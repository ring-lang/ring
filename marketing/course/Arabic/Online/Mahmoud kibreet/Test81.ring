/*
          Application : Ring Lessons
          Author      : Mahmoud Kibreet
          Date        : 2018.01.29
*/

load "openssllib.ring"

See "Enter a string : " give cStr

cKey = "my password"    # Any String!
cIV  = "my iv123"       # 8 bytes	      
	

cStr = Encrypt(cStr,cKey,cIV)
See "Cipher Text    : " + cStr + nl +
    "Plain Text     : " + Decrypt(cStr,cKey,cIV) + nl
