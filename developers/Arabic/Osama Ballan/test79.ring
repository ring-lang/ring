/*
**	Application	: Ring lessons - Encrypt() - Decrypt() .
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 13 .
*/
load "openssllib.ring"

See "Enter a string : " give cStr
	cKey=""			# 16 Bytes
	for x = 0 to 15
		cKey += char(x)
	next

	cIV = ""
	for x = 1 to 8
		cIV += char(x)
	next
cStr = Encrypt(cStr,cKey,cIV)
See "Cipher Text    : " + cStr + nl +
    "Plain Text     : " + Decrypt(cStr,cKey,cIV) + nl












