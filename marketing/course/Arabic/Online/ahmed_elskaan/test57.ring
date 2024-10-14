/*
**	Application Name : HASH;
**	Author           : Ahmed Elskaan;
**	Date             : 2017-12-20;		
*/
load "openssllib.ring"
str = read(exefilename())
see "size: " 		+ len(str) 		+ nl +
    "size(kb): " 	+ (len(str)) / 1024 	+ nl +
    "md5 : " 		+ md5(str) 		+ nl +
    "sha1: " 		+ sha1(str)		+ nl +
    "sha256: "		+ sha256(str)		+ nl +
    "sha512: "		+ sha512(str)		+ nl 

