#!c:\RING\bin\ring.exe -cgi
load "internetlib.ring"
/*
 +--------------------------------------------------------------------------
 +        Program Name : GetQuotesHistory.ring
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
        $YearStart    = "2016"

        $MonthEnd     = "03" 
        $DayEnd       = "21" 
        $YearEnd      = "2016" 

        $DayWeekMonth = "w"                                ### Options are  "d" daily, "w" weekly, "m" monthly


        $symbol      = "GOOGL"
        $urlbase     = "http://ichart.yahoo.com/table.csv?s="         
        $urlbaseType = "&a=" + $MonthStart + "&b=" + $DayStart + "&c=" + $YearStart + "&d=" + $MonthEnd + "&e=" + $DayEnd + "&f=" + $YearEnd + "&g=" + $DayWeekMonth + "&ignore=.csv"


        $url         = $urlbase + $symbol + $urlbaseType   ### Join as URL to fetch              

        see  $url + nl + nl
        see  $symbol + nl + "Date,Open,High,Low,Close,Volume,Adj Close" + nl + nl


cStr= download($url)
see cStr
write("download.txt",cStr)

###================
### OUTPUT
###----------------
#
# http://ichart.yahoo.com/table.csv?s=GOOGL&a=01&b=15&c=2016&d=03&e=21&f=2016&g=w&ignore=.csv
# 
# GOOGL
# Date,Open,High,Low,Close,Volume,Adj Close
# 
# Date,Open,High,Low,Close,Volume,Adj Close
# 2016-04-18,780.190002,790.950012,770.27002,780.00,2223300,780.00
# 2016-04-11,765.450012,780.929993,751.570007,780.00,1524700,780.00
# 2016-04-04,769.51001,772.440002,755.599976,759.469971,1250200,759.469971
# 2016-03-28,756.169983,777.309998,748.289978,769.669983,1658300,769.669983
# 2016-03-21,753.909973,765.390015,750.50,754.840027,1323000,754.840027
# 2016-03-14,744.969971,765.340027,742.840027,755.409973,1920700,755.409973
# 2016-03-07,725.150024,744.900024,704.00,744.869995,2306500,744.869995
# 2016-02-29,721.00,743.119995,716.840027,730.219971,2293300,730.219971
# 2016-02-22,729.51001,736.159973,702.02002,724.859985,1931400,724.859985
# 2016-02-16,718.650024,736.00,710.179993,722.109985,2165400,722.109985
#
###================

