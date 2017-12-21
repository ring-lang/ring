/*
**	Application Name : Encrypt;
**	Author           : Ahmed Elskaan;
**	Date             : 2017-12-20;		
*/
load "openssllib.ring"
see "Enter Your Text " give cStr

key = "123345546&^%$@#"
civ = "12345678"

cStr = Encrypt(cStr, key, civ)

see "Cipher text: " + cStr + nl +
    "Plain text: "  + decrypt(cStr, key, civ)


