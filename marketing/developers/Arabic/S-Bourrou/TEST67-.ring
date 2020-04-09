# بسم الله الرحمن الرحيم
// this is Lesson 9 -  thanks to Mr.MAHMOUD FAYED
/*
  Application:  Test Openssllib
  Author     :  S.BOURROU
  Date       :  20.12.2017  
*/

load "openssllib.ring"

 cStr = read(exefilename())

see "Size           :" + len(cStr) + nl +
    "Size in (KB)   :" + (len(cStr) / 1024) + nl +
    "Md5            :" + Md5(cStr) + nl +
    "sha1           :" + Sha1(cStr) + nl +
    "sha256         :" + sha256(cStr) + nl +
    "sha224         :" + sha224(cStr) + nl +
    "sha512         :" + sha512(cStr) + nl 

