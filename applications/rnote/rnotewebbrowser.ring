# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

Class RNoteWebBrowser

	func pWebGo
		cWebsite = oWBText.text()
		oWebView.LoadPage( new qurl( cWebSite ) )

	func pWebBack
		oWebView.Back()

	func pSetWebsite
		oWebView { loadpage(new qurl(this.cWebSite)) }
		oWBText  { setText(this.cWebSite) }

	func pBrowserLink x
		cLink = aBrowserLinks[x][2]
		oWebView { loadpage(new qurl(cLink)) }
		oWBText  { setText(cLink) }
		oDockWebBrowser.Show()
		oDockWebBrowser.raise()
