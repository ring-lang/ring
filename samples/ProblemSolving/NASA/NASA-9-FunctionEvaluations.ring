# Project: Function Evaluations
# Date   : 2018/07/06
# Author: Gal Zsolt [~ CalmoSoft ~]
# Email  : <calmosoft@gmail.com>

nr = [80000,90000,100000]
for n = 1 to len(nr)
     x = 90
     starttime = clock()
     for z = 1 to nr[n]
          y = sin(x)
          x = asin(y)
          y = cos(x)
          x = acos(y)
          y = tan(x)
          x = atan(y)
     next
     endtime = clock()
     difftime = endtime - starttime
     see "" + (z-1) + "> " + x + " Time-msec: "+ difftime + nl
next
