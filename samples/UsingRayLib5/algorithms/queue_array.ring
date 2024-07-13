# Queue implementation using Ring List
# Author: Ahmad Zakaria (zaka7024@gmail.com)
# Date: 8/2020

Load "stdlib.ring"

# QueueArray class test
if IsMainSourceFile() 
	queue = new QueueArray{
		enqueue(1) enqueue(2) enqueue(3)
	}

	? queue.print()
	? "Queue size:	" + queue.size()		# get the queue size (number of elements)
	? "Remove:	" + queue.dequeue()		# remove element from the queue (front)
	
	? "First:	" + queue.first()		# get the first element in the queue
	? "Last: 	" + queue.last()		# get the last element in the queue
	? "Queue size:	" + queue.size()		# get the queue size (number of elements)
	? "Delete all elements"
	size = queue.size()
	for i = 1 to size				# remove all elements from the queue
		queue.dequeue() next
	
	? "Queue size:	" + queue.size()		# get the queue size (number of elements)
ok

class QueueArray
	
	# Ring list to store queue elements
	array = []
	# Pointer to the tail of the queue
	tail = 0
	# Pointer to the head of the queue
	head = 1
	# Function to push non-value into the queue
	func enqueue(value)
		if not isnull(value)
			if isempty()
				head = 1 ok
			array+value
			tail = tail + 1
		else raise("Error: Can't add a null value") ok
	# Function to pop the top of stack if its exists
	func dequeue
		if not isempty()
			value = array[head]
			head++
			return value
		else raise("Error: Can't dequeue from empty queue") ok		
	# Function to return the elements
	func items
		members = []
		if not isempty()		
			for i = head to tail members+array[i] next ok
		return members
	# Function to return the first item in the queue
	func first
		if not isempty() return array[head] else raise("Error: Can't return first item from empty queue") ok

	# Function to return the last item in the queue
	func last
		if not isempty() return array[tail] else raise("Error: Can't return last item from empty queue") ok
	# Function to return the size of queue
	func size
		return tail - head + 1
	# Function to check if the queue is empty
	func isempty
		return head > tail
	# Function to print queue elements from front to end
	func print
		if not isempty()
			for i = head to tail
				? array[i]
			next
		else raise("Error: Can't print a empty stack") ok
	# Function to get random sample from the queue
	func sample
		if not isempty() > 0
			random = random(tail - 1) + 1 + head - 1
			return array[random]
		else raise("Error: Can't get sample from empty queue") ok
	# Function to check if an item exists in the queue
	func contains item
		if not isempty()
			for i = head to tail
			if array[i] = item
				return True ok next
		ok
		return false
