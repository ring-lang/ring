# Quick Find implementation
# Author: Ahmad Zakaria (zaka7024@gmail.com)
# Date: 8/2020

Load "stdlib.ring"

# Quick Find Class test
if IsMainSourceFile()
	
	QF = new QuickFind (10)		# init with 10 integer

	QF.union(2, 3)			# connect 2 with 3
	QF.union(4, 5)			# connect 4 with 5

	? QF.connected(2, 3)		# check if 2 and 3 are connected

	QF.union(3, 4)			# connect 3 with 4

	? QF.connected(2, 5)		# check if 2 and 5 are connected
	

	QF = new QuickFind (10)
	? "Connect numbers from file: "

	try
		data = read("UnionFindTest.txt")	# read data from file
	catch 
		? cCatchError bye
	done
	
	items = split(data, ' ' )		# split into list

	for i = 1 to len(items) step 2		# connect each consecutive two numbers
		QF.union(0 + items[i], 0 + items[i + 1])
	next

	? QF.connected(7, 1)			# check if 7 and 1 are connected
	? QF.connected(7, 9)			# check if 7 and 9 are connected
	? QF.connected(1, 9)			# check if 1 and 9 are connected
	
	QF.union(1, 7)				# connect 1 with 7
	? QF.connected(7, 1)
ok

class QuickFind
	
	# Init the QuickFind
	# Function to clear the QuickFind structure, set id of each object to it self
	func init n
		for i = 1 to n
			id + i
		next	
	# Function to connect p with q
	func union p, q
		pid = id[p]
		qid = id[q]
		for i = 1 to len(id)
			if id[i] = pid id[i] = qid ok
		next
	# Function to check if p and q are connected
	func connected p, q
		return id[p] = id[q]

	private
	id = []
