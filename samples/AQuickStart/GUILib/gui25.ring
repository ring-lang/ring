Load "guilib.ring"

New qApp {
        win1 = new qMainWindow() {
                setwindowtitle("QLabel - Display image")
                new qlabel(win1) {
                        image = new qpixmap("images/advice.jpg")
                        setpixmap(image)
                        setGeometry(0,0,image.width(),image.height())
                }
                showMaximized()
        }
        exec()
}
