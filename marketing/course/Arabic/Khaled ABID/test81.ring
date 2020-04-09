/*
	Application	: Ring Lessons
	Author		: Khaled ABID
	Date		: 03/04/2018
*/

load "openssllib.ring"

See "Enter a string : " give cStr

cKey= "my psswrd"	# Any string 		
cIV = "my iv123"   	# 8 bytes

cStr = Encrypt(cStr,cKey,cIV)
See "Cipher Text    : " + cStr + nl +
    "Plain Text     : " + Decrypt(cStr,cKey,cIV) + nl

/* output

Enter a string : 1
Cipher Text    : ;��-w�
Plain Text     : 1

Enter a string : klk
Cipher Text    : 2�V�X��
Plain Text     : 
*/
