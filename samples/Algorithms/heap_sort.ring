# Heap Sort Algorithm implementation
# Author: Ahmad Zakaria (zaka7024@gmail.com)
# Date: 8/2020
# Description: Sort list of items using a binary heap

Load "stdlib.ring"
	
# Heap Sort class test
if IsMainSourceFile()
	
	array = [4, 2, 1, 0, 6, 5]
	? "The Array before sorting:"
	? array

	sorter = new HeapSort(array)
	array = sorter.sort()

	? "The Array after sorting:"
	? array

ok

class HeapSort
	array
	n
	# Function to build the max binary heap
	func init list
		if isnull(list)
			raise("Error: Can't init the heap with null list")
		ok
		array = list
		n = len(array)
	# Function to sort the given array
	func sort
		for k = len(array) / 2 to 1 step -1
			sink(k)
		next

		while n > 0
			temp = array[n]
			array[n] = array[1]
			array[1] = temp
			n--
			sink(1)
		end

		return array
	
	private
	func sink k
		while k * 2 <= n
			j = k * 2
			if j < n and array[j] <  array[j + 1] j++ ok
			if array[k] <  array[j]
				swap(array, k, j)
			ok
			k = j
		end		
