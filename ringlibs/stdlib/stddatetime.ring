# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

Load "stdfunctions.ring"
Load "stdbase.ring"
Load "stdlibcore.ring"

if IsMainSourceFile() 
	datetime_class_test()
ok

func datetime_class_test
	
	oDateTime = new datetime

	See "Test the datetime Class Methods" + nl

	See "Calculate performance" + nl
	t1 = oDateTime.clock()
	for x = 1 to 1000000 next
	see oDateTime.clock() - t1 + nl

	See "Time : " + oDateTime.time() + nl

	See "Date : " + oDateTime.date()  + nl

	See oDateTime.TimeList()

	See "Month Name : " + oDateTime.TimeList()[4]      

	cDate = oDateTime.date()
	see cDate + nl                  
	cDate = oDateTime.adddays(cDate,10)
	see cDate + nl 

	cDate1 = oDateTime.date()
	see cDate1 + nl                                          
	cDate2 = oDateTime.adddays(cDate1,10)
	see cDate2 + nl                                          
	see "DiffDays = " + oDateTime.diffdays(cDate1,cDate2) + nl         
	see "DiffDays = " + oDateTime.diffdays(cDate2,cDate1) + nl       

Class datetime 

	Func clock
		return std_clock()

	Func time
		return std_time()

	Func date
		return std_date()

	Func timelist
		return std_timelist()

	Func adddays cDate,nDays
		return std_adddays(cDate,nDays)

	Func diffdays cdate1,cdate2
		return std_diffdays(cdate1,cdate2)
