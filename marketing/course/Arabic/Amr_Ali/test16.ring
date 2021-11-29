/*
**	Application	: variables (String) - Date , Time
**	Author    	: Amr Ali
**	Date   		: 08/03/2018
*/
####################################################################
# Variables types(String, Number, List, Object, c object)

? Date() 
? time()
			// Ring Language Not Case Sensitive important
cDate = date()
cdate1 = "08/10/2017"        # This is a practical Example to make 
			     # The first date of Last period for Gynecologist

cdate2 = "15/07/2018"
# cTime = time()
# ? cDate ? ctime

cDays = addDays(cdate1, 280) # Magnificent 
? cDays

cDays2 = diffdays(cdate2, cdate1)
see cDays2 ? " Days"
