#!ring -cgi

Load "weblib.ring"
Import System.Web

New NumbersController { start() }

Class NumbersController

	MyHeader aNumbers		

	Func Start

		MyHeader = New Header
		{
			cColumn1 = "Number" cColumn2 = "Square"
		}

		aNumbers = list(20)

		for x = 1 to len(aNumbers)
			aNumbers[x] = new number
			{
				nValue  = x   nSquare = x*x
			}
		next	  

		cTemp = Template("mynumbers.html",self)

		New Page 
		{ 			
			boxstart()
				text( "Test Templates" )  			
				newline()
			boxend()
			html(cTemp)  
		} 

Class Header cColumn1 cColumn2
Class Number nValue   nSquare
