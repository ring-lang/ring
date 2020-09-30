# Quick Union implementation
# Author: Ahmad Zakaria (zaka7024@gmail.com)
# Date: 8/2020

Load "stdlib.ring"

# Quick Union Class test
if IsMainSourceFile()

	QU = new QuickUnion (10)
	
	QU.union(2, 3)			# connect 2 with 3
	QU.union(4, 5)			# connect 4 with 5

	? QU.connected(2, 3)		# check if 2 and 3 are connected

	QU.union(3, 4)			# connect 3 with 4

	? QU.connected(2, 5)		# check if 2 and 5 are connected
	

	QU = new QuickUnion (10)
	? "Connect numbers from file: "

	try
		data = read("UnionFindTest.txt")	# read data from file
	catch 
		? cCatchError bye
	done
	
	items = split(data, ' ' )		# split into list

	for i = 1 to len(items) step 2		# connect each consecutive two numbers
		QU.union(0 + items[i], 0 + items[i + 1])
	next

	? QU.connected(7, 1)			# check if 7 and 1 are connected
	? QU.connected(7, 9)			# check if 7 and 9 are connected
	? QU.connected(1, 9)			# check if 1 and 9 are connected
	
	QU.union(1, 7)				# connect 1 with 7
	? QU.connected(7, 1)
ok

class QuickUnion

	# Init the QuickUnion
	# Function to clear the QuickUnion structure, set id of each object to it self
	func init n
		id = []
		for i = 1 to n
			id + i
		next
	# Function to connect p with q
	func union p, q
		proot = root(p)
		qroot = root(q)
		id[proot] = qroot
	# Function to check if p and q are connected
	func connected p, q
		return root(p) = root(q)	

	private
	id = []
	# Function to get the root of number using the id list
	func root n
		while id[n] != n
			n = id[n]
		end
		return n
