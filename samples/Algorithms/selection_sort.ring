# Selection Sort Algorithm implementation
# Author: Ahmad Zakaria (zaka7024@gmail.com)
# Date: 8/2020
# Description: Sort a list of items in ascending order

Load "stdlib.ring"
	
# Selection Sort test
if IsMainSourceFile()
	array = [2, 5, 2, 4, 3, 7, 9, 10, 1, 6]
	SelectionSort(array)
	? array
ok

# Function to sort an array using selection sort algorithm
func SelectionSort array
	for i = 1 to len(array)
		min = i
		for j = i + 1 to len(array)
			if array[j] < array[min]
				min = j
			ok
		next
		# Swap
		temp = array[i]
		array[i] = array[min]
		array[min] = temp
	next
