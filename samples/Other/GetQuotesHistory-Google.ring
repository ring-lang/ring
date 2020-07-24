### Works with Google Finance only
### For Yahoo use GetQuotesHistory-Yahoo.ring  uses Cookie and Crumb
load "internetlib.ring"
/*
 +--------------------------------------------------------------------------
 +        Program Name : GetQuotesHistory.ring
 +        Date         : 2016.04.21
 +        Author       : Bert Mariani
 +        Purpose      : Fetch stock quotes history from finance.yahoo.com
 +        Update       : 2017.06.06  Adapter for Google Finance only.
 +--------------------------------------------------------------------------
*/


    ###----------------------------------------------------------------------------------
    ###   HistoryDate MM/DD/YYYY  Subtract -1 from Month.  03 returns => April 2015-04-15

    $MonthStart   = "01"
    $DayStart     = "15"
    $YearStart    = "2016"

    $MonthEnd     = "05"
    $DayEnd       = "30"
    $YearEnd      = "2017"

    $symbol       = "NVDA"


    ### GOOGLE FINANCE  format.   For Yahoo see GetQuotesHistory-Yahoo.ring
    ### $url = https://www.google.com/finance/historical?output=csv&startdate=01-Jan-2015&q=NVDA


    $urlbase     = "https://www.google.com/finance/historical?output=csv&startdate="
    $urlbaseType = $DayStart +"-"+  $MonthStart +"-"+ $YearStart
    $url         = $urlbase + $urlbaseType +"&q="+ $symbol

    See "Sym: " + $symbol +" , URL: " + $url + nl
    see  $symbol + " , Date,Open,High,Low,Close,Volume,Adj Close" + nl + nl

    ###--------------------------------
    ### Download Data and Save to File
    ###--------------------------------

    cStr= download($url)
    see cStr
    write("download.txt",cStr)

###================================================================================================
### OUTPUT
###----------------
#
# Sym: NVDA URL: https://www.google.com/finance/historical?output=csv&startdate=15-01-2016&q=NVDA
# NVDA , Date,Open,High,Low,Close,Volume,Adj Close
#
# ∩╗┐Date,Open,High,Low,Close,Volume               ### <<< NOTE 3 leading char before Date???
# 5-Jun-17,142.98,148.53,142.51,148.01,20434442
# 2-Jun-17,144.24,145.30,143.40,143.64,12186434
# 1-Jun-17,144.99,145.03,142.52,144.36,12583467
# 31-May-17,146.69,147.00,142.05,144.35,22182894
# 30-May-17,143.70,146.29,143.05,144.87,24741298
# 26-May-17,137.93,145.28,137.11,141.84,19478497
# 25-May-17,140.00,140.03,136.44,138.26,15205701
# 24-May-17,140.96,141.07,138.08,138.57,20434495
# 23-May-17,139.70,139.79,135.71,137.03,17031247
# 22-May-17,137.77,139.48,137.33,138.90,20915225
# 19-May-17,137.02,138.22,135.22,136.00,25459271
# 18-May-17,129.50,133.43,127.05,133.07,28900757
# 17-May-17,134.10,134.86,127.55,127.72,31784158
#
###================
