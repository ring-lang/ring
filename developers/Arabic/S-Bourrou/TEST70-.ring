# بسم الله الرحمن الرحيم
// this is Lesson 9 -  thanks to Mr.MAHMOUD FAYED
/*
  Application:  Test3 > Encrypt(),Decrypt()
  Author     :  S.BOURROU
  Date       :  25.06.2018  
*/


load "openssllib.ring"

See "Enter a string : " give cStr

 cKey="My PassKey" # any str  
 cIV = "My ivkaey"       # 8 byte

cStr = Encrypt(cStr,cKey,cIV)
See "Cipher Text    : " + cStr + nl +
    "Plain Text     : " + Decrypt(cStr,cKey,cIV) + nl

