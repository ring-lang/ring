# Insertion Sort Algorithm implementation
# Author: Ahmad Zakaria (zaka7024@gmail.com)
# Date: 8/2020
# Description: Sort a list of items in ascending order

Load "stdlib.ring"
	
# Insertion Sort test
if IsMainSourceFile()
	array = [2, 5, 2, 4, 3, 7, 9, 10, 1, 6]
	InsertionSort(array)
	? array
ok

# Function to sort an array using Insertion sort algorithm
func InsertionSort array
	for i = 2 to len(array)
		for j = i to 2 step -1
			if array[j - 1] > array[j]
				# Swap
				temp = array[j - 1]
				array[j - 1] = array[j]
				array[j] = temp
			ok
		next
		
	next
