# This test program is written by Ilir Liburn

str = "test"
for c in str step 1
? "c in str step 1"
? c

	? "s in substr(str,2) step 2"
	for s in substr(str, 2) step 2
		? s
		? "h in hybrid step 3"
		hybrid = new Hybrid(str)
		for h in hybrid step 3
			? h
			exit 2
		next
	next
next

class Hybrid
	data
	func init val 
		data = val

        func operator cOperator,Para
		switch cOperator
			on "len"
				return len(data)
			on "[]"
				return data[Para]
		off