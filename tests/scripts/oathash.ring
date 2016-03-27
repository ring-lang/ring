aKeywords = ["IF","TO","OR","AND","NOT","FOR","NEW","FUNC", 
"FROM","NEXT","LOAD","ELSE","SEE","WHILE","OK","CLASS","BREAK","RETURN","BUT", 
"END","GIVE","BYE","EXIT","TRY","CATCH","DONE","SWITCH","ON","OTHER","OFF", 
"IN","LOOP","PACKAGE","IMPORT","PRIVATE","STEP","DO","AGAIN","CALL"]

func main

for t = 1 to 1000
	r = mytest(t,false)
	if r = 0
		see "Output : " + t + nl
		exit
	ok
next

#mytest(201,true)	# oat hash
#mytest(178,true) 	# javascript hash 
#mytest(134,true)	# fnv hash
#mytest(122,true)	# elf hash
#mytest(226,true)	# murmur3 hash

func mytest nDiv,lDisp

aRes = []

for t in aKeywords
	nHash = javascript_hash(t)%nDiv
	aRes + nHash
	if lDisp
		see "Keyword : " + lower(t) + "  " + nHash + nl
	ok
next

aRes2 = []
for t in aRes
	nEqual = 0
	for r in aRes
		if t = r
			nEqual++
		ok
	next
	nEqual--
	aRes2 + nEqual
next

if lDisp
	see "Collision results" + nl
	see aRes2
ok
nSum = 0
for t in aRes2
	if t > 0
		nSum += 1
	ok
next
nCol =  ceil(nSum/2) 
if lDisp
	see "Number of collision = " + nCol + nl
ok

return nCol

#see djb_hash("hello") + nl
#see fnv_hash("hello") + nl
#see oat_hash("hello") + nl
#see elf_hash("hello") + nl

func djb_hash cKey
	h = 0
	for x in cKey
		h = 33 * h ^ ascii(x)
	next
	return h

func fnv_hash  cKey
	h = 2166136261
	for x in cKey
		h = unsigned(unsigned(h,16777619,"*"),ascii(x),"^")
	next
	return h  

func javascript_hash cKey	
	h = 0
	for x in cKey
		h = unsigned(h,ascii(x),"+")
		h = unsigned(h,unsigned(h,10,"<<"),"+")
		r = unsigned(h,6,">>")
		h = unsigned(h, r,"^")
	next
	return h  


func oat_hash cKey	
	h = 0
	for x in cKey
		h = unsigned(h,ascii(x),"+")
		h = unsigned(h,unsigned(h,10,"<<"),"+")
		r = unsigned(h,6,">>")
		h = unsigned(h, r,"^")
	next
	h = unsigned(h,unsigned(h,3,"<<"),"+")
	h = unsigned(h,unsigned(h,11,">>"),"^")
	h = unsigned(h,unsigned(h,15,"<<"),"+")
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
