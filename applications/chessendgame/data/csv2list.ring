#=============================================#
# Convert Chess CSV file to Ring File 
# 2021, Mahmoud Fayed <msfclipper@yahoo.com>
#=============================================#

func main 
	# Read the CSV file 
		? "Read the file (chess.csv)"
		cStr = read("chess.csv")
	# Process the Data 
		? "Process the data ..."
		aList = str2List(cStr)
		nIndex = 1
		nMax = len(aList)
		for item in aList
			item = "[" + item + "]"
			if nIndex != nMax 
				item += ","
			ok
			nIndex++
		next
		cStr = list2Str(aList)
		cStr = update(cStr)
		cData = "aList = [" + WindowsNL() + cStr + WindowsNL() + "]"
	# Write the Ring file 
		? "Write the Ring file (dataset.ring)"
		write ("dataset.ring",cData)

func update cStr
	aWords = [
		:a,
		:b,
		:c,
		:d,
		:e,
		:f,
		:g,
		:h,
		:draw,
		:zero,
		:one,
		:two,
		:three,
		:four,
		:five,
		:six,
		:seven,
		:eight,
		:nine,
		:ten,
		:eleven,
		:twelve,
		:thirteen,
		:fourteen,
		:fifteen,
		:sixteen,
		"WhiteKingFile",
		"WhiteKingRank",
		"WhiteRockFile",
		"WhiteRockRank",
		"BlackKingFile",
		"BlackKingRank",
		"GameResult"
	]

	nMax = len(aWords)
	for t = nMax to 1 step -1
		cStr = substr(cStr,"["+aWords[t]+",","["+Char(34)+aWords[t]+Char(34)+",")
		cStr = substr(cStr,","+aWords[t]+",",","+Char(34)+aWords[t]+Char(34)+",")
		cStr = substr(cStr,","+aWords[t]+"]",","+Char(34)+aWords[t]+Char(34)+"]")
	next
	
	return cStr