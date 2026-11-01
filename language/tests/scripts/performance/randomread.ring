# Random reads of lists built with + operator

t1 = clock()

N = 20000      # items per list
M = 20000      # reads per test

? "Lists of " + N + " items, " + M + " reads per test"
? copy("=", 50)

# One list, random positions
aA = Build(N, 1)
nSum = 0
for k = 1 to M
	r = Pos(k)
	nSum += aA[r]
next

# Two lists read in turn (parallel arrays)
aKeys = Build(N, 1)  aValues = Build(N, 2)
nSum = 0
for k = 1 to M
	r = Pos(k)
	nSum += aKeys[r] + aValues[r]
next

# Three lists read in turn
aX = Build(N, 1)  aY = Build(N, 2)  aZ = Build(N, 3)
nSum = 0
for k = 1 to M
	r = Pos(k)
	nSum += aX[r] + aY[r] + aZ[r]
next

# Nested list: random row, random column (rows built with +)
nRows = 200  nCols = 200
aMatrix = []
for i = 1 to nRows
	aRow = []
	for j = 1 to nCols aRow + (i * j) next
	aMatrix + aRow
next
nSum = 0
for k = 1 to M
	nSum += aMatrix[(k * 7) % nRows + 1][(k * 13) % nCols + 1]
next

# Binary search written in Ring
aSorted = Build(N, 1)
nHits = 0
for k = 1 to M / 4
	nTarget = Pos(k)
	nLo = 1  nHi = N
	while nLo <= nHi
		nMid = floor((nLo + nHi) / 2)
		if aSorted[nMid] = nTarget
			nHits++
			exit
		but aSorted[nMid] < nTarget
			nLo = nMid + 1
		else
			nHi = nMid - 1
		ok
	end
next

# Control: sequential reads (fast before and after)
nSum = 0
for k = 1 to N
	nSum += aA[k]
next

# Control: the list changes between reads (no items array is kept)
aC = Build(N, 1)
nSum = 0
for k = 1 to 2000
	nSum += aC[Pos(k)]
	aC + k
next

t2 = clock()
if (t2-t1)/clocksPerSecond() < 0.5 
	? "PASS"
else
	? "FAIL"
ok

func Build nCount, nFactor
	aList = []
	for i = 1 to nCount aList + (i * nFactor) next
	return aList

func Pos k
	return ((k * 7919) % N) + 1

