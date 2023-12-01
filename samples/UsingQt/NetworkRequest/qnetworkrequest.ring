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

	oUrl = new QUrl("https://ring-lang.github.io")

	request = new qNetworkRequest(oUrl)
	request.setrawheader(new qbytearray().append("User-Agent"), new qbytearray().append("Application"))

	manager = new qNetworkAccessManager(win1) 
	{
		setfinishedevent("pfinish()")
	}

	manager.getvalue(request)

func pfinish
	reply = new qNetworkReply {  pObject = manager.getEventParameters()[1] }
	see reply.readall().data()



