Import System.Web

Func TestRandom

	New Page 
	{

		boxstart()
			text( "Random Test")
		 	newline()
		boxend()

		link([ :url = website, :title = "back" ]) 	
		newline() 		

		divstart([ :style = styleFloatLeft() + styleWidth("400px") ])
			newline()
			aList = dir(cUploadPath)
			if len(aList) > 0
				nIndex = random(len(aList)) 
				if nindex = 0 nIndex = 1 ok
				text("Files Count : " + len(aList) ) 
				newline()
				for x = 1 to len(aList) text("("+x+") "+alist[x][1]) newline() next
				text("Random Image : " + nIndex)
				newline()
				cItem = "upload/" + aList[nIndex][1]
				newline()
				image( [ :url = cItem , :alt = :image  ] )
			else
				text("No images!") newline()
			ok
		divend()

	}