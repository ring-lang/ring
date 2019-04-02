/* IS442 - moataz alsharqawy */ 
Load "guilib.ring"

New qApp {

        win1 = new qWidget() {

                setwindowtitle("TreeWidget")
                setGeometry(100,100,400,400)

                layout1 = new qvboxlayout()

                tree1 = new qtreewidget(win1) {
                        setGeometry(00,00,400,400)
                        setcolumncount(1)
                        myitem = new qtreewidgetitem()
                        myitem.settext(0,"The First Step")
                        addtoplevelitem(myitem)
                        for  x = 1 to 10
                                myitem2 = new qtreewidgetitem()
                                myitem2.settext(0,"hello"+x)
                                myitem.addchild(myitem2)
                                for  y = 1 to 10
                                        myitem3 = new qtreewidgetitem()
                                        myitem3.settext(0,"hello"+x)
                                        myitem2.addchild(myitem3)
                                next
                        next
                        setheaderlabel("Steps Tree")
                }

                layout1.addwidget(tree1)
                setlayout(layout1)

                show()
        }

        exec()
}
