Import System.Web

Func MainPage

	New Page
	{

		divstart([ :style = stylesizefull() + stylebackcolor("cyan") ])

		boxstart()
			text( "Main Menu - Welcome!" )
		boxend()

		newline() newline()
		text("Hello")	newline()
		text( " Date : " + date() + " Time : " + Time())
	 	newline() newline()
		link([ :url = website+"?page=1", :title = "(1) HTTP GET" ])
		newline()
		link([ :url = website+"?page=3", :title = "(2) HTTP POST" ])
	 	newline()
		link([ :url = website+"?page=5",:title = "(3) Upload" ]) 		newline()
		link([ :url = website+"?page=7",:title = "(4) Cookies" ]) 		newline()
		link([ :url = website+"?page=2&Name="+URLEncode("-*{Fine & Happy = Good}*-")+
			"&Address=Egypt&Phone=123456&Age=28&Notes=Programmer", :title = "(5) Test URL Encode" ])
		newline()
		link([ :url = website+"?page=9",:title = "(6) Templates" ]) 	newline()
		link([ :url = website+"?page=10",:title = "(7) HTML Special Characters" ]) newline()
		link([ :url = website+"?page=11",:title = "(8) Hash Functions"]) newline()
		link([ :url = website+"?page=13",:title = "(9) Random Image" ]) newline()
		link([ :url = website+"?page=14",:title = "(10) Web Page Content using Objects" ])
		newline()
		link([ :url = website+"?page=15",:title = "(11) HTML Tables" ])
		newline()
		link([ :url = website+"?page=16&part=1",:title = "(12) Salary Table" ])
		newline()
		link([ :url = website+"?page=17",:title =  "(13) Gradient" ])
		newline()
		link([ :url = website+"?page=18",:title =  "(14) PDF File" ])
		newline()
		link([ :url = website+"?page=19",:title =  "(15) Register" ])
		newline()
		link([ :url = website+"?page=20",:title =  "(16) Login" ])
		newline()
		link([ :url = website+"?page=23",:title =  "(17) Check User" ])
		newline()
		link([ :url = website+"?page=24&part=1",:title = "(18) Users Table" ])
		newline()
		link([ :url = website+"?page=25",:title =  "(19) HTML Lists" ])
		newline()
		link([ :url = website+"?page=26",:title =  "(20) Bootstrap - functions" ])
		newline()
		link([ :url = website+"?page=27",:title =  "(21) Bootstrap - objects" ])
		newline()
		link([ :url = website+"?page=28",:title =  "(22) Bootstrap - html" ])
		newline()
		newline()

		divend()
	}
