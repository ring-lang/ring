See "Enter a string : " give cStr
list = 0:15  cKey=""  for x in list cKey += char(x) next
list = 1:8   cIV = "" for x in list cIV += char(x) next
cStr = encrypt(cStr,cKey,cIV)
See "Cipher Text : " + cSTR + nl +
    "Plain Text : " + decrypt(cStr,cKey,cIV) + nl
