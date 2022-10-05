/*
          Application        :Variables (Strings) - Date & Time
          Author             :Islam Deraz
          Date               :2018.02.12
          Application Number :1
*/ 
# variable Types (string, number, list, object, c object)

? date()
cdate = date()

? time()
ctime = time()

cdate1 =adddays(cdate,6)
?cdate1
cdate2 =diffdays(cdate1,cdate)
?cdate2


 # Application of age Calculation

? "Welcome" 
see "Enter your name: " +nl
give Name 
see "Hello " +Name +nl

see "Enter your Born-day: " +nl
give nday
 

see "Enter your Born-month: " +nl
give nmonth

see "Enter your Born-year: " +nl
give nyear

see "Enter the current day: " +nl
give nday1


see "Enter the current month: " +nl
give nmonth1

see "Enter the current year: " +nl
give nyear1

nday2=0+(nday1-nday)

if nday2 < 0
		{

nmonth2=(0+nmonth1)-1
nmonth3=(0+nmonth2)-nmonth
nday3=(0+nday1)+30
nday4=(0+nday3)-nday
see "your age is: " +nday4 + "Day" +nl

if 	nmonth3 < 0
nyear2=(0+nyear1)-1
nyear3=(0+nyear2)-nyear
nmonth4=(0+nmonth2)+12
nmonth5=(0+nmonth4)-nmonth
see "	   : " +nmonth5 + "Month" +nl
see "	   : " +nyear3 + "Year" +nl


elseif 	nmonth3 >= 0
nyear3=(0+nyear1)-nyear
see "	    : " +nmonth3 + "Month" +nl
see "	    : " +nyear3 + "Year" +nl

end

		 }


if  	nday2 >=  0

		 {
nmonth2=(0+nmonth1)-nmonth
see "your age is: " +nday2 + "Day" +nl


if 	nmonth2 < 0
nyear2=(0+nyear1)-1
nyear3=(0+nyear2)-nyear
nmonth4=(0+nmonth1)+12
nmonth5=(0+nmonth4)-nmonth
see "	    : " +nmonth5 + "Month" +nl
see "	    : " +nyear3 + "Year" +nl


elseif 	nmonth2 >= 0
nyear3=0+(nyear1-nyear)
see "	    : " +nmonth2 + "Month" +nl
see "	    : " +nyear3 + "Year" +nl

end

		  }
/*
elseif 	nday2 < 0 
nmonth3=0+(nmonth2-nmonth)
*/
		
# end

/*
if 	nmonth3 < 0
nyear2=(0+nyear1)-1
nyear3=(0+nyear2)-nyear
nmonth4=(0+nmonth2)+12
nmonth5=0+(nmonth4-nmonth)

see "the year is: " +nyear3 +nl
see "the month is: " +nmonth5 +nl

elseif 	nmonth3 >= 0
nyear3=0+(nyear1-nyear)
see "the year is: " +nyear3 +nl
see "the month is: " +nmonth3 +nl
end
*/
