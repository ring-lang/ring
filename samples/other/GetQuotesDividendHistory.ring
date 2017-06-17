#!c:\RING\bin\ring.exe -cgi
load "internetlib.ring"
/*
 +--------------------------------------------------------------------------
 +        Program Name : GetQuotesDividendHistory.ring
 +        Date         : 2016.04.21
 +        Author       : Bert Mariani
 +        Purpose      : Fetch stock quotes history from finance.yahoo.com
 +--------------------------------------------------------------------------
*/

 
        ###
        ###   HistoryDate MM/DD/YYYY  Subtract -1 from Month.  03 returns => April 2015-04-15
        ###

        $MonthStart   = "01" 
        $DayStart     = "15" 
        $YearStart    = "2015"

        $MonthEnd     = "03" 
        $DayEnd       = "21" 
        $YearEnd      = "2016" 

        $DayWeekMonth = "v"                                ### Options are  "v" DIVEIDENDS, "d" daily, "w" weekly, "m" monthly QUOTES


        $symbol      = "T"                                 ### ATT-Telephone
        $urlbase     = "http://ichart.yahoo.com/table.csv?s="         
        $urlbaseType = "&a=" + $MonthStart + "&b=" + $DayStart + "&c=" + $YearStart + "&d=" + $MonthEnd + "&e=" + $DayEnd + "&f=" + $YearEnd + "&g=" + $DayWeekMonth + "&ignore=.csv"

        $url         = $urlbase + $symbol + $urlbaseType   ### Join as URL to fetch              

        see  $url + nl + nl
        see  $symbol +nl 

cStr= download($url)
see cStr
write("download.txt",cStr)

###================
### OUTPUT
###----------------
#
# http://ichart.yahoo.com/table.csv?s=T&a=01&b=15&c=2015&d=03&e=21&f=2016&g=v&ignore=.csv
# 
# T
# Date,Open,High,Low,Close,Volume,Adj Close
# 
# Date,Dividends
# 2016-04-06,0.480000
# 2016-01-06,0.480000
# 2015-10-07,0.470000
# 2015-07-08,0.470000
# 2015-04-08,0.470000
#
###================

