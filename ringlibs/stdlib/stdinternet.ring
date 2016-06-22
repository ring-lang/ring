# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

if filename() = sysargv[2]
	eval("Load 'stdfunctions.ring'")
	eval("Load 'stdbase.ring'")
	internet_class_test()
ok

func internet_class_test
	
	ointernet = new internet
	See "Test the internet Class Methods" + nl
	ointernet { 
		see download("www.ring-lang.sf.net")
	}

Class internet
 
	Func download cURL
		return std_download(cURL)

	Func sendemail cSMTPServer,cEmail,cPassword,cSender,cReceiver,cCC,cTitle,cContent
		std_sendemail(cSMTPServer,cEmail,cPassword,cSender,cReceiver,cCC,cTitle,cContent)
