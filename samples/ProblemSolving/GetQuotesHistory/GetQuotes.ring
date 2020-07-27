#!c:\RING\bin\ring.exe -cgi
load "internetlib.ring"
/*
 +--------------------------------------------------------------
 +        Program Name : GetQuotes.ring
 +        Date         : 2016.04.21
 +        Author       : Bert Mariani
 +        Purpose      : Fetch stock quotes from finance.yahoo.com
 +--------------------------------------------------------------
*/

    $shortList   = "CHKP,CVX,CSCO,C,CTXS,CTSH,CL"                              ### List of symbols
    $urlbase     = "http://download.finance.yahoo.com/d/quotes.csv?s="         ### Yahoo API
    $urlbaseType = "&f=shgl1vredj1n&e=.csv"                                    ### Field letters to fetch

    $url         = $urlbase + $shortList + $urlbaseType ;                      ### Join as URL to fetch              

    see  $url + nl + nl
    see  "$symbol,$high,$low,$last,$vol,$pe,$eps,$div,$cap,$name" + nl + nl

cStr= download($url)
see cStr
write("download.txt",cStr)

###----------------
### OUTPUT
###----------------
#
# http://download.finance.yahoo.com/d/quotes.csv?s=CHKP,CVX,CSCO,C,CTXS,CTSH,CL&f=shgl1vredj1n&e=.csv
# 
# $symbol,$high,$low,$last,$vol,$pe,$eps,$div,$cap,$name
# 
# "CHKP",86.79,84.29,85.33,641996,22.82,3.74,N/A,15.01B,"Check Point Software Technologi"
# "CVX",102.28,101.11,102.11,1621019,41.68,2.45,4.28,192.29B,"Chevron Corporation Common Stoc"
# "CSCO",28.5100,28.2400,28.4172,3750133,14.0679,2.0200,1.0400,143.00B,"Cisco Systems, Inc."
# "C",46.950,46.410,46.785,6866877,8.661,5.402,0.200,138.17B,"Citigroup, Inc. Common Stock"
# "CTXS",90.00,85.90,86.48,2175580,43.46,1.99,N/A,13.32B,"Citrix Systems, Inc."
# "CTSH",60.360,59.710,60.135,341562,22.692,2.650,N/A,36.63B,"Cognizant Technology Solutions "
# "CL",70.32,69.00,69.05,1064385,45.43,1.52,1.56,61.64B,"Colgate-Palmolive Company Commo"
#
###----------------
