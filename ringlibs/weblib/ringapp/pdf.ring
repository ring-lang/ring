Import System.Web

func testpdf

	New HTML2PDF
	{
		filepath  = cPDFPath
		filefolder = cPDFFolder
		divstart([ :style = stylebackcolor("purple") + stylecolor("white")  + styleheight("30px") + styletextcenter()])
			text("PDF File")
		divend()
		divstart([ :style = stylebackcolor("blue") + stylecolor("white")   ])
			text("  Hello")
			newline()
			text("  Welcome")
			newline()
			For x = 1 to 10
				text("  " + x)
				newline()
			Next
		divend()
		divstart([ :style = stylebackcolor("purple") + stylecolor("white")  + styleheight("30px") + styletextcenter()])
			text("Thank You!")
		divend()
		aList = dir(cUploadPath)
		if len(aList) > 0
			nIndex = random(len(aList)) 
			if nindex = 0 nIndex = 1 ok
			cItem = cUploadPath + aList[nIndex][1]
			newline()
			image( [ :url = cItem , :alt = :image  ] )
		ok
	}

