#!ring -cgi

Load "weblib.ring"
Load "datalib.ring"
Load "get.ring"
Load "mainpage.ring"
Load "post.ring"
Load "upload.ring"
Load "cookie.ring"
Load "template.ring"
Load "htmlsc.ring"
Load "hash.ring"
Load "random.ring"
Load "webpage.ring"
Load "table.ring"
Load "salarytable.ring"
Load "gradient.ring"
Load "pdf.ring"
Load "users.ring"
Load "htmllists.ring"
Load "bootstrap.ring"

Import System.Web

website = "index.ring"

cUploadPath = exefolder() + "../samples/UsingWebLib/Demo/upload/"
cUploadFolder = "/upload/"

cPDFPath = exefolder() + "../samples/UsingWebLib/Demo/temp/"
cPDFFolder = "/temp/"


Func Main

		if aPageVars["page"] = NULL
			mainpage()
		else
			switch aPageVars["page"]
			on 1
				testget()
			on 2
				testgetresponse()
			on 3
				testpost()
			on 4
				testpostresponse()
			on 5
				testupload()			
			on 6
				testuploadresponse()
			on 7
				testcookies()
			on 8
				testcookiesresponse()
			on 9
				testtemplate()
			on 10
				testhtmlsc()
			on 11
				testhash()
			on 12
				testhashresponse()
			on 13
				testrandom()
			on 14
				testwebpage()
			on 15
				testtables()
			on 16
				new salaryController { Routing() }
			on 17
				testgradient()
			on 18
				testpdf()
			on 19
				testregister()
			on 20
				testlogin()
			on 21
				testregisternew()
			on 22
				testlogincheck()
			on 23
				checkuser()
			on 24
				new usersController { Routing() }
			on 25
				testhtmllists()
			on 26
				testbootstrap()
			on 27
				testbootstrap2()
			on 28
				testbootstrap3()

			other
				errormsg("Invalid Link!")
			off
		ok


Func ErrorMsg x

	New Page
	{
		boxstart()
			text("Website Error!")
		boxend()
		divstart([ :style = stylesizefull()+stylecolor("black")+stylegradient(60)+stylefontsize("16px ") ])
			text(x)
			newline() link([ :url = website, :title = "index" ])
		divend()
	}
