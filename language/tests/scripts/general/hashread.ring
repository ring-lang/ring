aHash = [ :a = 1, :b = 2 ]

header("(1) The reads: the value is an empty string, the size stays 2")
nValue = aHash[:c]
? "==> [" + nValue + "] " + len(aHash)
? aHash[:d]
? "==> " + len(aHash)
f(aHash[:e])
if aHash[:f] = "" ? "==> empty " + len(aHash) ok
v = aHash[:g] + "x"
? "==> " + v + " " + len(aHash) + " " + len(aHash[:h]) + " " + len(aHash)
v = aHash[:i]
	? "==> " + len(aHash)

header("(2) An existing key is still read (any case)")
? "==> " + aHash[:a] + " " + aHash[:B] + " " + len(aHash)

header("(3) Assignment adds the key")
aHash[:c] = "value"
? "==> " + aHash[:c] + " " + len(aHash)
aHash[:list] = []
aHash[:list][:k] = 10
? "==> " + aHash[:list][:k] + " " + len(aHash[:list]) + " " + len(aHash)
? "==> [" + aHash[:list][:missing] + "] " + len(aHash[:list])

header("(4) A large list (it has a hash table): the same rules")
aBig = []
for x = 1 to 20 aBig[ "key" + x ] = x next
? "==> " + len(aBig) + " " + aBig[:key5]
v = aBig[:nothere]
? "==> " + len(aBig)
aBig[:nothere] = 1
? "==> " + len(aBig) + " " + aBig[:nothere]

header("(5) for in over a missing key, and eval()")
for t in aHash[:nokey] ? t next
? "==> " + len(aHash)
eval("v = aHash[:evalkey]")
? "==> " + len(aHash)
eval("aHash[:evalkey] = 5")
? "==> " + len(aHash) + " " + aHash[:evalkey]

header("(6) Lists inside lists, local lists, and list items")
aList = [ [ :x = 1 ] ]
v = aList[1][:y]
? "==> " + len(aList[1])
? "==> " + g()

header("(7) A missing key indexed again is still an error")
try
	v = aHash[:zz][:y]
catch
	? "==> error"
done

func header cTitle
	? copy("=",70)
	? cTitle
	? copy("=",70)

func f p
	? "==> [" + p + "]"

func g
	aLocal = [ :one = 1 ]
	v = aLocal[:two]
	aLocal[:three] = 3
	return len(aLocal)
