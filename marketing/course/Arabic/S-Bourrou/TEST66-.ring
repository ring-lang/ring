# بسم الله الرحمن الرحيم
// this is Lesson 9 -  thanks to Mr.MAHMOUD FAYED
/*
  Application:  Test Openssllib
  Author     :  S.BOURROU
  Date       :  20.12.2017  
*/

load "openssllib.ring"

? " Write Text to Encode ! :" give cMsg
? "Md5 = " + MD5(cMsg)
? "SHA1 =" + SHA1(cMsg)
? "SHA256 =" + SHA256(cMsg)
? "SHA512 =" + SHA512(cMsg)
