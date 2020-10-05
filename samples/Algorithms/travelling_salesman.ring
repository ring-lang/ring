// Travelling_SalesMan
// Bert Mariani 2020-10-04
// See details at end
//
// https://www.thecrazyprogrammer.com/2017/05/travelling-salesman-problem.html
//

//          1     2     3     4      5     6     7     8     9    10    11    12    13 
Array =[[   0, 2451,  713, 1018,  1631, 1374, 2408,  213, 2571,  875, 1420, 2145, 1972], // 1
        [2451,    0, 1745, 1524,   831, 1240,  959, 2596,  403, 1589, 1374,  357,  579], // 2
        [ 713, 1745,    0,  355,   920,  803, 1737,  851, 1858,  262,  940, 1453, 1260], // 3
        [1018, 1524,  355,    0,   700,  862, 1395, 1123, 1584,  466, 1056, 1280,  987], // 4
        [1631,  831,  920,  700,     0,  663, 1021, 1769,  949,  796,  879,  586,  371], // 5
        [1374, 1240,  803,  862,   663,    0, 1681, 1551, 1765,  547,  225,  887,  999], // 6
        [2408,  959, 1737, 1395,  1021, 1681,    0, 2493,  678, 1724, 1891, 1114,  701], // 7
        [ 213, 2596,  851, 1123, 17698, 1551, 2493,    0, 2699, 1038, 1605, 2300, 2099], // 8
        [2571,  403, 1858, 1584,   949, 1765,  678, 2699,    0, 1744, 1645,  653,  600], // 9
        [ 875, 1589,  262,  466,   796,  547, 1724, 1038, 1744,    0,  679, 1272, 1162], // 10
        [1420, 1374,  940, 1056,   879,  225, 1891, 1605, 1645,  679,    0, 1017, 1200], // 11
        [2145,  357, 1453, 1280,   586,  887, 1114, 2300,  653, 1272, 1017,    0,  504], // 12
        [1972,  579, 1260,  987,   371,  999,  701, 2099,  600, 1162, 1200,  504,    0]] // 13 
 

NodeName = ["NewYork","LosAngeles","Chicago","Minneapolis","Denver","Dallas","Seattle", 
            "Boston","SanFrancisco","St.Louis","Houston","Phoenix","SaltLakeCity"]
 
// 1. New York - 2. Los Angeles - 3. Chicago - 4. Minneapolis - 5. Denver - 6. Dallas - 7. Seattle - 
// 8. Boston - 9. San Francisco - 10. St. Louis - 11. Houston - 12. Phoenix - 13. Salt Lake City
// Objective 7293 miles
// 1 8 3 4 5 13 7 9 2 12 11 6 10 1     

// Ring Path
// 1--->8--->3--->10--->4--->5--->13--->12--->2--->9--->7--->6--->11---> 1  Minimum cost is: 8131
 

completed   = list(len(array))            
node        = len(Array)                 // Nbr of Cities   
cost        = 0 
maxDistance = 9999
 
//------------------------------------
 
Func main()
  
   See "TSP: Graph create Manual or Auto: Enter M or A: "
   Give Letter
   Letter = Upper(Letter)
   if Letter = 'M'  Manual = 'M'  else    Manual = 'A'  ok
   
   if Manual = 'M'
      takeInput()                       // MANUAL Ask for Grid points for graph representation
      node = len(Array)
      completed = list(len(array))
   else
      node = len(Array)                 // AUTOMATIC  Adjust to size of Grid for Automatic
      completed = list(len(Array))
   ok
   //-------------------   
   
   
   See "Array of Distance: "+nl display2D(array)
   See nl+"The Path is: "+ nl
   
   minCost(1)                           //===>>> CALL,Ring-Index-1 starting vertex
 
   See nl+nl+"Minimum cost is: "+ cost +nl
 
return 0
 
//------------------------------------
 
Func minCost(City)

   nCity = 1
   completed[City] = 1
 
   See ""+ (City) +" "+ NodeName[City] +" --> "    // 1 NewYork --->8 Boston --->3 Chicago --->1
   
   nCity = least(City)   //===>>> CALL
 
   if nCity = maxDistance
   
      nCity = 1    
      See " "+ (nCity) +" "+ NodeName[nCity]       // 1 NewYork
      cost += array[City][nCity]
 
      return
   ok
 
   minCost(nCity)   //===>>> CALL Recursive

return
 
//------------------------------------
 
Func least(c)

   nCity = maxDistance
   mini  = maxDistance
   kmin  = 0
 
   for i = 1 to  node       // Nodes
   
      if  array[c][i] !=0   &&  completed[i] = 0
      
         if array[c][i] + array[i][c] < mini
         
            mini  = array[i][c] + array[c][i]
            kmin  = array[c][i]
            nCity = i
            
         ok
      ok  
   next
 
   if mini != maxDistance
      cost += kmin
   ok
 
return nCity 


//------------------------------------

Func takeInput()

   NodeName = ["A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","R","S","T","U","V","W","X","Y","Z"]
 
   See "Enter the number of villages: "
   Give node   node = number(node)
   
   Array = list(node,node)                // Create array matrix 
 
   See nl+"Enter the Cost Matrix: "+ nl
 
   for i = 1 to node 
   
      See nl+"Enter Elements of Row: "+ (i) +nl
 
      for j = 1 to node
         Give Element   Element = number(Element)
         
         array[i][j] = Element
    
         completed[i] = 0
      next
   next
 
   See nl+nl+"The cost list is: "
 
   for i = 1 to  node
   
      See nl
 
      for j = 1 to node
         See "  "+ array[i][j]
         
      next
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

 
//------------------------------------
/*

                                1 2 3 4
         A    4    B          1 0 4 1 3
                              2 4 0 2 1
         3   1,1   2          3 1 2 0 5
                              4 3 1 5 0
         C    5    D
              
Output

Enter the number of villages: 4

Enter the Cost Matrix
Enter Elements of Row: 1
0 4 1 3

Enter Elements of Row: 2
4 0 2 1

Enter Elements of Row: 3
1 2 0 5

Enter Elements of Row: 4
3 1 5 0

The cost list is:
0 4 1 3
4 0 2 1
1 2 0 5
3 1 5 0

The Path is:
1—>3—>2—>4—>1

Minimum cost is 7

==================

   1  2  3  4                         A
1  0 10 15 20                       / | \
2 10  0 35 25                     /   D   \
3 15 35  0 30                   /    /  \   \
4 20 25 30  0                  B  /------- \ C


 TSP tour in the graph is 1-2-4-3-1. 
 The cost of the tour is 10+25+30+15 which is 80.
*/        
