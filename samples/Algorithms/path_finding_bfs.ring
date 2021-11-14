# Path finding on grid using BFS algorithm
# Author: Ahmad Zakaria (zaka7024@gmail.com)
# Date: 8/2020
# Description: visualization tool for path between two point on a grid

Load "stdlib.ring"

load "../DataStructure/queue_array.ring"
load "raylib.ring"

# Raylib window properties
screenWidth 	= 700
screenHeight 	= 560

# Create grid with 20 row and 15 column
new Grid(20, 15)


# class to represent a node in the grid
class GridNode type x y visited = False prevNode
	func operator cOperator, Para
                switch cOperator
                on "="
			if para.x = x and para.y = y return True else return False ok
		on "!="
			if para.x != x or para.y != y return True else return False ok
		off
# class to represent m * n grid using ring list
class Grid

	# Function to init grid properties 
	func init length, height
		InitWindow(screenWidth, screenHeight, "Path finding using BFS")
		SetTargetFPS(60)
	
		GRID_LENGTH = length
		GRID_HEIGHT = height
		
		initGridView()
		
		while !WindowShouldClose()
		
		        BeginDrawing()
		
		        ClearBackground(RAYWHITE)
			
		        for i = 1 to GRID_LENGTH
				for j = 1 to GRID_HEIGHT
					DrawRectangle(i * BOX_SIZE  - 1, j * BOX_SIZE - 1, BOX_SIZE + 2, BOX_SIZE + 2, BLACK)
					drawGridNode(i, j)
				next
			next
		
		        if IsMouseButtonDown(MOUSE_LEFT_BUTTON)
				pos = getMouseGridPosition()
				if isValidIndex(pos.x, pos.y) grid[pos.x][pos.y].type = BLOCKED_NODE ok
			ok
		
			if IsKeyReleased(KEY_TAB)
				destination = !destination
			ok

			destination = GuiCheckBox(Rectangle( screenWidth * 0.1, screenHeight * 0.93, 25, 25 ),
                        getPointMessage(), destination)

			if IsMouseButtonDown(MOUSE_RIGHT_BUTTON)
				pos = getMouseGridPosition()
				if isValidIndex(pos.x, pos.y) and destination and isnull(endNode)
					grid[pos.x][pos.y].type = END_NODE
					endNode = object2pointer(grid[pos.x][pos.y])
				elseif isValidIndex(pos.x, pos.y) and !destination and isnull(startNode)
					grid[pos.x][pos.y].type = START_NODE
					startNode = object2pointer(grid[pos.x][pos.y])
				ok
			ok

			clearButton = GuiButton(Rectangle( screenWidth * 0.3, screenHeight * 0.93, 80, 30 ), "CLEAR")
			findButton = GuiButton(Rectangle( screenWidth * 0.45, screenHeight * 0.93, 80, 30 ), "FIND PATH")
			

			if clearButton
				initGridView()
			ok

			if findButton and findPath()
				paths = path(pathNode)
				if len(paths) > 0
					drawPath(paths)	
				ok
			ok
		        EndDrawing()
		
		end
		
		CloseWindow()

	private

	BOX_SIZE 	= 32
	GRID_LENGTH 	= 20
	GRID_HEIGHT 	= 15
	WALKABLE_NODE 	= 0
	START_NODE 	= 1
	END_NODE	= 2
	BLOCKED_NODE 	= 3
	VISITED_NODE 	= 4
	PATH_NODE	= 5
	POINT_MESSAGE 	= 'Start Point'
	grid		= []
	startNode	= ''
 	endNode 	= ''
	pathNode	= ''
	destination 	= False
	clearButton 	= False
	findButton	= False

	# Function to create m * n grid
	func initGridView
		startNode 	= NULL
		endNode		= NULL
		pathNode	= NULL
		grid		= []
		
		for i = 1 to GRID_LENGTH
			cols = []
				for j = 1 to GRID_HEIGHT
					cols + new GridNode{
						x = i y = j type = 0
					}
				next
			grid + cols
		next
	# Function to toggle button message
	func getPointMessage
		if destination return "End Point" else return "Start Point" ok
	# Function to draw m * n grid
	func drawGridNode i, j
		switch grid[i][j].type
			on 0 DrawRectangle(i * BOX_SIZE , j * BOX_SIZE, BOX_SIZE, BOX_SIZE, BLUE)
			on 1 DrawRectangle(i * BOX_SIZE , j * BOX_SIZE, BOX_SIZE, BOX_SIZE, YELLOW)
			on 2 DrawRectangle(i * BOX_SIZE , j * BOX_SIZE, BOX_SIZE, BOX_SIZE, GREEN)
			on 3 DrawRectangle(i * BOX_SIZE , j * BOX_SIZE, BOX_SIZE, BOX_SIZE, RED)
			on 4 DrawRectangle(i * BOX_SIZE , j * BOX_SIZE, BOX_SIZE, BOX_SIZE, LIGHTGRAY)
			on 5 DrawRectangle(i * BOX_SIZE , j * BOX_SIZE, BOX_SIZE, BOX_SIZE, GREEN)
		off
	# Function to get mouse position on the grid
	func getMouseGridPosition
		xGrid = floor(GetMousePosition().x / BOX_SIZE)
		yGrid = floor(GetMousePosition().y / BOX_SIZE)
		return Vector2(xGrid, yGrid)
	# Function to check if an position is valid position in the grid or not
	func isValidIndex x, y
		if x >= 1 and x <= GRID_LENGTH and y >=1 and y <= GRID_HEIGHT return True ok
		return False
	# Function to get node from the grid
	func getNeighbor i, j
		if isValidIndex(i, j) return object2pointer(grid[i][j]) ok
		return null
	# Function to create a chain of nodes from a node to the startNode (used after find a path)
	func path endPointer
		list = []
		list + endPointer
		while !isnull(pointer2object(endPointer).prevNode)  and (pointer2object(pointer2object(endPointer).prevNode) != pointer2object(startNode))
			list + pointer2object(endPointer).prevNode
			endPointer = pointer2object(endPointer).prevNode
		end
	return reverse(list)
	# Function to draw a path using a chain of nodes
	func drawPath nodes
		for node in nodes
			node = pointer2object(node)
			grid[node.x][node.y].type = PATH_NODE
		next
	# Function to find a path between two point on the grid using the BFS Algorithm
	func findPath
		if !isnull(startNode) and !isnull(endNode)
			queue = new QueueArray
			pointer2object(startNode).visited = True
			queue.enqueue(startNode)
			while !queue.isempty()
				
				cn = pointer2object(queue.dequeue())
			
				# Get all current node neighbors
				# Mark unvisited nodes as visited
				# Add unvisited nodes to the queue

				# Deep copy is deep
				if isvalidIndex(cn.x + 1, cn.y) and !grid[cn.x + 1][cn.y].visited and grid[cn.x + 1][cn.y].type != BLOCKED_NODE
					grid[cn.x + 1][cn.y].visited = True
					grid[cn.x + 1][cn.y].type = VISITED_NODE
					grid[cn.x + 1][cn.y].prevNode = object2pointer(grid[cn.x][cn.y])
					queue.enqueue(object2pointer(grid[cn.x + 1][cn.y]))
					if grid[cn.x + 1][cn.y] = pointer2object(endNode) pathNode = object2pointer(grid[cn.x + 1][cn.y]) return True exit ok
				ok

				if isvalidIndex(cn.x - 1, cn.y) and !grid[cn.x - 1][cn.y].visited and grid[cn.x - 1][cn.y].type != BLOCKED_NODE
					grid[cn.x - 1][cn.y].visited = True
					grid[cn.x - 1][cn.y].type = VISITED_NODE
					grid[cn.x - 1][cn.y].prevNode = object2pointer(grid[cn.x][cn.y])
					queue.enqueue(object2pointer(grid[cn.x - 1][cn.y]))
					if grid[cn.x - 1][cn.y] = pointer2object(endNode) pathNode = object2pointer(grid[cn.x - 1][cn.y]) return True exit ok

				ok

				if isvalidIndex(cn.x, cn.y + 1) and !grid[cn.x][cn.y + 1].visited and grid[cn.x][cn.y + 1].type != BLOCKED_NODE
					grid[cn.x][cn.y + 1].visited = True
					grid[cn.x][cn.y + 1].type = VISITED_NODE
					grid[cn.x][cn.y + 1].prevNode = object2pointer(grid[cn.x][cn.y])
					queue.enqueue(object2pointer(grid[cn.x][cn.y + 1]))
					if grid[cn.x][cn.y + 1] = pointer2object(endNode) pathNode = object2pointer(grid[cn.x][cn.y + 1]) return True exit ok

				ok

				if isvalidIndex(cn.x, cn.y - 1) and !grid[cn.x][cn.y - 1].visited and grid[cn.x][cn.y - 1].type != BLOCKED_NODE
					grid[cn.x][cn.y - 1].visited = True
					grid[cn.x][cn.y - 1].type = VISITED_NODE
					grid[cn.x][cn.y - 1].prevNode = object2pointer(grid[cn.x][cn.y])
					queue.enqueue(object2pointer(grid[cn.x][cn.y - 1]))
					if grid[cn.x][cn.y - 1] = pointer2object(endNode) pathNode = object2pointer(grid[cn.x][cn.y - 1]) return True exit ok

				ok
			end
		ok
		return False
