/*
          Application        :Application of Age Calculation
          Author             :Islam Deraz
          Date               :2018.02.12
          Application Number :1
*/ 
# variable Types (string, number, list, object, c object)


 # 

? "Welcome" 
? "Enter your name: " 
give Name 
? "Hello " +Name 

? "Enter your Born-day: " 
give nday
 

? "Enter your Born-month: " 
give nmonth

? "Enter your Born-year: " 
give nyear

? "Enter the current day: " 
give nday1


? "Enter the current month: " 
give nmonth1

? "Enter the current year: " 
give nyear1

nday2=0+(nday1-nday)

if nday2 < 0
		{

nmonth2=(0+nmonth1)-1
nmonth3=(0+nmonth2)-nmonth
nday3=(0+nday1)+30
nday4=(0+nday3)-nday
? "your Age is: " +nday4 + "Day" 

if 	nmonth3 < 0
nyear2=(0+nyear1)-1
nyear3=(0+nyear2)-nyear
nmonth4=(0+nmonth2)+12
nmonth5=(0+nmonth4)-nmonth
? "	   : " +nmonth5 + "Month" 
? "	   : " +nyear3 + "Year" 


elseif 	nmonth3 >= 0
nyear3=(0+nyear1)-nyear
? "	    : " +nmonth3 + "Month" 
? "	    : " +nyear3 + "Year" 

end

		 }


if  	nday2 >=  0

		 {
nmonth2=(0+nmonth1)-nmonth
? "your Age is: " +nday2 + "Day" 


if 	nmonth2 < 0
nyear2=(0+nyear1)-1
nyear3=(0+nyear2)-nyear
nmonth4=(0+nmonth1)+12
nmonth5=(0+nmonth4)-nmonth
? "	    : " +nmonth5 + "Month" 
? "	    : " +nyear3 + "Year" 


elseif 	nmonth2 >= 0
nyear3=0+(nyear1-nyear)
? "	    : " +nmonth2 + "Month" 
? "	    : " +nyear3 + "Year" 

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
