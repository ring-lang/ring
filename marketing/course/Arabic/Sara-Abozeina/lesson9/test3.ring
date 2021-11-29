/*
**	Application:security for file download-encrypt & decrypt
**	Author	   :Sara Abozeina
**	Date       :2017.12.31
*/

load "openssllib.ring"

See "Enter the password : " give cStr
list = 0:15  cKey=""    for x in list cKey += char(x) next   # any string
list = 1:8   cIV = ""   for x in list cIV += char(x) next    # 8 bytes
cStr = Encrypt(cStr,cKey,cIV)
See "Cipher Text    : " + cStr + nl +
    "Plain Text     : " + Decrypt(cStr,cKey,cIV) + nl

