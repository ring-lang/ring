/*
**	Application Name : Encrypt;
**	Author           : Ahmed Elskaan;
**	Date             : 2017-12-20;		
*/

load "openssllib.ring"
see "Enter Your Text " give cStr
key = ""
for x = 0 to 15
	key += char(x)
next
civ = ""
for x = 1 to 8
	civ += char(x)
next

cStr = Encrypt(cStr, key, civ)

see "Cipher text: " + cStr + nl +
    "Plain text: "  + decrypt(cStr, key, civ)
