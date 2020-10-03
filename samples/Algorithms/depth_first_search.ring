// DFS Depth First Search
// Bert Mariani 2020-10-02
// See details below
//
// https://www.thecrazyprogrammer.com/2014/03/depth-first-search-dfs-traversal-of-a-graph.html
//

Graph    = list(10,10)
visited  = list(10)
nodes    = 8                     // Nodes is nbr of vertices and graph is sorted in array G[10][10]
solution =[] 
 
Vertice = [[ 0,1,1,1,1,0,0,0],
           [ 1,0,0,0,0,1,0,0],
			  [ 1,0,0,0,0,1,0,0],
			  [ 1,0,0,0,0,0,1,0],
			  [ 1,0,0,0,0,0,1,0],
			  [ 0,1,1,0,0,0,0,1],
			  [ 0,0,0,1,1,0,0,1],
			  [ 0,0,0,0,0,1,1,0]]
			  
// Solution: 1 2 6 3 8 7 4 5
			  
//------------------------- 
Func main()

	See "DFS: Graph create Manual or Auto: Enter M or A: "
	Give Letter
	Letter = Upper(Letter)
	if Letter = 'M'  Manual = 'M'  else 	Manual = 'A'  ok
   
   if Manual = 'M'
		create_graph()              // Ask for Grid points for graph representation
	else
	   nodes  = len(Vertice)       // Adjust to size of Grid for Automatic
	ok
	
	
   Graph = Vertice                // Automation 2D 8x8

   visited = list(nodes)          // populated with 0
	
	See "Graph:"+nl    display2D(Graph)
	
   DFS(1)                         //===>>> Call
   
   See nl+"Solution: "+nl  display1D(solution)
	
return
 
//-------------------------  
Func DFS(i)

	See "Node:"+ i +nl             // Solution, Node-Number's
   Add(solution, i)
	 
   visited[i] = 1
	
	for j = 1 to nodes   
	
      if (!visited[j])  &&  Graph[i][j] = 1
			DFS(j)                   // ===>>> CAll Recursive
		ok
   next
	
return

//============================
 
Func create_graph()

	See "Enter number of vertices: "
	Give nodes   nodes = number(nodes)
	
	nodes    = nodes +1              // Need +1 bigger graph points
	Vertice  = list(nodes,nodes)     // Manual ENTRY: Grid of Vertex - Vertex Points

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
			Vertice[origin][destin] = 1			
		ok
		
	next
	
	See "Vertice Manual: "+ nl   display2d(Vertice)
		
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
/*   

Graph            1
           ______|______
			  |  |     |  |
           2  3     4  5
			  \  /     \  /
			    6        7
				  \______/
				      |
				      8
        
             1 2 3 4 5 6 7 8 
Vertice = [[ 0,1,1,1,1,0,0,0], 1
           [ 1,0,0,0,0,1,0,0], 2
			  [ 1,0,0,0,0,1,0,0], 3
			  [ 1,0,0,0,0,0,1,0], 4
			  [ 1,0,0,0,0,0,1,0], 5
			  [ 0,1,1,0,0,0,0,1], 6
			  [ 0,0,0,1,1,0,0,1], 7
			  [ 0,0,0,0,0,1,1,0]] 8
	
Enter Vertice = 8


1 2
1 3
1 4
1 5

2 1
2 6
3 1
3 6

4 1
4 7
5 1
5 7

6 2
6 3
6 8

7 4
7 5
7 8

8 6
8 7
	
//Solution:  0 1 5 2 7 6 3 4
//Ring       1 2 6 3 8 7 4 5			  
			  
*/			  
