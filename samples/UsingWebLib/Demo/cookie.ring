Import System.Web

Func TestCookies

	New page 
	{
		boxstart()
			text( "Cookie Test" )
 			newline()
		boxend()
		link([ :url = website, :title = "back" ]) 	newline()
		link([ :url = website+"?page=8", :title = "Use Cookies" ]) 	
		cookie("custname","Mahmoud Fayed")
		cookie("custage",28)
		

	}

Func TestCookiesResponse

	New page 
	{

		boxstart()
			text( "Cookies Values" )
			newline()
		boxend()
		link([ :url = website+"?page=7", :title = "back" ]) 			
		newline() 

		divstart([:style="float:left;width:200px"])
			text( "Name : " + aPageVars["custname"] )
		  	newline()
		  	text( "Age : " + aPageVars["custage"] )
		  	newline()
		divend()
	

	}	
