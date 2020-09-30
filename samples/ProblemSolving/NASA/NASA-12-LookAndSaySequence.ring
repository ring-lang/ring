# Project: Look and Say Sequence
# Date   : 2018/07/06
# Author: Gal Zsolt [~ CalmoSoft ~]
# Email  : <calmosoft@gmail.com>

nr = [40,45,48]
for x = 1 to len(nr)
     number = "1223334444"
     starttime   = clock()
     for n = 1 to nr[x]
          number = looksay(number)
     next
     endtime   = clock()
     difftime  = endtime - starttime
     see "Look and Say " + (n - 1) + " Time-msec: "+ difftime + nl
next

func looksay(n)
       j = 0
       c=""
       o=""
       for i = 1 to len(n)
               c = substr(n,i,1)
               j = i + 1
               while substr(n,j,1) = c
                        j = j + 1
               end
               o = o + string(j-i) + c
               i = j
       next
       return o 
 
