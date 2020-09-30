# Binary Search Algorithm implementation
# Author: Ahmad Zakaria (zaka7024@gmail.com)
# Date: 8/2020
# Description: Search for an item in a sorted list

Load "stdlib.ring"

# Binary Search test
if IsMainSourceFile()
	
	list =  generateSortedList(100)	# generate sorted list

	index = binarySearch(list, 5)	# get the index of (5) if (5) is in the list
	if index > 0 ? "list contains 5" ok

	list = [2, 4, 6, 8, 10]
	num = 5
	index = binarySearch(list, num)
	? "index of " + num + " :" + index

	num = 6
	index = binarySearch(list, num)
	? "index of " + num + " :" + index
ok

# Function to generate a sorted list of numbers
func generateSortedList length
	list = []
	r = random(5)
	for i = 0 to length
		list + r
		r = random(5) + r
	next

	return list

# Function to do a binary search in a list, return 0 if the item doesn't exist
func binarySearch list, value
	if not islist(list)
		raise("Error: Bad parameter. Expect list")
	ok

	lo = 1
	hi = len(list)
	while lo <= hi
		mid = ceil((lo + hi) / 2)
			if list[mid] > value
				hi = mid - 1
			elseif list[mid] < value
				lo = mid + 1
			else return mid ok
	end
	return 0
	
