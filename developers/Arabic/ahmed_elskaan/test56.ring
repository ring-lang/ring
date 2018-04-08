/*
**	Application Name : Hash;
**	Author           : Ahmed Elskaan;
**	Date             : 2017-12-20;		
*/
load "openssllib.ring"
? "Enter Your message " Give cMes
? "MD5: " + md5(cMes)
? "SHA1: " + sha1(cMes)
? "SHA256: " + sha256(cMes)
? "SHA512: " + sha512(cMes)
