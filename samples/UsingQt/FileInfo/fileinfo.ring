load "guilib.ring"

oFile = new qFileinfo()
oFile.setfile(filename())	# filename() return the current file name 
oDateTime = oFile.lastmodified()
oDate = oDateTime.date()
? "Day  : " + oDate.day()
? "Month: " + oDate.month()
? "Year : " + oDate.year()
oTime = oDateTime.time()
? "Second : " + oTime.second()
? "Minute : " + oTime.minute()
? "Hour   : " + oTime.hour()
