# بسم الله الرحمن الرحيم
// this is Lesson 9 -  thanks to Mr.MAHMOUD FAYED
/*
  Application:  Test2 > Encrypt(),Decrypt()
  Author     :  S.BOURROU
  Date       :  25.06.2018  
*/


load "openssllib.ring"

See "Enter a string : " give cStr
 cKey=""    for x=0 to 15  cKey += char(x) next
  cIV = ""   for x=1 to 8  cIV += char(x) next
cStr = Encrypt(cStr,cKey,cIV)
See "Cipher Text    : " + cStr + nl +
    "Plain Text     : " + Decrypt(cStr,cKey,cIV) + nl

