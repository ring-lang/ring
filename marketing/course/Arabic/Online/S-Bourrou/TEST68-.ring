# بسم الله الرحمن الرحيم
// this is Lesson 9 -  thanks to Mr.MAHMOUD FAYED
/*
  Application:  Test > Encrypt(),Decrypt()
  Author     :  S.BOURROU
  Date       :  25.06.2018  
*/

load "openssllib.ring"

See "Enter a string : " give cStr
list = 0:15  cKey=""    for x in list cKey += char(x) next
list = 1:8   cIV = ""   for x in list cIV += char(x) next
cStr = Encrypt(cStr,cKey,cIV)
See "Cipher Text    : " + cStr + nl +
    "Plain Text     : " + Decrypt(cStr,cKey,cIV) + nl

