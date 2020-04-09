/*
          Application        :Ring Lessons
          Author             :Islam Deraz
          Date               :2018.03.15
*/

load "openssllib.ring"

See "Enter a string : " give cStr
	
cKey = "1234567890abcdef"    			
cIV  = "87654321" 
  
cStr = Encrypt(cStr,cKey,cIV)
See "Cipher Text    : " + cStr + nl +
    "Plain Text     : " + Decrypt(cStr,cKey,cIV) + nl



