
Load "stdlibcore.ring"
Load "matrixlib.ring"

//http://learnwebgl.brown37.net/transformations2/transformations_matrices.html
//Radian = 180/Pi = 57 Degrees. 360 Degrees = 2PI  180Degress = Pi

i = PI/180
j = PI/180
k = PI/180

oldX = 1   newX = 45  matX = 10
oldY = 1   newY = 45  matY = 10
oldZ = 1   newZ = 45  matZ = 10

Z1 = [[cos(-i), -sin(-i),  0,        0],
      [sin(-i),  cos(-i),  0,        0],
      [0,        0,        1,        0],
      [0,        0,        0,        1]]1

Y1 = [[cos(-j),  0,        sin(-j),  0], 
      [0,        1,        0,        0],
      [-sin(-j), 0,        cos(-j),  0],
      [0,        0,        0,        1]]

X1 = [[1,        0,        0,        0],
      [1,        cos(k),  -sin(k),   0],       
      [0,        sin(k),   cos(k),   0], 
      [0,        0,        0,        1]]

Y2 = [[cos(j),   0,        sin(j),   0], 
      [0,        1,        0,        0],
      [-sin(j),  0,        cos(j),   0],  
      [0,        0,        0,        1]]   

Z2 = [[cos(i),  -sin(i),   0,        0],
      [sin(i),   cos(i),   0,        0],
      [0,        0,        1,        0],
      [0,        0,	        0,        1]]
	  
T5 = [[matX],  // Matrix 5 Combo
      [matY],
      [matZ],
      [1]]	  

R1 = [[oldX],  // Old position
      [oldY],
      [oldZ],
      [1]]

S2 = [[newX],  // New position
      [newY],
      [newZ],
      [1]]
	  
	  
// MatrixMultiply -- 5 Steps -- Z1*Y1*X1+*Y2*Z2
T5 = MatrixMulti( MatrixMulti( MatrixMulti( (MatrixMulti(Z1,Y1)), X1), Y2), Z2)

See "Z1 T5: "    MatrixPrint(Z1)
See "Y1 T5: "    MatrixPrint(Y1)
See "X1 T5: "    MatrixPrint(X1)
See "Y2 T5: "    MatrixPrint(Y2)
See "Z2 T5: "    MatrixPrint(Z2)
See "R1 T5: "    MatrixPrint(R1)
See "S2 T5: "    MatrixPrint(S2)

// Use for iterative T5 * Old Position
S2 = MatrixMulti(T5, R1 )    

See "Z1 S2 = T5, R1: "    MatrixPrint(Z1)
See "Y1 S2 = T5, R1: "    MatrixPrint(Y1)
See "X1 S2 = T5, R1: "    MatrixPrint(X1)
See "Y2 S2 = T5, R1: "    MatrixPrint(Y2)
See "Z2 S2 = T5, R1: "    MatrixPrint(Z2)
See "R1 S2 = T5, R1: "    MatrixPrint(R1)
See "S2 S2 = T5, R1: "    MatrixPrint(S2)


for i = 1 to 5
   R1 = S2
   S2 = MatrixMulti(T5, R1 )
   See "S2 T5, R1 Loop: "+i     MatrixPrint(S2)


next
//=================================
//=================================
/*

Rotate angle degrees about any axis defined as <ux,uy,uz>:

Let’s derive a transformation for rotating about any axis by combining the transformations we have already created. 
This will give you an example of how basic transformations can be combined to form more complex transformations. 
If we want to rotate about an axis defined by <ux, uy, uz>, 
then we can accomplish this by performing the following sequence of transformations:

1 Rotate about the Z axis to place the vector <ux, uy, uz> in the Z-X plane. 
  Let’s call this new vector <ux’, uy’, uz’>.
2 Then rotate about the Y axis to place <ux’, uy’, uz’> along the X axis.
3 Then rotate about the X axis the desired angle.
4 Then rotate about the Y axis to place <ux’, uy’, uz’> back to its original location.
5 Then rotate about the Z axis to place <ux, uy, uz> back in its original location.

This series of 5 rotations will provide the visual affect of rotating a model about the axis <ux,uy,uz>. 
But we don’t want to do all of the 5 transformations over and over again for each vertex. 
We want a single transformation that will produce the visual motion we desire. 
We can accomplish this by multiplying the 5 matrices together before we start rendering, 
and then use a single transformation matrix to perform the desired rotation. 
To make this idea clear, lets perform the 5 transformations above in the order they are specified. 
The order is critical, because if you change the order, you will get a very different result.

We need to calculate 2 angles of rotation that will get the axis of rotation aligned with the X axis. 
Let i be the angle in step one, j be the angle for step two, and k be the angle for step 3. 
And let’s use s() and c() to represent the sin and cosine functions. 
The transformation looks like this:

*/
