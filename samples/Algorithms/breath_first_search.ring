// BFS  breathFirstSearch
// Bert Mariani  2020-19-01
//
// https://justtechreview.com/breadth-first-search-bfs-program-in-c/
// https://www.thecrazyprogrammer.com/2015/09/breadth-first-search-bfs-program-in-c.html

       
Load "stdlib.ring"

MAX     = 1 
nodes   = 1

// Graph representation of Vertices 
// Path from Vertix 1 ==> 1 2 4 5 3 7 6 8 9
// AUTOMATIC -- feed this Graph

adj = [[0,1,0,1,1,0,0,0,0,0],
       [0,0,1,0,0,0,0,0,0,0],
       [0,0,0,0,0,1,0,0,0,0],
       [0,0,0,0,0,0,1,0,0,0],
       [0,0,0,0,0,1,0,1,0,0],
       [0,0,0,0,0,0,0,0,0,0],
       [0,0,0,0,1,0,0,1,0,0],
       [0,0,0,0,0,1,0,0,1,0],
       [0,0,0,0,0,0,0,0,0,0],
       [0,0,0,0,0,0,0,0,0,0]]


state = list(MAX)          // 1,2,3 = initial, waiting, visited
queue = new queue	
solution = []             // print final solution of Vertex Path.	 
 
initial = 1
waiting = 2
visited = 3
 
Manual = 'A'                // M or A-automatic

//-----------------------------
Func main()

	See "BFS: Graph create Manual or Auto: Enter M or A: "
	Give Letter
	Letter = Upper(Letter)
	if Letter = 'M'  Manual = 'M'  else 	Manual = 'A'  ok
   
   if Manual = 'M'
		create_graph()            // Ask for Grid points for graph representation
	else
	   nodes = len(adj)          // Adjust to size of Grid for Automatic
		MAX   = nodes
		state = list(MAX)
	ok
	
	BF_Traversal()
	
	See "Solution: > "   display1D(solution)
	
return 0

//===============================
// Breath First Transversal
 
Func BF_Traversal()
	
	display2D(adj)
	See "Nodes: "+ nodes +nl
	
	for v = 1 to nodes
		state[v] = initial
	next
	
	See "State: > "  	display1D(state)
	
	See "Enter Start Vertex for BFS: "
	Give v  try v = number(v) catch v = 0 done

	if v < 1 ? "Wrong vertex!" return ok
   
	BFS(v)       // ===>>>  Call 
	
	
return

//===============================
// Breath First Search
 
Func BFS(v)

	insert_queue(v)
	state[v] = waiting
	
	while !isEmpty_queue()
	
		v = delete_queue()  

		state[v] = visited
		
		for i = 1 to nodes
	
			if adj[v][i] = 1 && state[i] = initial	
			
				insert_queue(i)
				state[i] = waiting
			ok
			
		next
	end
	
	See nl
return
 
//=========================
//=========================
 
Func insert_queue(vertex)

	See "Path: vertex:  "+ vertex +nl
	Add(solution, vertex)

   size = len(queue)
	if size = Max
		See "Queue Overflow"+nl
	else
	
		queue.Add(vertex)
		### displayQueue()  ok     // Display Queue size and entries
	ok
return

//-----------------------------
 
Func isEmpty_queue()

   size = len(queue)
	if size = 0
		### displayQueue()  ok
		return 1
	else
		### displayQueue()  ok
		return 0
	ok
return
 
//-----------------------------
 
Func delete_queue()

	size = len(queue)
	if size = 0
		See "Queue Underflow"+nl
		exit(1)
	ok
	
	delete_item = queue.remove()
	
	### displayQueue()  ok
	
return delete_item

//============================
 
Func create_graph()

	See "Enter number of vertices: "
	Give nodes   nodes = number(nodes)
	
	nodes = nodes +1          // Need +1 bigger graph points
	Max   = nodes 
	adj   = list(MAX,MAX)     // Manual ENTRY: Grid of Vertex - Vertex Points
	state = list(MAX) 
 
	max_edge = nodes * (nodes - 1)
 
	for count = 1 to max_edge   

		See "Enter edge "+ count +" ( 0 0 to quit ) : "
		Give origin   origin = number(origin)
		Give destin   destin = number(destin)

		if origin = 0 && destin = 0
			exit(1)                     // break out of for loop;
		ok
 
		if origin >= nodes || destin >= nodes || origin < 1 || destin < 1 		
			See "Invalid edge!: Number too big: "+nl
			count--	
		else		
			adj[origin][destin] = 1			
		ok
		
	next
		
return

//============================

Func display1D(array)

   size = len(array)
	
	for i = 1 to size
		See " "+ array[i]
	next
	See nl+nl

return

//-----------------------------

Func display2D(array)

   sizeX = len(array)
	sizeY = len(array[1])
	
	for i = 1 to sizeY
	   See "...: "+i +" > "
		for j = 1 to sizeX
			See " "+ array[i][j]
		next
		See nl
		
	next
	See nl+nl

return

//-----------------------------

Func displayQueue()

	size = len(queue)

	for i = 1 to size
		See " "+ queue[i]
	next
	See nl
return

//===============================
// DETAILS
/*

 A Graph G = (V, E) is an accumulation of sets V and E 
 where V is a gathering of vertices and E is a gathering of edges.


------------------------------------------------- 
 Que.add(y) to End,  Que.remove() from Start
 lastPos = len(Que)
 if lastPos > Max   Que.remove()  ok   

 GRAPH
    1 --> 2 --> 3                      3
    |  \  |     |              14------|----12
    4 --> 5 --> 6           6---|---9    1---|---5
    |  /  |  /
    7 --> 8 --> 9	 


Ring Uses Index-1
Enter vertices: 10        Enter vertices: 14  (max Node number) 
                           
Enter edge                Enter edge 
1 2                        3 14
1 4                        3 12
1 5                       14  6
2 3                       14  9
4 7                       12  1
5 8                       12  5 
7 5                        0  0
7 8                        
3 6                       Enter Start Vertex: 3 
5 6                       3 12 14 1 5 6 9  
8 6                         
8 9                         
0 0                         
                           
Enter Start Vertex: 1       
1 2 4 5 3 7 6 8 9          

*/
