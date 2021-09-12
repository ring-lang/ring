# Posted In Ring Group by Ilir Liburn
# Updated by Fayed for include outer for loop that repeat the test 100 times

str = "test"
size = len(str)
for nTest=1 to 100
	for c = 1 to size step 1
		? 'c = 1 to size step 1'
		? c
		ssize = len(substr(str,2))
		for s = 1 to ssize step 2
			? "s = 1 to ssize step 2"
			? s
			hybrid = new Hybrid2(str)
			for h in hybrid step 3
				? "h in hybrid step 3"
				? h[1]
				loop 2
			next
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
