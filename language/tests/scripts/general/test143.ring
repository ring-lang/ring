#======================================#
# Test using hybrid2() function 
# That uses: return new Hybrid2(str)
# That leads to a discovery that 
# (For-Loops) needs ICO_FREESTACK
#======================================#
# This test program is an updated 
# version to one of the tests submitted
# to Ring Group by Ilir Liburn
#======================================#

str = "test"
size = len(str)
for c = 1 to size step 1
? 'c = 1 to size step 1'
? c
	ssize = len(substr(str,2))
	for s = 1 to ssize step 2
		? "s = 1 to ssize step 2"
		? s
		hybrid = Hybrid2(str)
		for h in hybrid step 3
			? "h in hybrid step 3"
			? h[1]
			loop 2
		next
	next
next

func hybrid2 val
	return new Hybrid2(str)

class Hybrid
	data
	func init val 
		data = val

        func operator cOperator,Para
		switch cOperator
			on "len"
				return len(data)
			on "[]"
				return &data[Para]
		off

class Hybrid2
	data
	func init val 
		size = len(val)
		data = list(size)
		for i = 1 to size
			data[i] = new Hybrid(val)
		next

        func operator cOperator,Para
		switch cOperator
			on "len"
				return len(data)
			on "[]"
				return &data[Para]
		off
