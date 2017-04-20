Load "guilib.ring"

New qApp {
                 win1 = new qMainWindow() 
                {
                            setGeometry(100,100,450,500)
                            setwindowtitle("Using QDial")
                            button1 = new QPushButton(win1){
                                                    setGeometry(100,350,100,30)
                                                    settext("Increment")
                                                    setClickEvent("pIncrement()")
                            }

                            button2 = new QPushButton(win1){
                                                    setGeometry(250,350,100,30)
                                                    settext("Decrement")
                                                    setClickEvent("pDecrement()")
                                               
                            }
 
                            pdial = new qdial(win1) {
                                       setGeometry(100,50,250,300)
                                       setNotchesVisible(true)
                                       setValue(50)
                            }

                            lineedit1 = new qlineedit(win1) {
                                            setGeometry(200,400,50,30)
                                            setalignment(Qt_AlignHCenter)
                                            settext(string(pdial.value())) 
                            } 

                  show()
                  }
                  exec()
                  }

func pIncrement
       pdial{val=value()}
       pdial.setvalue(val+1)  
       lineedit1{settext(string(val+1))}   

func pDecrement
       pdial{val=value()}
       pdial.setvalue(val-1)   
       lineedit1{settext(string(val-1))}      
