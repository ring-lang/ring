# Author : Magdy Ragab

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
	edit1.settext(""+ edit1.text()+"*100")




func checkEnter
	try
		enum= edit1.text()
		eval("result="+enum)
		edit1.settext( ""+result )
		add2history(enum,result)
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
