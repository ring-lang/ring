# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteWebBrowser

	func createWebBrowserControl  
		if ismacOSX()
			oWebView = new customWebView(this.win1) 
			oWBBack.hide()
		else 
			oWebView = new QWebView(this.win1) 
		ok
		oWebView {
			loadpage(new qurl(this.cWebSite))
		}

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

class customWebView from qQuickWidget 

	cQMLTemplate = `
		import QtQuick 2.2
		import QtWebView 1.0		
		WebView {
			id: webView
			objectName: "webView"
			url: "#{cURL}"
		}
	`
	func init oParent 
		super.init(oParent)
		QQuickWidget_SizeRootObjectToView = 1
		setResizeMode(QQuickWidget_SizeRootObjectToView)

	func loadPage oURL
		showPage(oURL.tostring(0))

	func showPage cURL
		setupdatesenabled(False)
		cQMLFile = exefolder()+"../tools/ringnotepad/rnote_webview.qml"
		write(cQMLFile,substr(cQMLTemplate,"#{cURL}",cURL))
		engine().clearcomponentcache()
		setSource(AppURL("file:///"+cQMLFile))
		setupdatesenabled(True)
		show()

	func back
