/*
**	Application	: Ring lessons - Encrypt() - Decrypt() .
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 13 .
*/
load "openssllib.ring"

See "Enter a string : " give cStr

	cKey="my password"					# Any String
	cIV = "my iv123"					# 8 Bytes

cStr = Encrypt(cStr,cKey,cIV)
See "Cipher Text    : " + cStr + nl +
    "Plain Text     : " + Decrypt(cStr,cKey,cIV) + nl












