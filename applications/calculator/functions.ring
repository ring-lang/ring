/*
 +---------------------------------------------------------------------------------------------------------
 +     Program Name : Calculator
 +     Date                : 2016-2017
 +     Author             : Magdy Ragab
 +                           : Gal Zsolt (~ CalmoSoft ~)
 +---------------------------------------------------------------------------------------------------------
*/

func typeNumbers x
        edit1.settext(edit1.text()+x)
        spaceflag = 1
 
func math x
        edit1.settext(edit1.text()+ x )
        spaceflag = 1
	
func addPeriod
	edit1.settext(edit1.text()+'.')
             spaceflag = 1

func clearCalc
	num1=0
	num2=0
	m="+"
	edit1.settext("")

func calcPercent
	edit1.settext(""+ edit1.text()+"%")
             spaceflag = 1

func checkEnter
	try
                 enum = edit1.text()
                 enum = substr(enum, " ", "")
                 check = checkEdit()
                 if check = 0
                     new qmessagebox(win1) {
                     setwindowtitle("Bad input") 
                     settext("Bad input!")
                     show()
                     } 
                 else
                     per = substr(edit1.text(), "%")
                     if per > 0
                        eval("number = " + left(enum, per - 1))
                        percent = number(substr(enum, per+1))
                        result = number*percent/100
                        edit1.settext( ""+result )
	          add2history(enum,result)
                     else                 
	          enum= edit1.text()
	          eval("result="+enum)
	          edit1.settext( ""+result )
	          add2history(enum,result)
                     ok
                 ok
	catch
	       see nl+cCatchError+nl
	       edit1.settext( "NAN" )
	done	
	
func add2history enum,result
	oDB = sqlite_init()
	sqlite_open(oDB,'calc.db')
	sqlite_execute(oDB, "insert into `calc` (`math`, `result`) values('"+ enum +"','"+ result +"');")
	sqlite_close(oDB)
 	
func deletehistory
	oDB = sqlite_init()
	sqlite_open(oDB,'calc.db')
	sqlite_execute(oDB, "delete from calc ;")
	sqlite_close(oDB)
	win2.close()
	memo()

func checkEdit
        enum= edit1.text()
        enum = substr(enum, " ", "")
        flag = 1
        nflag = list(len(enum))
        for n = 1 to len(enum)
              nflag[n] = 0
        next
        for n = 1 to len(enum)
              en = enum[n]
              if (ascii(en) > 47 and ascii(en) < 58) or en = "+" or en = "-" or en = "*" or en = "/" or en = "%" or en = "." or en = "(" or en = ")"
                 nflag[n] = 1
              ok               
        next
        for n = 1 to len(enum)
              if nflag[n] != 1
                 flag = 0
              ok
        next
        en1 = substr(enum, len(enum) - 1, 1)
        en2 = right(enum, 1)
        bool1 = (en1 = "+" or en1 = "-" or en1 = "*" or en1 = "/" or en1 = "%" or en1 = ".")
        bool2 = (en2 = "+" or en2 = "-" or en2 = "*" or en2 = "/" or en2 = "%" or en2 = ".")
        if bool1 = true and bool2 = true
           flag = 0
        ok
        return flag
 



