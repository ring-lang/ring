# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteWebBrowser

	func WebGo
		cWebsite = oWBText.text()
		if lower(left(cWebsite,4)) != "http" and 
		   lower(left(cWebsite,5)) != "file:"
			cWebsite = "http://" + cWebsite
		ok
		oWebView.LoadPage( new qurl( cWebSite ) )

	func WebBack
		oWebView.Back()

	func SetWebsite
		oWebView { loadpage(new qurl(this.cWebSite)) }
		oWBText  { setText(this.cWebSite) }

	func BrowserLink x
		cLink = aBrowserLinks[x][2]
		oWebView { loadpage(new qurl(cLink)) }
		oWBText  { setText(cLink) }
		oDockWebBrowser.Show()
		oDockWebBrowser.raise()
