/*
**	Application:security for file download(by file Hash)
**	Author	   :Sara Abozeina
**	Date       :2017.12.31
*/

load "openssllib.ring"
tab=char(9)+char(9)
? "Enter the file name with its path"
 Give cName
cStr=read(cName)
? "the file size (KB) = "+len(cStr)/1024 

 ? tab+"md5    :    "     + md5(cStr) 
 ? tab+"sha1   :    "     + sha1(cStr)
 ? tab+"sha256 :    "     + sha256(cStr) 
 ? tab+"sha224 :    "     + sha224(cStr) 
 ? tab+"sha384 :    "     + sha384(cStr) 
 ? tab+"sha512 :    "     + sha512(cStr) 

 
