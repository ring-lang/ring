# Tree implementation
# Author: Ahmad Zakaria (zaka7024@gmail.com)
# Date: 8/2020

Load "stdlib.ring"
Load "queue_array.ring"

# Trees class test
if IsMainSourceFile()

	t = new Trees 			# Root of the tree

	t.setValue("ROOT")		# Set the root node value

	t.add(2) { add("A") add("B")}	# Add new tree (has 2 children)

	t.add(3) {add("C")}		# Add new tree (has 1 children)

	? t.size()			# Get the size of the tree (children count)
	
	node = t.getNode(1)		# Get a specific children

	? t.remove(1)			# Remove specific children

	? "contains:" + t.contains("C")	# Search in the whole tree	

	? t.print()			# Print the Tree

ok

class Trees
	# Each tree hast value and array of children (Trees)
	value children = []

	# Function to set the value of the tree
	func setValue v
		value = v
	# Function to add children to the tree
	func add v		
		children + new Trees
		children[len(children)].value = v
		return children[len(children)]
	# Function to get node from the tree
	func getNode index
		if size() = 0
			raise("Error: Can't get from tree with no children") ok
		if index < 1 or index > len(children)
			raise("Error: Index out bounds") ok
		return children[index]
	# Function to get all children of a tree	
	func items
		items = []
		for item in children
			items + item next
		return items
	# Function to print the whole tree (from the root to the leafs)
	func print
		? value
		for item in children
			item.print() next
	# Function to get the size of tree (children count)
	func size
		return len(children)
	# Function to check if the whole tree has a children with given value
	func contains v
		# Simple BFS
		queue = new QueueArray {enqueue(this)}
		while not queue.isempty()
			current = queue.dequeue()
			if compare(current, v) return True ok
			for item in current.children
				queue.enqueue(item) next	
		end return False
	# Function to remove children from the tree
	func remove index
		if index < 1 or index > len(children)
			raise("Error: Can't remove, Index out bounds")
		ok

		new_children = []
		for i = 1 to len(children)
			if i = index loop ok
			new_children + children[i] next

		 children = new_children
	private
	# Function to compare tree value with a given value
	func compare item, v
		if item.value = v
			return True ok
		return False
