# Author: Bert Mariani

load "matrixlib.ring"
load "fastpro.ring"

           
aListA = [1:5,
          2:6,
          3:7,
          4:8,
          5:9,
		  6:10]
		  
aListB = [7:11,
          8:12,
          9:13,
          10:14,
          11:15,
		  12:16]		  
          


See "aListA: "   MatrixPrint(aListA)
See "aListB: "   MatrixPrint(aListB)

//==================================
// Ring

Axis = 0  // 0=Verr
aListC = Append (aListA, aListB, Axis)
See "Ring Append: Axis Vert: "+Axis  MatrixPrint(aListC)  

Axis = 1  // 1=Horz
aListC =Append (aListA, aListB, Axis)
See "Ring Append: Axis Horz: "+Axis  MatrixPrint(aListC) 

//--------------------

// FastPro
Axis = 0  // 0-Vert
aListC = updatelist(aListA,:append,:matrix,aListB, Axis)
See "FastPro Append: Axis Vert: "+Axis  MatrixPrint( aListC)

Axis = 1  // 1-Horz
aListC = updatelist(aListA,:append,:matrix,aListB, Axis)
See "FastPro Append: Axis Horz: "+Axis  MatrixPrint( aListC)


//====================================
//====================================
// SPEED TEST

X = 500
Y = 500

aListA = list(X,Y)
         updateList(aListA,:random,:matrix )    // 0.00 to 1.00
aListA = updateList(aListA,:scalar,:matrix,10 ) // Mul by 10

aListB = list(X,Y)
         updateList(aListA,:random,:matrix )    // 0.00 to 1.00
aListB = updateList(aListA,:scalar,:matrix,10 ) // Mul by 10


//=================================
// RING

Axis = 0
         t1   = clock()
aListC = Append (aListA, aListB, Axis)
         t2   = clock()
         Diff = t2 -t1

See "RING Append Axis: "+Axis +"  "+X +"x"+Y +" Time "+ Diff +" millisecs"+nl
//See "Ring Append"  MatrixPrint(aListC)


//==================================
// FastPro

Axis = 0
         t1 = clock()
Index = updatelist(aListA,:append,:matrix,aListB, Axis)
         t2   = clock()
         Diff = t2 -t1

See "FastPro Append: Axis: "+Axis +"  "+X +"x"+Y  +" Time "+ Diff +" millisecs"+nl
//See "FastPro Append "  MatrixPrint(aListC)

//==================================
//==================================

//=================================
// RING

Axis = 1
         t1   = clock()
aListC = Append (aListA, aListB, Axis)
         t2   = clock()
         Diff = t2 -t1

See "RING Append Axis: "+Axis +"  "+X +"x"+Y +" Time "+ Diff +" millisecs"+nl
//See "Ring Append"  MatrixPrint(aListC)


//==================================
// FastPro

Axis = 1
         t1 = clock()
Index = updatelist(aListA,:append,:matrix,aListB, Axis)
         t2   = clock()
         Diff = t2 -t1

See "FastPro Append: Axis: "+Axis +"  "+X +"x"+Y  +" Time "+ Diff +" millisecs"+nl
//See "FastPro Append "  MatrixPrint(aListC)


//===================================
//===================================


See nl+"FINISHED"+nl

//===================================
//===================================

//===================================
//Axis: 1=Horz  0=Vert

	func Append (MatrixA,MatrixB,Axis) { 
		aAppend = MatrixA                          // Copy A
		if Axis = 1 { 
			for v = 1 to len(MatrixB) {            // Row-B       
				for h = 1 to len(MatrixB[1]) {     // Col-B
					aAppend[v] + MatrixB[v][h]     // Add cell-B to A
				} 
			} 
			return aAppend
			
		elseif Axis = 0
				alist = []                         // Flat array
				for v = 1 to len(MatrixB) {        // Row-B
				        alist = []                 // Fix ...add
						
					for h = 1 to len(MatrixB[1]) { // Col-B 
						alist + MatrixB[v][h]      // Add  cell-B to Flat
					} 
					aAppend + alist                // Fix ... add 
				} 
							
				//aAppend + alist                    // Fix ... Remive
				return aAppend
		} 
	} 
//===================================
