# To create 4x2x3  List

aList = [
	[  [1,2,3],[1,2,3]  ],
	[  [1,2,3],[1,2,3]  ],
	[  [1,2,3],[1,2,3]  ],
	[  [1,2,3],[1,2,3]  ]
]

nFirstDim  = len(aList)
nSecondDim = len(aList[1])
nThirdDim  = len(aList[1][1])
? "First  Dim : " + nFirstDim
? "Second Dim : " + nSecondDim
? "Third  Dim : " + nThirdDim
for y=1 to nFirstDim
	for x=1 to nSecondDim
		for z=1 to nThirdDim
			see aList[y][x][z]
			if z != nThirdDim
				see ","
			ok
		next
		if x != nSecondDim
			see " - "
		ok
	next
	see nl
next
