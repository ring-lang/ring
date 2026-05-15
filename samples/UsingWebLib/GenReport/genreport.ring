load "weblib.ring"
import system.web 

func main

	t1 = clock()
	cOutput = createReport()
	t2 = clock()
	? "Time: " + (t2-t1) + " ms"
	write("report.html", cOutput)
	system("report.html")

func createReport 

	nCustCount = 100

	oPage = new HtmlPage { 
		h1 { text("Customers Report") }
		Table 
		{ 
			style = styleWidth("100%")+styleGradient(4)
			TR 
			{ 
				TD { WIDTH = "10%" text("Customers Count : ") }
				TD { text(nCustCount) }
			}
		}
		Table 
		{ 
			style = styleWidth("100%")+styleGradient(26)
			TR 
			{ 
				style = styleWidth("100%")+styleGradient(24)
				TD { text("Name ") }
				TD { text("Age") }
				TD { text("Country") }
				TD { text("Job") }
				TD { text("Company") }
			}
			for t=1 to nCustCount 
				TR 
				{ 
					TD { text("Test "+t) }
					TD { text("30") }
					TD { text("Egypt") }
					TD { text("Sales") }
					TD { text("Future") }
				}
			next 
		}
	}

	return oPage.output()

	