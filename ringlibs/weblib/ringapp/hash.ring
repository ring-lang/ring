Load "openssllib.ring"

Import System.Web

Func TestHash

	New Page 
	{

		boxstart()
			text( "Hash Test")
		 	newline()
		boxend()

		link([ :url = website, :title = "back" ]) 	
		newline() 		

		divstart([:style = StyleFloatLeft() + StyleWidth("100px") ])
			newline()
			text( "Value : " )  	
			newline() newline()
		divend()

		formpost(website)

			hidden("page",12)
			divstart([:style = StyleFloatLeft() + StyleWidth("300px") ])
				newline()
				textbox([ :name = "Value" ]) 	
				newline() newline()
				submit([ :value = "Send" ])
			divend()

		formend()

	}

Func TestHashResponse

	New Page 
	{

		boxstart()
			text( "Hash Result" )
			newline()
		boxend()

		link([ :url = website+"?page=11", :title = "back" ]) newline() 		

		divstart([:style = styleFloatLeft() + styleWidth("100%") ])
			newline()
			text( "Value : " + aPageVars["Value"] )  	
			newline()
			text( "MD5 : " + md5(aPageVars["Value"]) )  	
			newline()
			text( "SHA1 : " + SHA1(aPageVars["Value"]) )
			newline()
			text( "SHA256 : " + SHA256(aPageVars["Value"]) )
			newline()
			text( "SHA224 : " + SHA224(aPageVars["Value"]) )
			newline()
			text( "SHA384 : " + SHA384(aPageVars["Value"]) )
			newline()
			text( "SHA512 : " + SHA512(aPageVars["Value"]) )
			newline()

		divend()

		
	}	