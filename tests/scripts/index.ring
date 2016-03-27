#!b:\mahmoud\apps\nova2\nova.exe 

load "weblib.nova"

import System.Web

website = "http://localhost/novaapp/index.nova"

func main
	o1 = new Application 
	{
	    	if get("REQUEST_METHOD") = "GET"
			cInput = get("QUERY_STRING")
			if cInput = "" # main page 
				mainpage()	
			else
				aVars = decode(cInput)
				if getvalue(aVars,"page") = 1
					secondpage() 				
				else
					error()
				ok 
			ok
		ok	
	}	

func mainpage
	o1 = new html 
	{
		see "Main Menu" newline()
		link(website+"?page=1","firstpage") newline()
		link("http://www.google.com","google") newline()
		see "You are welcome" newline()
	}

func secondpage	
	o1 = new html 
	{
		see "Second Page" newline()
		link(website,"back") newline() newline()
		button("Add") button("Edit") button("Delete") button("Find") newline() newline() 
		see "Name : " textbox("Name") newline() newline()
		see "Address : " textbox("Address") newline() newline()
		see "Phone : " textbox("Phone") newline() newline()
		see "Age : " textbox("Age") newline() newline()
		see "Note : " editbox("Notes") newline() newline()
	}

func error
	o1 = new html
	{
		see "Website error" newline()
		link(website,"main page")
	}