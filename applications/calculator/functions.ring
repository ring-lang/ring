func typeNumbers x
	edit1.settext(edit1.text()+x)


func math x
	edit1.settext(edit1.text()+ x )
	
func addPrediod
	edit1.settext(edit1.text()+'.')


func clearCalc
	num1=0
	num2=0
	m="+"
	edit1.settext("")

func calcPercent
	edit1.settext(""+ edit1.text()+"%")

func checkEnter
	try
                 per = substr(edit1.text(), "%")
                 if per > 0
                    enum= edit1.text()
                    number = number(left(enum, per - 1))
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
