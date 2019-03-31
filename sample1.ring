/*
IS-422 - AbdulazizAli
*/
Load "guilib.ring"

New qApp {

        win1 = New qWidget() {

                setwindowtitle("Using QTreeView and QFileSystemModel")
                setGeometry(100,100,500,400)

                New qtreeview(win1) {
                        setGeometry(00,00,500,400)
                        oDir = new QDir()
                        ofile = new QFileSystemModel()
                        ofile.setrootpath(oDir.currentpath())
                        setmodel(ofile)
                }

                show()
        }

        exec()
}
