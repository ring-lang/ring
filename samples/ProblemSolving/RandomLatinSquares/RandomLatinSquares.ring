// Random Latin Squares
// Bert Mariani  2020-07-30
// Use "size" and "repeat" to Generate multiple size Squares

load "stdlib.ring"

size      = 10					// Size of Matrix .. Display formats up to 99
repeat    = 3					// Number of Matrix to Generate
a2DSquare = newlist(size,size)
a2DFinal  = newlist(size,size)


//===================================================
Func main

	for i = 1 to repeat							// Multiple Latin Squares
		aList  = 1:size
    	aList2 = RandomList(aList)

		//See nl+"New Random: ------------ "+nl
		//DisplayList(aList2)    				// ? aList2 = vertical output

		GenerateRows(aList2)
		ShuffleCols(a2DSquare, a2DFinal)

		DisplaySquare(a2DFinal)
    		
	next
return

//===================================================
// Generate Rows of data. Put them in the 2DArray

Func GenerateRows(aInput)

	aOutput = []
	size  = len(aInput)
    shift = 1

	for k = 1 to size									// Make 8 Rows of lists
		aOutput = []
		
		for i = 1 to size           					// make a list
			   pick = i + shift     					// shift every Row by +1 more
			if pick > size   pick = pick - size  ok
	
			aOutput + aInput[pick]
		next
	
		//See "List "
		//DisplayList(aOutput)
		
		a2DSquare[k] = aOutput							// Row of Output to a2DSquare

		shift++                    						// shift next line by +1 more
		if shift > size  shift = 1 ok
	next

	//See nl+ "Square "+nl
	//DisplaySquare(a2DSquare)

return

//===================================================
// Shift random Rows into a2DFinal, then random Cols

Func ShuffleCols(a2DSquare, a2DFinal)

	aSuffle  = 1:size
    aSuffle2 = RandomList(aSuffle)	// Pick random Col to insert in a2DFinal
	
	//See "aSuffle2 Random  "+nl
	//DisplayList(aSuffle2)

	for i = 1 to size           	// Row		
		pick = aSuffle2[i]

        for j = 1 to size			// Col
			a2DFinal[i][j] =  a2DSquare[pick][j]  // i-Row-Col j-Horz-Vert
		next
	next

	a2DSquare = a2DFinal			// Now do the verticals
	aSuffle  = 1:size
	aSuffle2 = RandomList(aSuffle)

	for i = 1 to size           	// Row		
		pick = aSuffle2[i]

        for j = 1 to size			// Col
			a2DFinal[j][i] =  a2DSquare[j][pick]  //Reverse i-j , i-Row-Col j-Horz-Vert
		next
	next


	//See "a2DFinal "+nl
	//DisplaySquare(a2DFinal)

return

//===================================================
// Display array on one line

Func DisplayList(aList)

	for i = 1 to len(aList)
		See " "+ aList[i]
	next
		See nl

return

//===================================================
// Display Square, if numbers <=9 pad with space

Func DisplaySquare(a2DSquare)

	size = len(a2DSquare)

	for i = 1 to size
		for j = 1 to size
				output =  a2DSquare[i][j]
			if output <= 9   output = " "+ output  ok
			See " "+ output
		next
		See nl
	next
		See nl

return

//===================================================
