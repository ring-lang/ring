x	= 1
? "x = " + x
bytes	= int2bytes(x)
nSize	= len(bytes)
? "Size (int) : " + nSize + " bytes!"
for t=1 to nSize
	? "Byte " + t + " value = " + ASCII(Bytes[t])
next
if ASCII(Bytes[1]) = 1
	? "little-endian"
else
	? "big-endian"
ok