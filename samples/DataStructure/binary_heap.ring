# Binary Heap (max) implementation using ring list
# Author: Ahmad Zakaria (zaka7024@gmail.com)
# Date: 8/2020

Load "stdlib.ring"

# Binary Heap class test
if IsMainSourceFile()
	heap = new BinaryHeap (10)		# create binary heap(max) with size of 10
	heap {
						# add 3 items to the heap
		add(4)				
		add(3)
		add(5)
	}

	? "size: "	+ heap.size()		# get the size of the heap (number of elements)
	? "max: " 	+ heap.max()		# get the max value	
	
	? "delete: "	+ heap.deleteMax()	# delete the max value in the heap

	heap.add(7)	

	? "max: " 	+ heap.max()		# get the max value

	? "print heap:"
	? heap.print()				# print all elements in the heap

	size = heap.size()			
	? "size: " + size

	? "Delete all elements"

	for i = 1 to size
		heap.deleteMax()
	next

	? "size: " + heap.size()		# the heap is empty

	
	/* You can add a object to the heap but make sure 
	   that your object support comparison operators
	   Use Ring operator overloading */
ok

class BinaryHeap
	
	# Function to init the array of null value using the size of the heap
	func init n
		if !isnumber(n) 
			raise("Error: Can't initialize the heap with illegal argument")
		ok
		for i = 1 to n
			array + ""
		next
	# Function to add value to the heap
	func add v
		if len(array) = 0 
			raise("Error: The binary heap size is 0, you should initialize the size of the heap.")
		ok
		n++
		array[n] = v
		swim(n)
	# Function to get the max in heap
	func max
		if n <= 0
			raise("Error: Can't get the max, the heap is empty")
		ok
		return array[1]
	# Function to delete the max value in the heap
	func deleteMax
		if n <= 0
			raise("Error: Can't delete the max, the heap is empty")
		ok
		max = array[1]
		if n > 1 swap(array, 1, n) ok
		n--
		sink(1)
		array[n + 1] = NULL
		return max
	# Function to get the number of elements in the heap
	func size
		return n
	# Function to check if the heap is empty
	func isEmpty
		return n = 0
	# Function to get all heap items
	func items
		items = []
			for i = 1 to n
				items + array[i] next
		return items
	
	# Function to print the items in the heap
	func print
		for i = 1 to n
			? array[i]
		next
	private

	array = []
	n = 0

	# Function to swim the new value to the current position in the heap (bottom -> top)
	func swim k
		while k > 1 and (array[floor(k/2)] < array[k])
			swap(array, floor(k/2), k)
			k = floor(k / 2)
		end
	# Function to sink a value to the current position in the heap (top -> bottom) 
	func sink k
		while k * 2 <= n
			j = k * 2
			if j < N and array[j] <  array[j + 1] j++ ok
			if array[k] <  array[j]
				swap(array, k, j)
			ok
			k = j
		end
