load "httplib.ring"
load "weblib.ring"
import System.Web

? "Start the server..."
oServer = new Server 

? "Try localhost:8080/report"
oServer.route(:Get,"/report",:report)

? "Listen to port 8080"
oServer.listen("0.0.0.0", 8080)

func report
	oPage = New HTMLPage
	{
		nRowsCount = 10
		title = "Report"
		h1 { text("Customers Report") }
		Table
		{
			style = stylewidth("100%") + stylegradient(4)
			TR
			{
				TD { WIDTH="10%" text("Customers Count : " )  }
							TD { text (nRowsCount) }
			}
		}
		Table
		{
			style = stylewidth("100%") + stylegradient(26)
			TR
			{
				style = stylewidth("100%") + stylegradient(24)
				TD { text("Name " )  }
				TD { text("Age" ) }
				TD { text("Country" ) }
				TD { text("Job" ) }	
				TD { text("Company" ) }
			}
			for x =  1 to nRowsCount
				TR
				{
					TD { text("Test" )  }
					TD { text("30" ) }
					TD { text("Egypt" ) }
					TD { text("Sales" ) }	
					TD { text("Future" ) }
				}
			next
		}
	}

	oServer.setHTMLPage(oPage)
