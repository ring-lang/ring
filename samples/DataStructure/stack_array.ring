# Stack implementation using Ring List
# Author: Ahmad Zakaria (zaka7024@gmail.com)
# Date: 8/2020

Load "stdlib.ring"

# StackArray class test
if IsMainSourceFile() 
	stack = new StackArray{
		push(2) push(4) push(["Four", "Two"])
	}

	stack.push(".")
	top = stack.pop()	# pop the top of the stack

	? stack.pop() 		# pop one element from the stack

	? stack.pops(2) 	# pop two element

	? "is empty? " + stack.isempty()

	stack {
		push(2) push(4) push("+")
	}

	sample = stack.sample() # random sample from the stack
	
	stack.contains(sample) 	# check if the stack contains an elements
	
	? stack.items() 	# return list of all stack elements
ok

class StackArray
	
	# Ring list to store stack elements
	array = []
	# Pointer to the tail of the stack
	tail = 0
	# Function to push non-value into the stack
	func push(value)
		if not isnull(value)
			array+value
			tail++
		else raise("Error: Can't push a null value") ok
	# Function to pop the top of stack if its exists
	func pop
		if size() > 0
			value = array[tail]
			tail--
			return value
		else raise("Error: Can't pop from empty stack") ok
	# Function to pop n time from the stack, return the items with new list
	func pops times
		canceled = []
		for i = 1 to times
			if tail > 0
				value = array[tail]
				canceled+value
				tail--
			else raise("Error: Can't pop from empty stack") ok
		next return canceled
			
	# Function to return the elements
	func items
		members = []
		for i = 1 to tail members+array[i] next
		return members
	# Function to return the top of stack
	func peek
		if tail > 0 return array[tail] else raise("Error: The top of stack is empty") ok

	# Function to return the size of stack
	func size
		return tail
	# Function to print stack elements from the top to the bottom 
	func print
		if size() > 0
			for i = tail to 1 step -1
				? array[i]
			next
		else raise("Error: Can't print a empty stack") ok
	# Function to get random sample from the stack
	func sample
		if size() > 0
			random = random(tail - 1) + 1
			return array[random]
		else raise("Error: Can't get sample from empty stack") ok
	# Function to check if an item exists in the stack
	func contains item
		if size() > 0
			for i = 1 to tail
				if type(array[i]) = type(item)
					if isString(array[i]) or isNumber(array[i])
						if array[i] = item return True ok 
					ok
				ok
			next
		ok
		return false
	# Function to check if the stack is empty
	func isempty
		return size() = 0
