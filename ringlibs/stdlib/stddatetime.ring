# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

if filename() = sysargv[2]
	eval("Load 'stdfunctions.ring'")
	eval("Load 'stdbase.ring'")
	datetime_class_test()
ok

func datetime_class_test
	
	odatetime = new datetime

	See "Test the datetime Class Methods" + nl

Class datetime 

	Func std_clock
		return clock()

	Func std_time
		return time()

	Func std_date
		return date()

	Func std_timelist
		return timelist()

	Func std_adddays cDate,nDays
		return adddays(cDate,nDays)

	Func std_diffdays cdate1,cdate2
		return diffdays(cdate1,cdate2)
