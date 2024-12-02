cStr = "Some Text"
cStrToFind = ""
cStrSize = len(cStrToFind )

nPos = subStr(cStr, cStrToFind )

? cStrSize	# 0
? nPos		# 1

cRes = substr(cStr, nPos, cStrSize)      
? cRes
? len(cRes)

if cStrToFind
   ? "we have something to find"
else
   ? "empty string!"
ok

