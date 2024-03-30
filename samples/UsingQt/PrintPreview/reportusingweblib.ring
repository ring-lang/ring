# Create Report using the WebLib & GUILib
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

load "stdlib.ring"
load "weblib.ring"
load "guilib.ring"

import System.Web
import System.GUI

new qApp {
	openWindow(:CustomersReportController)
	exec()
}

class CustomersReportController from WindowsControllerParent

	oView = new CustomersReportView

	func Start
		CreateReport()

	func CreateReport
		mypage = new HtmlPage {
			h1 { text("Customers Report") }
			Table
		        {
				style = stylewidth("100%") + stylegradient(4)
				TR
				{
					TD { WIDTH="10%" text("Customers Count : " )  }
                	        	TD { text (100) }
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
				for x =  1 to 100
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
		write("report.html",mypage.output())

	func PrintEvent
		printer1 = new qPrinter(0) {
			setoutputformat(1)
			setoutputfilename("report.pdf")
		}
		oView {
			web.print(printer1, Method( :OpenPDF ))
			web.show()
		}
	
	func OpenPDF
		new QDesktopServices { 
			OpenURL(new qURL("report.pdf") ) 
		} 
	
class CustomersReportView

		win = new window() {
	                setwindowtitle("Report Window")
        	        setgeometry(100,100,500,500)
                	web = new webview(win) {
                        	setgeometry(100,100,1000,500)
	                        loadpage(new qurl("file:///"+substr(currentdir(),"\","/")+"/report.html"))
        	        }
                	new pushbutton(win) {
                        	setGeometry(100,20,100,30)
	                        settext("Print")
        	                setclickevent(Method(:PrintEvent))
                	}
			showMaximized()
       	 	}

