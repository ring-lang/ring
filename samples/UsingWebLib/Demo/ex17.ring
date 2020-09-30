#!ring -cgi

Load "weblib.ring"
Import System.Web


cUploadPath = exefolder() + "../libraries/weblib/ringapp/upload/"

New Page 
{

	boxstart()
		text( "Random Test")
		newline()
	boxend()	

	divstart([ :style = styleFloatLeft() + styleWidth("400px") ])
		newline()
		aList = dir(cUploadPath)
		if len(aList) > 0
			nIndex = random(len(aList)) 
			if nindex = 0 nIndex = 1 ok
			cItem = "upload/" + aList[nIndex][1]
			newline()
			image( [ :url = cItem , :alt = :image  ] )
		else
			text("No images!") newline()
		ok
	divend()

}
