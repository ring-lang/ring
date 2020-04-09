/*
	Application	: Hash Functions Version 6
	Author		: Ahmed Mohamed
	Date		: 2019/10/24
*/

load "openssllib.ring"

See "Enter a string : " give cStr

	cKey = "my password"	# Any String
	cIV  = "my iv123"	# 8 Bytes

cStr = Encrypt(cStr,cKey,cIV)

See "Cipher Text    : " + cStr + nl +
    "Plain Text     : " + Decrypt(cStr,cKey,cIV) + nl
