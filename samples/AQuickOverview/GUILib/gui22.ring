Load "guilib.ring"

New qApp {
        win1 = new qMainWindow() {
                setwindowtitle("QLabel - Hyperlink")
                new qlabel(win1) {
                        setGeometry(100,100,100,30)
                        setopenexternallinks(true)
                        settext('<a href="http://google.com">Google</a>')
                }
                showMaximized()
        }
        exec()
}
