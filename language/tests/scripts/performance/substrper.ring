t1 = clock()

cText = "" for i = 1 to 20000 cText += "the quick brown fox jumps over the lazy dog " next

aWords = [] cWord = ""
for i = 1 to len(cText) c = cText[i] if c = " " if cWord != "" aWords + cWord ok cWord = "" else cWord += c ok next

aWords2 = mysplit(cText, " ")
cOut = "" for w in aWords2 cOut += upper(left(w, 1)) + substr(w, 2) + " " next

t2 = clock()

if (t2-t1)/clocksPerSecond() < 1
	? "PASS"
else
	? "FAIL"
ok

func mysplit cStr, cSep
	# split by scanning characters (linear)
	aOut = [] cCur = ""
	for i = 1 to len(cStr) c = cStr[i] if c = cSep aOut + cCur cCur = "" else cCur += c ok next
	aOut + cCur
	return aOut
