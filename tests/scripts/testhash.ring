/*
aKeywords = ["IF","TO","OR","AND","NOT","FOR","NEW",":FUNC", 
"FROM","NEXT","LOAD","ELSE","SEE","WHILE","OK","CLASS","BREAK","RETURN","BUT", 
"END","GIVE","BYE","EXIT","TRY","CATCH","DONE","SWITCH","ON","OTHER","OFF", 
"IN","LOOP","PACKAGE","IMPORT","PRIVATE","STEP","DO","AGAIN","CALL"]

for t in aKeywords
	see "Keyword : " + lower(t) + "  " + (oat_hash(lower(t))%len(aKeywords)) + nl
next
*/


see djb_hash("hello") + nl
see fnv_hash("hello") + nl
see oat_hash("hello") + nl
see elf_hash("hello") + nl

func djb_hash cKey
	h = 0
	for x in cKey
		h = 33 * h ^ ascii(x)
	next
	return h

func fnv_hash  cKey
	h = 2166136261
	for x in cKey
		h = unsignedmul(h,16777619) 
		h = unsignedxor(h,ascii(x))
	next
	return h  

func oat_hash cKey	
	h = 0
	for x in cKey
		h += ascii(x)
		h += (h << 10)
		r = (h >> 6)
		h ^= r
	next
	h += (h << 3)
	h ^= (h >> 11)
	h += (h << 15)	
	return h  

func elf_hash cKey
	h = 0
	for x in cKey
		h = (h << 4) + ascii(x)
		g = h & dec("f0000000")
		if g != 0
			h ^= g >> 24
		ok
		h &= ~g
	next
	return h

func unsignedshift val,amt
	lastbit = val & (1 << 31)
	val = val & dec("7fffffff")
	val >>= amt
	if lastbit != 0
		val |= 1 << (32 - amt - 1)
	ok
	return val

func unsignedxor val,amt
	lastbit = val & (1 << 31)
	val = val & dec("7fffffff")
	val ^= amt
	if lastbit != 0
		val |= 1 << (32 - amt - 1)
	ok
	return val

func unsignedmul val,amt
	lastbit = val & (1 << 31)
	val = val & dec("7fffffff")
	val *= amt
	if lastbit != 0
		val |= 1 << (32 - amt - 1)
	ok
	return val