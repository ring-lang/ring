aMap = [
	[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
	[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
	[0,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0],
	[0,0,0,0,0,0,0,1,0,0,0,0,2,0,0,0,0],
	[0,0,0,0,0,0,0,0,1,0,0,2,0,0,0,0,1],
	[0,0,1,0,0,0,0,0,0,0,2,0,0,0,0,1,0],
	[0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0],
	[1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0]
]

C_WIDTH  = len(aMap[1])
C_HEIGHT = len(aMap)

checkWinner()

func checkWinner 

	lWin = False

	for nRow = 1 to C_HEIGHT
		for nCol = 1 to C_WIDTH
			cCell = aMap[nRow][nCol]
			if cCell = 0   loop ok

			if ( nRow + 3 <= C_HEIGHT and cCell=aMap[nRow+1][nCol] and
				cCell=aMap[nRow+2][nCol] and cCell=aMap[nRow+3][nCol] ) OR

			( nCol + 3 <= C_WIDTH and cCell=aMap[nRow][nCol+1] and
				cCell=aMap[nRow][nCol+2] and cCell=aMap[nRow][nCol+3] ) OR

			( nRow + 3 <= C_HEIGHT and nCol + 3 <= C_WIDTH and 
				cCell=aMap[nRow+1][nCol+1] and
				cCell=aMap[nRow+2][nCol+2] and  cCell=aMap[nRow+3][nCol+3] ) OR

			( nRow > 3 and nCol + 3 <= C_WIDTH  and cCell=aMap[nRow-1][nCol+1] and
				cCell=aMap[nRow-2][nCol+2] and  cCell=aMap[nRow-3][nCol+3] ) 

				lWin=True exit 2 
			ok
		next
	next

	if lWin ? "Winner=" + cCell else ? "No winner" ok
