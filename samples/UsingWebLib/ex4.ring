#!ring -cgi

Load "weblib.ring"
Import System.Web
New Page
{
  Title = "Test HTTP Get"
  divstart([ :style = StyleSizeFull() ] )
  boxstart()
        text( "Test HTTP GET" )
        newline()
  boxend()
  divstart([ :style = Styledivcenter("600px","550px") +
                      StyleGradient(21) ])
  divstart([:style = stylefloatleft() + stylesize("100px","100%") +
                     stylecolor("black") + stylegradient(58)])
  formstart("ex5.ring")
        tablestart([ :style = stylesize("65%","90%") +
                              stylemarginleft("35%") +
                              stylemargintop("30%") ])
          rowstart([])
                cellstart([ ])
                  text ( "Name : "  )
                cellend()
                cellstart([])
                  cTextboxStyle = StyleMarginLeft("5%") +
                                  StyleWidth("250px") +
                                  StyleColor("black") +
                                  StyleBackColor("white")
                  textbox([ :name = "Name", :style = cTextboxStyle ] )
                cellend()
          rowend()
          rowstart([])
                cellstart([])
                  text ( "Address : " )
                cellend()
                cellstart([ ])
                  textbox([ :name = "Address", :style = cTextboxStyle] )
                cellend()
          rowend()
          rowstart([])
                cellstart([])
                  text ( "Phone : " )
                cellend()
                cellstart([  ])
                  textbox([ :name = "Phone", :style = cTextboxStyle ])
                cellend()
          rowend()
          rowstart([])
                cellstart([])
                  text ( "Age : "  )
                cellend()
                cellstart([  ])
                  textbox([ :name = "Age", :style = cTextboxStyle ])
                cellend()
          rowend()
          rowstart([])
                cellstart([])
                  text ( "City: " )
                cellend()
                cellstart([  ])
                  listbox([ :name = "City", :items = ["Cairo","Riyadh","Jeddah"],
                         :style = stylemarginleft("5%") + stylewidth("400px") ] )
                cellend()
          rowend()
          rowstart([])
                cellstart([])
                  text ( "Country : " )
                cellend()
                cellstart([   ])
                  combobox([ :name = "Country",
                         :items = ["Egypt","Saudi Arabia","USA"],
                         :style = stylemarginleft("5%") +
                                  stylewidth("400px")+
                                  stylecolor("black")+
                                  stylebackcolor("white")+
                                  stylefontsize("14px") ])
                cellend()
          rowend()
          rowstart([])
                cellstart([])
                  text ( "Note : " )
                cellend()
                cellstart([   ])
                  editbox([ :name = "Notes",
                        :style = stylemarginleft("5%") +
                                 stylesize("400px","100px")+
                                 stylecolor("black")+
                                 stylebackcolor("white") ,
                        :value = "write comments here..." ] )
                cellend()
          rowend()
          rowstart([])
                cellstart([])
                cellend()
                cellstart([   ])
                  submit([ :value = "Send" , :Style = stylemarginleft("5%") ])
                cellend()
          rowend()
        tableend()
  formend()
  divend()
  divend()
  divend()
}
