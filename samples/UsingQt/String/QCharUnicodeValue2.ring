load "guilib.ring"

oChar = new QChar(0xD988)   
nHexUnicodeValue =  Hex(oChar.unicode())
? Upper(nHexUnicodeValue)
? Hex2Str(nHexUnicodeValue)
? :done
