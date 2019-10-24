/*
	Application	: Hash Functions Version 3
	Author		: Ahmed Mohamed
	Date		: 2019/10/24
*/

load "openssllib.ring"

See "Enter a string : " give cStr

	list = 0:15  		# [0,1,2,3,.........,15]
	cKey = "" 		# 16 Bites   
	for x in list 
		cKey += char(x) 
	next

	list = 1:8   		# [0,1,2,3,5,6,7,8]
	cIV = ""   		
	for x in list 
		cIV += char(x) 
	next

cStr = Encrypt(cStr,cKey,cIV)

See "Cipher Text    : " + cStr + nl +
    "Plain Text     : " + Decrypt(cStr,cKey,cIV) + nl
