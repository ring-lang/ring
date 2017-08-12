load "guilib.ring"

manager = null

new qApp
{
	win1 = new qWidget()
	{
		resize(400,400)
		SetWindowTitle("Download ")
		new qPushButton(win1)
		{
			resize(100,30)
			setText("Download")
			setClickEvent("pDownload()")

		}
		show()
	}

	exec()
}

Func pDownload

	oUrl = new QUrl("http://ring-lang.sourceforge.net")
	see "Download..." + nl

	request = new qNetworkRequest(oUrl)
	see "request..." + nl
	request.setrawheader(new qbytearray().append("User-Agent"), new qbytearray().append("Application"))
	manager = new qNetworkAccessManager(win1) 
	{
		setfinishedevent("pfinish()")
	}

	manager.getvalue(request)
	see "done" + nl

func pfinish
	see "file downloaded!" + nl
	myobj = new qNetworkReply
	myobj.pObject = manager.getEventParameters()[1]
	see myobj.readall().data()
	see "ok..." + nl

