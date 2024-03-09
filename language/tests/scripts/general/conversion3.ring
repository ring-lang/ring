cStr = "123 -10 12.22 15.4 9.3 1.2e5"

cNum = "" + (0 + number(cStr))
? cNum

while len(cNum) <= len(cStr)
	cStr = trim(substr(cStr, len(cNum)+1 ))
	cNum = "" + (0+number(cStr))
	? cNum
end