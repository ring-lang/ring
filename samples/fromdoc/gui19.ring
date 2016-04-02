Load "guilib.ring"

New qApp {
        win1 = new qMainWindow() {
                setwindowtitle("QWebView")
                myweb = new qwebview(win1) {
                        setGeometry(10,10,600,600)
                        loadpage(new qurl("http://google.com"))
                }
                setcentralwidget(myweb)
                showMaximized()
        }
        exec()
}
